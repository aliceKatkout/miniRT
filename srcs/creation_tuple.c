/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation_tuple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:09:53 by mrabourd          #+#    #+#             */
/*   Updated: 2023/09/21 16:03:10 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"
/*
**	If tuple is a point, w = 1, else if it's a vector, w = 0.
	Beware of comparing doubleing point values
	using simple equivalency. Round-off error
	can make two numbers that should be equivalent instead be slightly different.
	When you need to test two doubleing point numbers for equivalence, compare their
	difference. If the absolute value
	of their difference is less than some value (called
	EPSILON), you can consider them equal.
*/

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

t_tuple	reverse_tuple(t_tuple a)
{
	a.x = -a.x;
	a.y = -a.y;
	a.z = -a.z;
	a.w = -a.w;
	return (a);
}
