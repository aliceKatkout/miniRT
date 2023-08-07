/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:49:43 by avedrenn          #+#    #+#             */
/*   Updated: 2022/12/08 14:25:19 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_type(char c)
{
	int		j;
	char	*letters;

	letters = "cspdiuxX%";
	j = 0;
	while (c != letters[j] && letters[j])
		j ++;
	return (j);
}

static void	init_fts(int (*fts[8])(int, va_list))
{
	(fts)[0] = put_c;
	(fts)[1] = put_s;
	(fts)[2] = put_p;
	(fts)[3] = put_id;
	(fts)[4] = put_id;
	(fts)[5] = put_u;
	(fts)[6] = put_x;
	(fts)[7] = put_bx;
}

int	pr_f(int (*fts[8])(int, va_list), va_list lst, const char *str, int count)
{
	int	i;
	int	c;

	i = 0;
	while (str[i])
	{
		while (str[i] != '%' && str[i])
			count += write(1, &str[i++], 1);
		if (str[i])
		{
			i ++;
			if (str[i] != '%')
			{
				c = (fts)[ft_find_type(str[i])](count, lst);
				if (c < count)
					return (-1);
				else
					count = c;
			}
			else
				count += write(1, &str[i], 1);
			i++;
		}
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		(*fts[8])(int, va_list);
	int		count;

	va_list(lst);
	init_fts((fts));
	va_start(lst, str);
	count = 0;
	count = pr_f((fts), lst, str, count);
	if (count < 0)
		return (-1);
	va_end(lst);
	return (count);
}

/*  int main ()
{
	//char	*str;
	unsigned int b;

	b = (unsigned int) LONG_MAX;
	//str = "ab";

  	//str = "Test";
  	printf("le vrai : %d\n", printf("Ad:%x\n", b));
	printf("le faux : %d\n", ft_printf("Ad:%x\n", b));
	return (0);
} */
//put_p, put_d, put_i, put_u, put_x, put_X, put_pc