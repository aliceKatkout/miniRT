/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:29:00 by avedrenn          #+#    #+#             */
/*   Updated: 2022/10/18 18:21:10 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	minus;
	int	res;

	i = 0;
	res = 0;
	minus = 1;
	while (nptr[i] && is_space(nptr[i]))
		i ++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			minus *= -1;
		i ++;
	}
	while (ft_isdigit((int) nptr[i]) && nptr[i])
	{
		res = (res * 10) + ((int) nptr[i] - 48);
		i ++;
	}
	return (minus * res);
}
