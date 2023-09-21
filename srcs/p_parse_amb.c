/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse_amb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:02:23 by mrabourd          #+#    #+#             */
/*   Updated: 2023/09/21 18:05:45 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	create_amb(char *line, t_data *data)
{
	char	**info;
	char	**param;

	info = get_params_from_line(line, 3);
	if (!info)
		return (1);
	data->world.light.amb.lighting = ft_atof(info[1]);
	if (!is_in_range(data->world.light.amb.lighting, 0.0, 1.0))
	{
		ft_free_arr((void **)info);
		return (1);
	}
	param = check_rgb(info[2]);
	if (!param)
	{
		ft_free_arr((void **)info);
		return (1);
	}
	data->world.light.amb.color = conv_color(param);
	ft_free_arr((void **) info);
	data->world.light.amb.color = color_to_unit(data->world.light.amb.color);
	data->world.light.amb.color = mult_tuples(data->world.light.amb.color,
			data->world.light.amb.lighting);
	return (0);
}
