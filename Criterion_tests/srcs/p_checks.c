/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_checks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 22:25:00 by avedrenn          #+#    #+#             */
/*   Updated: 2023/09/19 15:52:59 by mrabourd         ###   ########.fr       */
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
