/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 22:25:00 by avedrenn          #+#    #+#             */
/*   Updated: 2023/08/10 16:32:51 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../miniRT.h"

int		is_in_range(double val, double min, double max)
{
	if (val >= min && val <= max)
		return (1);
	return (0);
}

int		is_number(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '-')
		i ++;
	while(str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '.')
			return (0);
		i ++;
	}
	return (1);
}