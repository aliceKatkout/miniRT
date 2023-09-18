/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:17:05 by mrabourd          #+#    #+#             */
/*   Updated: 2023/09/18 18:00:51 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../project.h"

// int	create_amb(char *line, t_data *data)
// {
//     char    **info;
// 	char	**param;

// 	info = get_params_from_line(line, 3);
// 	if (!info)
// 		return (1);
// 	data->env.amb.lighting = ft_atof(info[1]);
//     param = check_rgb(info[2]);
//     if (!param)
//     {
//         ft_free_arr((void **)info);
// 		return (1);
//     }
// 	data->env.amb.r = ft_atoi(param[0]);
// 	data->env.amb.g = ft_atoi(param[1]);
// 	data->env.amb.b = ft_atoi(param[2]);
// 	ft_free_arr((void **) param);
// 	ft_free_arr((void **) info);
// 	// print_amb(&data->env.amb);
// 	return (0);
// }

t_tuple		conv_color(char **param)
{
	t_tuple		color;

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
	ft_free_arr((void **) info);
	// print_light(&data->env.light);
	return (0);
}