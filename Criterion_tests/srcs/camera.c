/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:27:42 by avedrenn          #+#    #+#             */
/*   Updated: 2023/09/18 16:34:20 by mrabourd         ###   ########.fr       */
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