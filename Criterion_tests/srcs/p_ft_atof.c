/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:18:24 by mrabourd          #+#    #+#             */
/*   Updated: 2023/09/18 16:30:59 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../project.h"

double  ft_atof(char *str)
{
    double  ret;
    double  ret2;
    int     minus;
    int     i;

    i = 0;
	minus = 1;
    ret = (double)ft_atoi(str);
	if (ret < 0)
	{
		minus = -1;
		ret *= -1;
	}
    ret2 = 0;
	while(str[i] && str[i] != '.')
        i++; 
    if (str[i] && str[i] == '.')
	{
        i++;
		ret2 = (double)ft_atoi(&str[i]);
		i = ft_strlen(&str[i]);
		while(i--)
			ret2 /= 10;
	}
	ret += ret2;
    return (minus * ret);
}