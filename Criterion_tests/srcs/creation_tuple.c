/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation_tuple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:09:53 by mrabourd          #+#    #+#             */
/*   Updated: 2023/08/31 20:17:57 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project.h"

t_tuple	create_point(double x, double y, double z)
{
	t_tuple	a;

	a.x = x;
	a.y = y;
	a.z = z;
	a.w = 1.0;
	return (a);
}

t_tuple	create_vector(double x, double y, double z)
{
	t_tuple	b;

	b.x = x;
	b.y = y;
	b.z = z;
	b.w = 0;
	return (b);
}

t_tuple	create_tuple(double x, double y, double z, double w)
{
	t_tuple	b;

	b.x = x;
	b.y = y;
	b.z = z;
	b.w = w;
	return (b);
}

int	tuples_cmp(t_tuple a, t_tuple b)
{
	if (fabs(a.x - b.x) < EPSILON)
	{
		if (fabs(a.y - b.y) < EPSILON)
		{
			if (fabs(a.z - b.z) < EPSILON)
				return (1);
		}
	}
	return (0);
}
