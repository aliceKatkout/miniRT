/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections_cy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:42:22 by mrabourd          #+#    #+#             */
/*   Updated: 2023/09/21 16:03:10 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

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
	if ((fabs(a) < EPSILON || discriminant < 0) && !obj->closed)
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

double	check_cap(t_ray ray, double t)
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
