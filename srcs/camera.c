/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:27:42 by avedrenn          #+#    #+#             */
/*   Updated: 2023/09/21 18:10:26 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

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

void	fill_orientation(double *o, t_tuple lft, t_tuple true_up, t_tuple fwd)
{
	o[0] = lft.x;
	o[1] = lft.y;
	o[2] = lft.z;
	o[3] = 0;
	o[4] = true_up.x;
	o[5] = true_up.y;
	o[6] = true_up.z;
	o[7] = 0;
	o[8] = -fwd.x;
	o[9] = -fwd.y;
	o[10] = -fwd.z;
	o[11] = 0;
	o[12] = 0;
	o[13] = 0;
	o[14] = 0;
	o[15] = 1;
}

t_matrix_4	view_transform(t_tuple from, t_tuple to, t_tuple up)
{
	t_tuple		forward;
	t_tuple		left;
	t_tuple		true_up;
	t_matrix_4	orientation;
	double		o[16];

	forward = normalize(sub_tuples(to, from));
	left = cross_product(forward, normalize(up));
	true_up = cross_product(left, forward);
	fill_orientation(o, left, true_up, forward);
	orientation = create_matrix_4(o);
	return (matrix_mult_4(orientation,
			translation(-from.x, -from.y, -from.z)));
}
