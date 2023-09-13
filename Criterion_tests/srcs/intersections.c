/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:44:10 by avedrenn          #+#    #+#             */
/*   Updated: 2023/09/13 12:00:54 by avedrenn         ###   ########.fr       */
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
