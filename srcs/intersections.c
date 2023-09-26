/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:44:10 by avedrenn          #+#    #+#             */
/*   Updated: 2023/09/26 16:06:56 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_xs	intersect(t_obj *obj, t_ray ray)
{
	t_xs	xs;

	obj->saved_ray = transform_ray(ray, mat_inversion_4(obj->transform));
	if (obj->shape == PLANE)
		xs = intersect_plane(obj, obj->saved_ray);
	else if (obj->shape == SPHERE)
		xs = intersect_sphere(obj, obj->saved_ray);
	else if (obj->shape == CYLINDER)
		xs = intersect_cylinder(obj, obj->saved_ray);
	else
	{
		ft_bzero(&xs, sizeof(xs));
		return (xs);
	}
	return (xs);
}

t_xs	intersect_plane(t_obj *obj, t_ray r)
{
	t_xs	xs;

	if (fabs(r.direction.y) < EPSILON)
	{
		xs.count = 0;
		return (xs);
	}
	xs.count = 1;
	xs.t = -r.origin.y / r.direction.y;
	if (xs.t < 0)
	{
		xs.count = 0;
		return (xs);
	}
	xs.obj = obj;
	return (xs);
}

void	find_hit(t_xs *xs)
{
	xs->t = 0;
	if (xs->xs[0] < 0 && xs->xs[1] < 0)
		xs->count = 0;
	else if (xs->xs[0] < 0 || xs->xs[1] < 0)
	{
		xs->count = 1;
		if (xs->xs[0] >= 0)
			xs->t = xs->xs[0];
		else if (xs->xs[1] >= 0)
			xs->t = xs->xs[1];
	}
	else if (xs->xs[0] >= 0 && xs->xs[1] >= 0)
	{
		xs->count = 2;
		if (xs->xs[0] <= xs->xs[1])
			xs->t = xs->xs[0];
		else if (xs->xs[1] < xs->xs[0] && xs->xs[1] >= 0)
			xs->t = xs->xs[1];
	}
	else
		xs->count = 0;
}

t_xs	intersect_sphere(t_obj *s, t_ray r)
{
	t_xs	xs;
	t_tuple	obj_to_ray;
	double	a;
	double	b;
	double	discriminant;

	xs.t = 0;
	obj_to_ray = sub_tuples(r.origin, create_point(s->x, s->y, s->z));
	xs.obj = s;
	a = dot_product(r.direction, r.direction);
	b = 2 * dot_product(r.direction, obj_to_ray);
	discriminant = b * b - 4 * a * (dot_product(obj_to_ray, obj_to_ray) - 1);
	if (discriminant < 0)
	{
		ft_bzero(&xs, sizeof(xs));
		return (xs);
	}
	xs.xs[0] = (-b - sqrt(discriminant)) / (2 * a);
	xs.xs[1] = (-b + sqrt(discriminant)) / (2 * a);
	find_hit(&xs);
	return (xs);
}
