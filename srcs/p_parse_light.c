/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:17:05 by mrabourd          #+#    #+#             */
/*   Updated: 2023/09/21 16:03:10 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	create_amb(char *line, t_data *data)
{
	char	**info;
	char	**param;
	t_tuple	color;

	info = get_params_from_line(line, 3);
	if (!info)
		return (1);
	data->world.light.amb.lighting = ft_atof(info[1]);
	//check si lighting < 0 ou > 1;
	param = check_rgb(info[2]);
	if (!param)
	{
		ft_free_arr((void **)info);
		return (1);
	}
	color.x = ft_atoi(param[0]);
	color.y = ft_atoi(param[1]);
	color.z = ft_atoi(param[2]);
	data->world.light.amb.color = color;
	ft_free_arr((void **) param);
	ft_free_arr((void **) info);
	data->world.light.amb.color = color_to_unit(data->world.light.amb.color);
	data->world.light.amb.color = mult_tuples(data->world.light.amb.color,
			data->world.light.amb.lighting);
	printf("data->world.light.amb.color.x: %f\n", data->world.light.amb.color.x);
	printf("data->world.light.amb.color.y: %f\n", data->world.light.amb.color.y);
	printf("data->world.light.amb.color.z: %f\n", data->world.light.amb.color.z);
	return (0);
}

t_tuple	conv_color(char **param)
{
	t_tuple	color;

	color.x = ft_atof(param[0]);
	color.y = ft_atof(param[1]);
	color.z = ft_atof(param[2]);
	color.w = 0;
	ft_free_arr((void **) param);
	return (color);
}

int	create_light(char *line, t_data *data)
{
	char	**info;
	char	**param;
	int		nb_info;

	info = ft_split(line, 32);
	if (!info)
		return (1);
	nb_info = ft_arrlen((void **) info);
	if (nb_info < 3 || nb_info > 4)
	{
		ft_free_arr((void **) info);
		return (1);
	}
	param = get_new_params(info[1], 3, ',');
	if (!param)
		return (1);
	data->world.light.position = conv_vec(param);
	// data->world.light.brightness = ft_atof(info[2]);
	if (nb_info == 4)
	{
		param = get_new_params(info[3], 3, ',');
		if (!param)
			return (1);
		data->world.light.intensity = conv_color(param);
	}
	data->world.light.intensity = color_to_unit(data->world.light.intensity);
	data->world.light.intensity = mult_tuples(data->world.light.intensity, ft_atof(info[2]));
	printf("data->world.light.intensity.x: %f\n", data->world.light.intensity.x);
	printf("data->world.light.intensity.y: %f\n", data->world.light.intensity.y);
	printf("data->world.light.intensity.z: %f\n", data->world.light.intensity.z);
	printf("data->world.light.position.x: %f\n", data->world.light.position.x);
	printf("data->world.light.position.y: %f\n", data->world.light.position.y);
	printf("data->world.light.position.z: %f\n", data->world.light.position.z);
	ft_free_arr((void **) info);
	return (0);
}
