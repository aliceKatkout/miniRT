/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:27:42 by avedrenn          #+#    #+#             */
/*   Updated: 2023/09/18 18:12:54 by mrabourd         ###   ########.fr       */
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

t_tuple	conv_vec(char **param)
{
	t_tuple		pos;

	pos.x = ft_atof(param[0]);
	pos.y = ft_atof(param[1]);
	pos.z = ft_atof(param[2]);
	pos.w = 1;
	ft_free_arr((void **) param);
	return (pos);
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

t_tuple		conv_cam_orientation(char **vec)
{
	t_tuple		to;

	to.x = ft_atof(vec[0]);
	to.y = ft_atof(vec[1]);
	to.z = ft_atof(vec[2]);
	if (to.z == 0)
		to.z = EPSILON;
	to.w = 0;
	ft_free_arr((void **) vec);
	return (to);
}

int		init_cam(t_data *data, char **info)
{
	char	**vec;
    char	**param;
	t_tuple	from;
	t_tuple	to;

	param = get_new_params(info[1], 3, ',');
	if (!param)
		return (1);
	from = conv_vec(param);
	vec = check_vectors(info[2]);
    if (!vec)
    {
        ft_free_arr((void **)info);
        return (1);
    }
	to = conv_cam_orientation(vec);
	data->cam = create_camera(WINDOW_HEIGHT, WINDOW_WIDTH, ft_atoi(info[3]));
	data->cam.transform = view_transform(from, to, create_vector(0, 1, 0));
	// print_cam(&data->env.cam);
	return (0);
}

int		parse_cam(char *line, t_data *data)
{
    char    **info;

	info = get_params_from_line(line, 4);
	if (!info)
		return (1);
	ft_bzero((void *)&data->cam, sizeof(t_cam));
	if (init_cam(data, info))
		return (1);
	ft_free_arr((void **) info);
	return (0);
}