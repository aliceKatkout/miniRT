/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse_cam.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:31:40 by mrabourd          #+#    #+#             */
/*   Updated: 2023/09/26 16:51:47 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

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

int	init_fov(t_data *data, char **info)
{
	if (!is_number(*info))
		return (1);
	data->cam.fov = ft_atof(*info);
	if (!is_in_range(data->cam.fov, 0, 180))
		return (1);
	data->cam.fov *= PI / 180;
	return (0);
}

int	fill_xyz(t_tuple *t, char *param)
{
	char		**xyz;

	xyz = ft_split(param, ',');
	if (ft_arrlen((void **)xyz) != 3 || !is_number(xyz[0])
		|| !is_number(xyz[1]) || !is_number(xyz[2]))
		return (ft_free_arr((void **)xyz));
	t->x = ft_atof(xyz[0]);
	t->y = ft_atof(xyz[1]);
	t->z = ft_atof(xyz[2]);
	ft_free_arr((void **)xyz);
	return (0);
}

int	init_cam(t_data *data, char **info)
{
	char	**vec;

	if (init_fov(data, &info[3]))
		return (1);
	data->cam = create_camera(WINDOW_WIDTH, WINDOW_HEIGHT, data->cam.fov);
	data->cam.position = create_point(0, 0, 0);
	if (fill_xyz(&data->cam.position, info[1]))
		return (1);
	vec = check_vectors(info[2]);
	if (!vec)
		return (1);
	data->cam.orientation = conv_cam_orientation(vec);
	data->cam.transform = view_transform(data->cam.position,
			data->cam.orientation, create_vector(0, 1, 0));
	return (0);
}

int	parse_cam(char *line, t_data *data)
{
	char	**info;

	info = get_params_from_line(line, 4);
	if (!info)
		return (1);
	ft_bzero((void *)&data->cam, sizeof(t_cam));
		if (init_cam(data, info))
	{
		ft_free_arr((void **) info);
		return (1);
	}
	ft_free_arr((void **) info);
	return (0);
}
