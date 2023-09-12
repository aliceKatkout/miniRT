/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:54:44 by mrabourd          #+#    #+#             */
/*   Updated: 2023/09/12 15:21:48 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project.h"

int	is_shadowed(t_world world, t_tuple point)
{
	t_tuple	v;
	double	distance;
	t_tuple	direction;
	t_ray	r;
	t_xs	intersections;

	v = sub_tuples(world.light->position, point);
	distance = magn_tuple(v);
	direction = normalize(v);
	r = create_ray(point, direction);
	intersections = intersect_world(world, r);
	/*
	h ← hit(intersections)
	if (h is present and h.t < distance)
		return (1);
	else
		return (0);
	*/
}