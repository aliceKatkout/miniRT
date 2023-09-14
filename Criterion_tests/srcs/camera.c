/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:27:42 by avedrenn          #+#    #+#             */
/*   Updated: 2023/09/14 16:39:58 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project.h"

t_cam	create_camera(double hsize, double vsize, double fov)
{
	t_cam	c;
	double	half_view;
	double	aspect;

	c.hsize = hsize;
	c.vsize = vsize;
	c.fov = fov;
	c.transform = identity_matrix();
	half_view = tan(c.fov / 2);
	aspect = c.hsize / c.vsize;
	if (aspect >= 1)
	{
		c.half_width = half_view;
		c.half_height = half_view / aspect;
	}
	else
	{
		c.half_width = half_view * aspect;
		c.half_height = half_view;
	}
	c.pixel_size = (c.half_width * 2) / c.hsize;
	return (c);
}

t_ray	ray_for_pixel(t_cam c, int px, int py)
{
	double	xoffset;
	double	yoffset;
	double	world_x;
	double	world_y;
	t_tuple pixel;
	t_ray	r;

	xoffset = (px + 0.5) * c.pixel_size;
	yoffset = (py + 0.5) * c.pixel_size;
	world_x = c.half_width - xoffset;
	world_y = c.half_height - yoffset;
	pixel = matrix_mult_tuple(mat_inversion_4(c.transform),
		create_point(world_x, world_y, -1));
	r.origin = matrix_mult_tuple(mat_inversion_4(c.transform),
		create_point(0, 0, 0));
	r.direction = normalize(sub_tuples(pixel, r.origin));
	return (r);
}
/*
t_image	render_cam(t_cam c, t_world w)
{
	int		x;
	int		y;
	t_ray	r;
	t_tuple	color;
	t_image	img;

	y = 0;
	img = canvas(c.hsize, c.vsize);
	while (y < c.vsize - 1)
	{
		x = 0;
		while (x < c.hsize - 1)
		{
			r = ray_for_pixel(c, x, y);
			color = color_at(w, r);
			// write_pixel(image, x, y, color);
			x++;
		}
		y++;
	}
	return (img);
}
*/