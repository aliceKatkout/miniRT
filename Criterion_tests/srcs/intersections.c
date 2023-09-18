/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:44:10 by avedrenn          #+#    #+#             */
/*   Updated: 2023/09/18 17:45:48 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project.h"

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

t_xs	intersect_cylinder(t_obj *obj, t_ray r)
{
	t_xs	xs;
	double	a;
	double	b;
	double	c;
	double	discriminant;

	ft_bzero(&xs, sizeof(xs));
	a = r.direction.x * r.direction.x + r.direction.z * r.direction.z;
	b = 2 * r.direction.x * r.origin.x + 2 * r.direction.z * r.origin.z;
	c = r.origin.x * r.origin.x + r.origin.z * r.origin.z - 1;
	discriminant = b * b - 4 * a * c;
	if ((fabs(a) < EPSILON || discriminant < 0 ) && !obj->closed)
		return (xs);
	xs.xs[0] = (-b - sqrt(discriminant)) / (2 * a);
	xs.xs[1] = (-b + sqrt(discriminant)) / (2 * a);
	find_xs_cylinder(&xs, obj, r);
	if (obj->closed)
	{
		intersect_caps(obj, r, &xs);
		find_hit_cylinder(&xs);
	}
	else
		find_hit(&xs);
	xs.obj = obj;
	return (xs);
}

void	find_hit_cylinder(t_xs *xs)
{
	int	i;

	i = 0;
	ft_sort_double_tab(xs->xs, 4);
	while (xs->xs[i] < 0 && i < 3)
		i++;
	xs->t = xs->xs[i];
	if (xs->t < 0)
		xs->count = 0;
}

double check_cap(t_ray ray, double t)
{
	double	x;
	double	z;

	x = ray.origin.x + t * ray.direction.x;
	z = ray.origin.z + t * ray.direction.z;
	if (x * x + z * z <= 1)
	{
		if (t < 0)
			return (0);
		else
			return (t);
	}
	else
		return (0);
}

void	intersect_caps(t_obj *obj, t_ray r, t_xs *xs)
{
	double	t;

	if (!obj->closed || fabs(r.direction.y) < EPSILON)
		return ;
	t = (obj->min - r.origin.y) / r.direction.y;
	if (check_cap(r, t))
	{
		xs->xs[2] = t;
		xs->count++;
	}
	t = (obj->max - r.origin.y) / r.direction.y;
	if (check_cap(r, t))
	{
		xs->xs[3] = t;
		xs->count++;
	}
}

void	find_xs_cylinder(t_xs *xs, t_obj *obj, t_ray r)
{
	double	a;
	double	y0;
	double	y1;

	xs->count = 0;
	xs->xs[2] = -1;
	xs->xs[3] = -1;
	if (xs->xs[0] > xs->xs[1])
	{
		a = xs->xs[0];
		xs->xs[0] = xs->xs[1];
		xs->xs[1] = a;
	}
	y0 = r.origin.y + xs->xs[0] * r.direction.y;
	if (obj->min < y0 && y0 < obj->max)
		xs->count++;
	else
		xs->xs[0] = -1;
	y1 = r.origin.y + xs->xs[1] * r.direction.y;
	if (obj->min < y1 && y1 < obj->max)
		xs->count++;
	else
		xs->xs[1] = -1;
}