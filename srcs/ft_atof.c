/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:18:24 by mrabourd          #+#    #+#             */
/*   Updated: 2023/08/08 20:29:52 by avedrenn         ###   ########.fr       */
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
	while(str[i] && str[i] != '.')
        i++; 
    if (str[i] && str[i] == '.')
	{
        i++;
		ret2 = (double)ft_atoi(&str[i]);
		len = ft_strlen(&str[i]);
		while(len--)
		{
			ret2 /= 10;
		}
	}
    ret *= minus;
	printf("atof => %f + %f = %f\n", ret, ret2, (ret + ret2));
    return (ret + ret2);
}