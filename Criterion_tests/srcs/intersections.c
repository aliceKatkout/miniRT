/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:44:10 by avedrenn          #+#    #+#             */
/*   Updated: 2023/09/18 16:44:51 by avedrenn         ###   ########.fr       */
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
	double	c;
	double	discriminant;

	obj_to_ray = sub_tuples(r.origin, create_point(s->x, s->y, s->z));
	xs.obj = s;
	a = dot_product(r.direction, r.direction);
	b = 2 * dot_product(r.direction, obj_to_ray);
	c = dot_product(obj_to_ray, obj_to_ray) - 1;
	discriminant = b * b - 4 * a * c;
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


	a = r.direction.x * r.direction.x + r.direction.z * r.direction.z;
	if (fabs(a) < EPSILON && !obj->closed)
	{
		ft_bzero(&xs, sizeof(xs));
		return (xs);
	}

	b = 2 * r.direction.x * r.origin.x + 2 * r.direction.z * r.origin.z;
	c = r.origin.x * r.origin.x + r.origin.z * r.origin.z - 1;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0 && !obj->closed)
	{
		ft_bzero(&xs, sizeof(xs));
		return (xs);
	}
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
	while(xs->xs[i] < 0 && i < 3)
		i++;
	xs->t = xs->xs[i];
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
	t =(obj->min - r.origin.y) / r.direction.y;
	if (check_cap(r, t))
	{
		xs->xs[2] = t;
		xs->count++;
	}
	t =(obj->max - r.origin.y) / r.direction.y;
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

t_comp	prepare_comp(t_xs xs, t_ray r)
{
	t_comp	comp;

	comp.t = xs.t;
	comp.obj = xs.obj;
	comp.point = position(r, comp.t);
	comp.eyev = neg_tuples(r.direction);
	comp.normalv = normal_at(comp.obj, comp.point);
	if (dot_product(comp.normalv, comp.eyev) < 0)
	{
		comp.inside = 1;
		comp.normalv = neg_tuples(comp.normalv);
	}
	else
		comp.inside = 0;
	comp.over_point = mult_tuples(comp.normalv, EPSILON);
	comp.over_point = add_tuples(comp.point, comp.over_point);
	return (comp);
}

t_tuple	color_at(t_world w, t_ray r)
{
	t_xs_world	xs;
	t_xs		h;
	t_comp		comp;
	t_tuple		res;

	xs = intersect_world(w, r);
	h = xs.tab_xs[0];
	printf("h.t : %f\n", h.t);
	if (h.count == 0)
	{
		printf("h.count == 0\n");
		return (create_color(0, 0, 0));
	}
	comp = prepare_comp(h, r);
	res = shade_hit(w, comp);
	return (res);
}

t_matrix_4	view_transform(t_tuple from, t_tuple to, t_tuple up)
{
	t_tuple	forward;
	t_tuple	left;
	t_tuple	true_up;
	t_matrix_4	orientation;
	t_matrix_4	translation;

	forward = normalize(sub_tuples(to, from));
	left = cross_product(forward, normalize(up));
	true_up = cross_product(left, forward);
	double	o[16] = {left.x, left.y, left.z, 0,
			true_up.x, true_up.y, true_up.z, 0,
			-forward.x, -forward.y, -forward.z, 0,
			0, 0, 0, 1};
	double	t[16] = {1, 0, 0, -from.x,
			0, 1, 0, -from.y,
			0, 0, 1, -from.z,
			0, 0, 0, 1};
	orientation = create_matrix_4(o);
	translation = create_matrix_4(t);
	return (matrix_mult_4(orientation, translation));
}