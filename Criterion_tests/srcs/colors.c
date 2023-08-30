/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:25:21 by mrabourd          #+#    #+#             */
/*   Updated: 2023/08/30 17:51:00 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project.h"

t_tuple	create_color(double red, double green, double blue)
{
	t_tuple color;

	color.x = red;
	color.y = green;
	color.z = blue;
	color.w = 0;
	return (color);
}

t_tuple	mult_colors(t_tuple a, t_tuple b)
{
	t_tuple	c;

	c.x = a.x * b.x;
	c.y = a.y * b.y;
	c.z = a.z * b.z;
	c.w = 0;
	return (c);
}