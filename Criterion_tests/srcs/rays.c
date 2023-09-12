/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:59:11 by avedrenn          #+#    #+#             */
/*   Updated: 2023/09/12 18:53:29 by mrabourd         ###   ########.fr       */
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

// void print_matrix_4(t_matrix_4 a)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	while (x < 4)
// 	{
// 		y = 0;
// 		while (y < 4)
// 		{
// 			printf("a.tab[%d][%d]: %f\n", x, y, a.tab[x][y]);
// 			y++;
// 		}
// 		x++;
// 	}
// }

//A modifier pour rnvoyer une liste de xs/ ou de t_intersection
t_xs	intersect(t_obj *s, t_ray r)
{
	t_xs	xs;
	t_tuple	obj_to_ray;
	double	a;
	double	b;
	double	c;
	double	discriminant;

	r = transform_ray(r, mat_inversion_4(s->transform));
	obj_to_ray = sub_tuples(r.origin, create_point(s->x, s->y, s->z));
	// printf("r.direction.x: %f\n", r.direction.x);
	// printf("r.direction.y: %f\n", r.direction.y);
	// printf("r.direction.z: %f\n", r.direction.z);
	xs.obj = s;
	a = dot_product(r.direction, r.direction);
	b = 2 * dot_product(r.direction, obj_to_ray);
	c = dot_product(obj_to_ray, obj_to_ray) - 1;
	discriminant = b * b - 4 * a * c;
	// printf("discriminant: %f\n", discriminant);
	// printf("a: %f\n", a);
	// printf("b: %f\n", b);
	// printf("c: %f\n", c);
	if (discriminant < 0)
	{
		ft_bzero(&xs, sizeof(xs));
		return (xs);
	}
	xs.x0 = (-b - sqrt(discriminant)) / (2 * a);
	xs.x1 = (-b + sqrt(discriminant)) / (2 * a);
	if (xs.x0 < 0 && xs.x1 < 0)
		xs.count = 0;
	else if (xs.x0 < 0 || xs.x1 < 0)
	{
		xs.count = 1;
		if (xs.x0 >= 0)
			xs.t = xs.x0;
		else if (xs.x1 >= 0)
			xs.t = xs.x1;
	}
	else if (xs.x0 >= 0 && xs.x1 >= 0)
	{
		xs.count = 2;
		if (xs.x0 <= xs.x1)
			xs.t = xs.x0;
		else if (xs.x1 < xs.x0 && xs.x1 >= 0)
			xs.t = xs.x1;
	}
	else
		xs.count = 0;
	return (xs);
}

t_intersection	create_intersection(double t, t_obj *s)
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