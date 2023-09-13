/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:54:44 by mrabourd          #+#    #+#             */
/*   Updated: 2023/09/13 12:15:35 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project.h"

t_tuple	shade_hit(t_world w, t_comp	comp)
{
	t_tuple		res;

	res = lighting(comp.obj->material, w.light,
			comp.point, comp.eyev, comp.normalv, is_shadowed(w, comp.point));
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
	if (h.count != 0 && h.t < distance)
		return (1);
	else
		return (0);
}