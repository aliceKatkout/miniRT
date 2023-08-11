/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forms_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:06:37 by avedrenn          #+#    #+#             */
/*   Updated: 2023/08/11 14:30:15 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

double	set_diameter(char	*param)
{
	double	diameter;

	diameter = ft_atof(param);
	if (diameter <= 0 || !is_number(param))
		return (-1);
	else
		return (diameter);
}

char	**get_params_from_line(char *line, int wanted_nb)
{
	char	**params;
	int		params_nb;

	params = ft_split(line, 32);
	if (!params)
		return (NULL);
	params_nb = ft_arrlen((void **) params);
	if (params_nb != wanted_nb)
	{
		ft_free_arr((void **) params);
		return (NULL);
	}
	return (params);
}

char	**check_rgb(char *line)
{
	char	**rgb;
	double	r;
	double	g;
	double	b;

	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = ',';
	rgb = ft_split(line, ',');
	if (ft_arrlen((void **)rgb) != 3 || !is_number(rgb[0]) 
		|| !is_number(rgb[1]) || !is_number(rgb[2]))
	{
		ft_free_arr((void **)rgb);
		return (NULL);
	}
	r = ft_atof(rgb[0]);
	g = ft_atof(rgb[1]);
	b = ft_atof(rgb[2]);
	if (!is_in_range(r, 0.0, 255.0) || !is_in_range(b, 0.0, 255.0) 
		|| !is_in_range(g, 0.0, 255.0))
	{
		ft_free_arr((void **)rgb);
		return (NULL);
	}
	return (rgb);
}

char	**check_vectors(char *line)
{
	char	**vec;
	double	x;
	double	y;
	double	z;

	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = ',';
	vec = ft_split(line, ',');
	if (ft_arrlen((void **)vec) != 3 || !is_number(vec[0]) 
		|| !is_number(vec[1]) || !is_number(vec[2]))
	{
		ft_free_arr((void **)vec);
		return (NULL);
	}
	x = ft_atof(vec[0]);
	y = ft_atof(vec[1]);
	z = ft_atof(vec[2]);
	if (!is_in_range(x, -1.0, 1.0) || !is_in_range(y, -1.0, 1.0) 
		|| !is_in_range(z, -1.0, 1.0))
	{
		ft_free_arr((void **)vec);
		return (NULL);
	}
	return (vec);
}
