/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:54:44 by mrabourd          #+#    #+#             */
/*   Updated: 2023/09/18 17:44:12 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project.h"

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

t_tuple	shade_hit(t_world w, t_comp	comp)
{
	t_tuple		res;
	int			shadowed;

	shadowed = is_shadowed(w, comp.over_point);
	res = lighting(comp.obj->material, comp, w.light, shadowed);
	return (res);
}

int	is_shadowed(t_world world, t_tuple point)
{
	t_tuple		v;
	double		distance;
	t_tuple		direction;
	t_ray		r;
	t_xs_world	intersections;
	t_xs		h;

	v = sub_tuples(world.light.position, point);
	distance = magn_tuple(v);
	direction = normalize(v);
	r = create_ray(point, direction);
	intersections = intersect_world(world, r);
	h = intersections.tab_xs[0];
	if (intersections.count > 0 && h.t < distance)
		return (1);
	else
		return (0);
}