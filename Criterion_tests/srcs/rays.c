/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:59:11 by avedrenn          #+#    #+#             */
/*   Updated: 2023/09/05 15:42:09 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project.h"

t_ray	create_ray(t_tuple origin, t_tuple direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;
	return (ray);
}

t_tuple	position(t_ray ray, double t)
{
	t_tuple	pos;

	pos.x = ray.origin.x + (ray.direction.x * t);
	pos.y = ray.origin.y + (ray.direction.y * t);
	pos.z = ray.origin.z + (ray.direction.z * t);
	pos.w = 1;
	return (pos);
}

//A modifier pour rnvoyer une liste de xs/ ou de t_intersection
t_xs	intersect(t_sphere s, t_ray r)
{
	t_xs	xs;
	t_tuple	sphere_to_ray;
	double	a;
	double	b;
	double	c;
	double	discriminant;

	sphere_to_ray = sub_tuples(r.origin, create_point(s.x, s.y, s.z));
	if (matrix_cmp_4(s.transform, identity_matrix()))
	{
		r = transform_ray(r, s.transform);
		sphere_to_ray = sub_tuples(r.origin, create_point(s.x, s.y, s.z));
	}
	a = dot_product(r.direction, r.direction);
	b = 2 * dot_product(r.direction, sphere_to_ray);
	c = dot_product(sphere_to_ray, sphere_to_ray) - 1;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
	{
		xs.count = 0;
		return (xs);
	}
	xs.x0 = (-b - sqrtf(discriminant)) / (2 * a);
	xs.x1 = (-b + sqrtf(discriminant)) / (2 * a);
	xs.count = 2;
	xs.obj = &s;
	return (xs);
}

t_intersection	create_intersection(double t, t_sphere *s)
{
	t_intersection	i;

	i.t = t;
	i.s = s;
	return (i);
}

t_ray	transform_ray(t_ray r, t_matrix_4 m)
{
	t_ray	new;

	new.direction = matrix_mult_tuple(m, r.direction);
	new.origin = matrix_mult_tuple(m, r.origin);
	return (new);
}