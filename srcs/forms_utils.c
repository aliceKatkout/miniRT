/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forms_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:06:37 by avedrenn          #+#    #+#             */
/*   Updated: 2023/08/10 16:52:23 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../miniRT.h"

char **get_params_from_line(char *line, int wanted_nb)
{
	char 	**params;
	int 	params_nb;

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
	if (!rgb)
		return (NULL);
	if (ft_arrlen((void **)rgb) != 3 || !is_number(rgb[0]) || !is_number(rgb[1]) || !is_number(rgb[2]))
	{
		ft_free_arr((void **)rgb);
		//return (ft_putstr_fdi("Error\n RGB must be numbers.\n", 2)); //ou 1
		return (NULL);
	}
	r = ft_atof(rgb[0]);
	g = ft_atof(rgb[1]);
	b = ft_atof(rgb[2]);
	if (!is_in_range(r, 0.0, 255.0) || !is_in_range(b, 0.0, 255.0) || !is_in_range(g, 0.0, 255.0))
	{
		ft_free_arr((void **)rgb);
		//return (ft_putstr_fdi("Error\n RGB must be numbers in range 0 to 255.\n", 2)); // ou 1
		return (NULL);
	}
	return (rgb);
}