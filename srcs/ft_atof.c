/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:18:24 by mrabourd          #+#    #+#             */
/*   Updated: 2023/08/08 16:57:17 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../miniRT.h"

double  ft_atof(char *str)
{
    double  ret;
    double  ret2;
    int     minus;
    int     len;
    int     i;

    i = 0;
    len = 0;
    minus = 1;
    ret = (double)ft_atoi(str);
    ret2 = 0;
    while (str[i] && is_space(str[i]))
		i ++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
    while(str[i] != '.')
        i++;
    if (str[i] != '.')
        i++;
    ret2 = (double)ft_atoi(&str[i]);
    len = ft_strlen(&str[i]);
    while(len--)
    {
        ret2 /= 10;
    }
    ret *= minus;
    return (ret + ret2);
}