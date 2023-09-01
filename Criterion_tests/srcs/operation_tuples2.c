/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_tuples2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:56:06 by mrabourd          #+#    #+#             */
/*   Updated: 2023/09/01 16:35:05 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project.h"

double	magn_tuple(t_tuple a)
{
	double	add_sqrs;
	double	c;

	add_sqrs = (a.x * a.x) + (a.y * a.y)
		+ (a.z * a.z) + (a.w * a.w);
	c = sqrtf(add_sqrs);
	return (c);
}

t_tuple	normalize(t_tuple vec)
{
	t_tuple	normlzd;
	double	magn;

	magn = magn_tuple(vec);
	normlzd.x = vec.x / magn;
	normlzd.y = vec.y / magn;
	normlzd.z = vec.z / magn;
	normlzd.w = 0;
	return (normlzd);
}

double	dot_product(t_tuple a, t_tuple b)
{
	double	ret;

	ret = (a.x * b.x) + (a.y * b.y)
		+ (a.z * b.z) + (a.w * b.w);
	return (ret);
}

t_tuple	cross_product(t_tuple a, t_tuple b)
{
	t_tuple	vec;

	vec.x = (a.y * b.z) - (a.z * b.y);
	vec.y = (a.z * b.x) - (a.x * b.z);
	vec.z = (a.x * b.y) - (a.y * b.x);
	vec.w = 0;
	return (vec);
}
