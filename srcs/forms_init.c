/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forms_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:26:44 by avedrenn          #+#    #+#             */
/*   Updated: 2023/09/19 14:10:59 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	init_obj(char **params, t_obj	*sp)
{
	static int	id = 0;
	char		**xyz;
	char		**rgb;

	sp->id = id++;
	sp->diameter = set_diameter(params[2]);
	if (sp->diameter <= 0)
		return (ft_putstr_fdi("obj diameter is incorrect.\n", 2)); // ou 2
	xyz = ft_split(params[1], ',');
	if (ft_arrlen((void **)xyz) != 3 || !is_number(xyz[0])
		|| !is_number(xyz[1]) || !is_number(xyz[2]))
		return (ft_free_arr((void **)xyz));
	sp->x = ft_atof(xyz[0]);
	sp->y = ft_atof(xyz[1]);
	sp->z = ft_atof(xyz[2]);
	rgb = check_rgb(params[3]);
	if (!rgb)
		return (ft_free_arr((void **)xyz));
	sp->r = ft_atof(rgb[0]);
	sp->g = ft_atof(rgb[1]);
	sp->b = ft_atof(rgb[2]);
	ft_free_arr((void **)xyz);
	ft_free_arr((void **)rgb);
	return (0);
}

int	init_cylinder(char **params, t_cylinder	*cy)
{
	static int	id = 0;
	char		**xyz;
	char		**rgb;
	char		**vec;

	cy->id = id++;
	cy->diameter = set_diameter(params[3]);
	cy->height = set_diameter(params[4]);
	if (cy->height <= 0 || cy->diameter <= 0)
		return (ft_putstr_fdi("cylinder diameter is incorrect.\n", 2)); // ou 2
	xyz = ft_split(params[1], ',');
	if (ft_arrlen((void **)xyz) != 3 || !is_number(xyz[0])
		|| !is_number(xyz[1]) || !is_number(xyz[2]))
		return (ft_free_arr((void **)xyz));
	cy->x = ft_atof(xyz[0]);
	cy->y = ft_atof(xyz[1]);
	cy->z = ft_atof(xyz[2]);
	vec = check_vectors(params[2]);
	if (!vec)
		return (ft_free_arr((void **)xyz));
	cy->x_v = ft_atof(vec[0]);
	cy->y_v = ft_atof(vec[1]);
	cy->z_v = ft_atof(vec[2]);
	rgb = check_rgb(params[5]);
	if (!rgb)
	{
		ft_free_arr((void **)vec);
		return (ft_free_arr((void **)xyz));
	}
	cy->r = ft_atof(rgb[0]);
	cy->g = ft_atof(rgb[1]);
	cy->b = ft_atof(rgb[2]);
	ft_free_arr((void **)vec);
	ft_free_arr((void **)xyz);
	ft_free_arr((void **)rgb);
	return (0);
}

int	init_plane(char **params, t_plane	*pl)
{
	static int	id = 0;
	char		**xyz;
	char		**rgb;
	char		**vec;

	pl->id = id++;
	xyz = ft_split(params[1], ',');
	if (ft_arrlen((void **)xyz) != 3 || !is_number(xyz[0])
		|| !is_number(xyz[1]) || !is_number(xyz[2]))
		return (ft_free_arr((void **)xyz));
	pl->x = ft_atof(xyz[0]);
	pl->y = ft_atof(xyz[1]);
	pl->z = ft_atof(xyz[2]);
	vec = check_vectors(params[2]);
	if (!vec)
		return (ft_free_arr((void **)xyz));
	pl->x_v = ft_atof(vec[0]);
	pl->y_v = ft_atof(vec[1]);
	pl->z_v = ft_atof(vec[2]);
	rgb = check_rgb(params[3]);
	if (!rgb)
	{
		ft_free_arr((void **)vec);
		return (ft_free_arr((void **)xyz));
	}
	pl->r = ft_atof(rgb[0]);
	pl->g = ft_atof(rgb[1]);
	pl->b = ft_atof(rgb[2]);
	ft_free_arr((void **)vec);
	ft_free_arr((void **)xyz);
	ft_free_arr((void **)rgb);
	return (0);
}