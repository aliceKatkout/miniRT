/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:44:10 by avedrenn          #+#    #+#             */
/*   Updated: 2023/09/16 16:10:46 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project.h"

t_xs	intersect(t_obj *obj, t_ray ray)
{
	t_xs	xs;

	obj->saved_ray = transform_ray(ray, mat_inversion_4(obj->transform));
	if (obj->shape == PLANE)
		xs = intersect_plane(obj, ray);
	else
		xs = intersect_sphere(obj, obj->saved_ray);
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
	if (xs->x0 < 0 && xs->x1 < 0)
		xs->count = 0;
	else if (xs->x0 < 0 || xs->x1 < 0)
	{
		xs->count = 1;
		if (xs->x0 >= 0)
			xs->t = xs->x0;
		else if (xs->x1 >= 0)
			xs->t = xs->x1;
	}
	else if (xs->x0 >= 0 && xs->x1 >= 0)
	{
		xs->count = 2;
		if (xs->x0 <= xs->x1)
			xs->t = xs->x0;
		else if (xs->x1 < xs->x0 && xs->x1 >= 0)
			xs->t = xs->x1;
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
	xs.x0 = (-b - sqrt(discriminant)) / (2 * a);
	xs.x1 = (-b + sqrt(discriminant)) / (2 * a);
	find_hit(&xs);
	return (xs);
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
	if (h.count == 0)
		return (create_color(0, 0, 0));
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