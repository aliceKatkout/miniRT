/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse_cam.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:31:40 by mrabourd          #+#    #+#             */
/*   Updated: 2023/09/21 19:02:28 by mrabourd         ###   ########.fr       */
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
	data->cam.fov = ft_atof(*info);
	if (!is_in_range(data->cam.fov, 0, 180))
	{
		ft_putstr_fd("Error, fov not in range 0-180 ❌ \n", 2);
		return (1);
	}
	data->cam.fov *= PI / 180;
	return (0);
}

int	init_cam(t_data *data, char **info)
{
	char	**vec;
	char	**param;

	if (init_fov(data, &info[3]))
		return (1);
	param = get_new_params(info[1], 3, ',');
	if (!param)
		return (1);
	data->cam = create_camera(WINDOW_WIDTH, WINDOW_HEIGHT, data->cam.fov);
	data->cam.position = conv_vec(param);
	vec = check_vectors(info[2]);
	if (!vec)
	{
		ft_putstr_fd("Error ❌ \n", 2);
		ft_free_arr((void **)info);
		return (1);
	}
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
