/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:25:21 by mrabourd          #+#    #+#             */
/*   Updated: 2023/09/21 18:35:32 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_tuple	color_at(t_world w, t_ray r)
{
	t_xs_world	xs;
	t_xs		h;
	t_comp		comp;
	t_tuple		res;

	xs = intersect_world(w, r);
	if (xs.count == 0)
		return (create_color(0, 0, 0));
	h = xs.tab_xs[0];
	if (h.count == 0)
		return (create_color(0, 0, 0));
	comp = prepare_comp(h, r);
	res = shade_hit(w, comp);
	return (res);
}

t_tuple	create_color(double red, double green, double blue)
{
	t_tuple	color;

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

double	convert_rgb(double color)
{
	double	res;

	res = color * 255;
	if (color * 255 - res >= 0.5)
		res += 1;
	if (res > 255)
		res = 255;
	if (res < 0)
		res = 0;
	return (res);
}

int	transform_color(t_tuple color)
{
	t_tuple	res;

	res.x = convert_rgb(color.x);
	res.y = convert_rgb(color.y);
	res.z = convert_rgb(color.z);
	return ((int)res.x << 16
		| (int)res.y << 8
		| (int)res.z);
}
