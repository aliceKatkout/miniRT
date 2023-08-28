/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:56:06 by mrabourd          #+#    #+#             */
/*   Updated: 2023/08/28 18:24:13 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"

double	magn_tuple(t_tuple a)
{
	double	add_sqrs;
	double	c;
	
	add_sqrs = (a.x * a.x) + (a.y * a.y) + ( a.z * a.z) + (a.w * a.w);
	c = sqrtf(add_sqrs);
	return (c);
}