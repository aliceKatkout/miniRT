/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_fts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:21:13 by avedrenn          #+#    #+#             */
/*   Updated: 2023/08/10 17:02:44 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	put_c(int count, va_list lst)
{
	char	c;

	c = va_arg(lst, int);
	return (count + write(1, &c, 1));
}

int	put_s(int count, va_list lst)
{
	char	*str;

	str = va_arg(lst, char *);
	if (!str)
		return (count + write(1, "(null)", 6));
	count += write(1, str, ft_strlen(str));
	return (count);
}

int	put_p(int count, va_list lst)
{
	char			*base;
	char			res[9];
	int				i;
	unsigned long	adr;
	void			*ptr;

	ptr = va_arg(lst, void *);
	if (!ptr)
		return (count + write(1, "(nil)", 5));
	base = "0123456789abcdef";
	adr = (unsigned long) ptr;
	i = 8;
	while ((adr / 16) > 0 || i > 0)
	{
		res[i] = base[(adr % 16)];
		adr /= 16;
		i--;
	}
	res[i] = base[(adr % 16)];
	count += write(1, "0x", 2);
	while (res[i] == '0')
		i++;
	while (i < 9)
		count += write(1, &res[i++], 1);
	return (count);
}

int	put_id(int count, va_list lst)
{
	char	*res;
	int		a;
	int		b;

	a = 0;
	b = va_arg(lst, int);
	res = ft_itoa(b);
	if (!res)
		return (-1);
	while (res[a])
		count += write(1, &res[a++], 1);
	free(res);
	return (count);
}
