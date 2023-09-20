/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_checks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 22:25:00 by avedrenn          #+#    #+#             */
/*   Updated: 2023/09/20 14:18:12 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project.h"

int	is_in_range(double val, double min, double max)
{
	if (min < INT_MIN)
		return (0);
	if (max >= INT_MAX)
		return (0);
	if (val >= min && val <= max)
		return (1);
	return (0);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '-')
		i ++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '.')
			return (0);
		i ++;
	}
	return (1);
}

int	set_diam_height_rad(char *s1, char *s2, t_obj *elem)
{
	float	diam_hght[2];

	diam_hght[0] = ft_atof(s1);
	if (!is_number(s1) || diam_hght[0] <= 0)
		return (ft_putstr_fdi("Wrong diameter value for cylinder", 2));
	elem->diameter = diam_hght[0];
	elem->radius = diam_hght[0] / 2;
	diam_hght[1] = ft_atof(s2);
	if (!is_number(s2) || diam_hght[1] <= 0)
		return (ft_putstr_fdi("Wrong heigth value for cylinder", 2));
	elem->height = diam_hght[1];
	return (0);
}
