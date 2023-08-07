/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_fts2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:36:18 by avedrenn          #+#    #+#             */
/*   Updated: 2022/12/08 14:26:03 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	find_size(long int nb, unsigned int s)
{
	long int	size;

	size = 1;
	while (nb >= s)
	{
		nb = nb / s;
		size ++;
	}
	return (size);
}

char	*put_uns_nbr_base(unsigned int i, char *base, char *res, long int j)
{
	size_t	s;

	if (!base)
		return (NULL);
	s = ft_strlen(base);
	while ((i / s) > 0 || j > 0)
	{
		res[j] = base[(i % s)];
		i /= s;
		j--;
	}
	res[j] = base[(i % s)];
	return (res);
}

int	put_u(int count, va_list lst)
{
	char			*res;
	int				a;
	unsigned int	b;
	size_t			s;
	long int		j;

	a = 0;
	b = va_arg(lst, unsigned int);
	s = ft_strlen("0123456789");
	j = find_size(b, s);
	res = malloc(j + 1);
	if (!res)
		return (-1);
	res[j] = 0;
	res = put_uns_nbr_base(b, "0123456789", res, j - 1);
	if (!res)
		return (-1);
	while (res[a] && a < j)
		count += write(1, &res[a++], 1);
	free(res);
	return (count);
}

int	put_x(int count, va_list lst)
{
	char			*res;
	int				a;
	unsigned int	b;
	size_t			s;
	unsigned int	j;

	a = 0;
	b = va_arg(lst, unsigned int);
	s = ft_strlen("0123456789abcdef");
	j = find_size(b, s);
	res = malloc(j + 1);
	if (!res)
		return (-1);
	res[j] = 0;
	res = put_uns_nbr_base(b, "0123456789abcdef", res, j - 1);
	if (!res)
		return (-1);
	while (res[a])
		count += write(1, &res[a++], 1);
	free(res);
	return (count);
}

int	put_bx(int count, va_list lst)
{
	char			*res;
	int				a;
	unsigned int	b;
	size_t			s;
	unsigned int	j;

	a = 0;
	b = va_arg(lst, unsigned int);
	s = ft_strlen("0123456789ABCDEF");
	j = find_size(b, s);
	res = malloc(j + 1);
	if (!res)
		return (-1);
	res[j] = 0;
	res = put_uns_nbr_base(b, "0123456789ABCDEF", res, j - 1);
	if (!res)
		return (-1);
	while (res[a])
		count += write(1, &res[a++], 1);
	free(res);
	return (count);
}
