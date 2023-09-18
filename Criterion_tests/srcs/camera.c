/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:27:42 by avedrenn          #+#    #+#             */
/*   Updated: 2023/09/18 17:47:31 by avedrenn         ###   ########.fr       */
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
	double	offset;
	double	world_x;
	double	world_y;
	t_tuple	pixel;
	t_ray	r;

	offset = (px + 0.5) * c.pixel_size;
	world_x = c.half_width - offset;
	offset = (py + 0.5) * c.pixel_size;
	world_y = c.half_height - offset;
	pixel = matrix_mult_tuple(mat_inversion_4(c.transform),
			create_point(world_x, world_y, -1));
	r.origin = matrix_mult_tuple(mat_inversion_4(c.transform),
			create_point(0, 0, 0));
	r.direction = normalize(sub_tuples(pixel, r.origin));
	return (r);
}

t_matrix_4	view_transform(t_tuple from, t_tuple to, t_tuple up)
{
	t_tuple	forward;
	t_tuple	left;
	t_tuple	true_up;
	t_matrix_4	orientation;
	t_matrix_4	translation;

	forward = normalize(sub_tuples(to, from));
	left = cross_product(forward, normalize(up));
	true_up = cross_product(left, forward);
	double	o[16] = {left.x, left.y, left.z, 0,
			true_up.x, true_up.y, true_up.z, 0,
			-forward.x, -forward.y, -forward.z, 0,
			0, 0, 0, 1};
	double	t[16] = {1, 0, 0, -from.x,
			0, 1, 0, -from.y,
			0, 0, 1, -from.z,
			0, 0, 0, 1};
	orientation = create_matrix_4(o);
	translation = create_matrix_4(t);
	return (matrix_mult_4(orientation, translation));
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