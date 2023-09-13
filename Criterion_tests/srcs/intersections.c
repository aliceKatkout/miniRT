/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:44:10 by avedrenn          #+#    #+#             */
/*   Updated: 2023/09/13 17:19:50 by avedrenn         ###   ########.fr       */
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