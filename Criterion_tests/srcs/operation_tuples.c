/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_tuples.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:09:51 by mrabourd          #+#    #+#             */
/*   Updated: 2023/09/01 15:25:52 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project.h"

t_tuple	add_tuples(t_tuple a, t_tuple b)
{
	t_tuple	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
	c.w = a.w + b.w;
	return (c);
}

t_tuple	sub_tuples(t_tuple a, t_tuple b)
{
	t_tuple	c;

	c.x = a.x - b.x;
	c.y = a.y - b.y;
	c.z = a.z - b.z;
	c.w = a.w - b.w;
	return (c);
}

t_tuple	neg_tuples(t_tuple a)
{
	t_tuple	c;

	c.x = -a.x;
	c.y = -a.y;
	c.z = -a.z;
	c.w = -a.w;
	return (c);
}

t_tuple	mult_tuples(t_tuple a, double vec)
{
	t_tuple	c;

	c.x = a.x * vec;
	c.y = a.y * vec;
	c.z = a.z * vec;
	c.w = a.w * vec;
	return (c);
}

t_tuple	div_tuples(t_tuple a, double vec)
{
	t_tuple	c;

	c.x = a.x / vec;
	c.y = a.y / vec;
	c.z = a.z / vec;
	c.w = a.w / vec;
	return (c);
}
