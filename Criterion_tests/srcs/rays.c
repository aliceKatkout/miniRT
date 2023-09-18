/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:59:11 by avedrenn          #+#    #+#             */
/*   Updated: 2023/09/18 14:37:06 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project.h"

t_ray	create_ray(t_tuple origin, t_tuple direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;
	return (ray);
}

t_tuple	position(t_ray ray, double t)
{
	t_tuple	pos;

	pos.x = ray.origin.x + (ray.direction.x * t);
	pos.y = ray.origin.y + (ray.direction.y * t);
	pos.z = ray.origin.z + (ray.direction.z * t);
	pos.w = 1;
	return (pos);
}

void print_matrix_4(t_matrix_4 a)
{
	int	x;
	int	y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			printf("a.tab[%d][%d]: %f\n", x, y, a.tab[x][y]);
			y++;
		}
		x++;
	}
}



t_intersection	create_intersection(double t, t_obj *s)
{
	t_intersection	i;

	i.t = t;
	i.s = s;
	return (i);
}

t_ray	transform_ray(t_ray r, t_matrix_4 m)
{
	t_ray	new;

	new.direction = matrix_mult_tuple(m, r.direction);
	new.origin = matrix_mult_tuple(m, r.origin);
	return (new);
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