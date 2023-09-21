/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:17:05 by mrabourd          #+#    #+#             */
/*   Updated: 2023/09/21 18:27:11 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

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

int	get_brightness(t_data *data, char **info)
{
	data->world.light.brightness = ft_atof(*info);
	if (!is_in_range(data->world.light.brightness, 0.0, 1.0))
	{
		ft_free_arr((void **) info);
		return (1);
	}
	return (0);
}

int	get_l_position(t_data *data, char **info1, char **info3, int nb_info)
{
	char	**param;

	param = get_new_params(*info1, 3, ',');
	if (!param)
		return (1);
	data->world.light.position = conv_vec(param);
	if (nb_info == 4)
	{
		param = check_rgb(*info3);
		if (!param)
			return (1);
		data->world.light.intensity = conv_color(param);
	}
	return (0);
}

int	create_light(char *line, t_data *data)
{
	char	**info;
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
	if (get_brightness(data, &info[2]))
		return (1);
	if (get_l_position(data, &info[1], &info[3], nb_info))
		return (1);
	data->world.light.intensity = color_to_unit(data->world.light.intensity);
	data->world.light.intensity = mult_tuples(data->world.light.intensity,
			data->world.light.brightness);
	ft_free_arr((void **) info);
	return (0);
}
