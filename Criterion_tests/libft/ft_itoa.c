/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:24:33 by avedrenn          #+#    #+#             */
/*   Updated: 2022/12/08 14:29:40 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_s(unsigned int nb, int minus)
{
	int	size;

	size = 1;
	while (nb >= 10)
	{
		nb = nb / 10;
		size ++;
	}
	if (minus < 0)
		return (size + 1);
	return (size);
}

static char	*revstr(char *res)
{
	int		size;
	int		i;
	char	tmp;

	i = 0;
	size = 0;
	while (res[size])
		size ++;
	while (i < size / 2)
	{
		tmp = res[i];
		res[i] = res[size - 1 - i];
		res[size - 1 - i] = tmp;
		i ++;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	unsigned int	nb;
	int				minus;
	char			*res;
	int				i;

	minus = 1;
	if (n < 0)
		minus *= -1;
	nb = n * minus;
	res = (char *) malloc (find_s(nb, minus) + 1);
	if (!res)
		return (NULL);
	i = 0;
	if (nb == 0)
		res[i++] = '0';
	while (nb > 0)
	{
		res[i++] = (nb % 10) + 48;
		nb = nb / 10;
	}
	if (minus < 0)
		res[i++] = '-';
	res[i] = 0;
	return (revstr(res));
}
