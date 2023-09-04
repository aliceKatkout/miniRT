/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:41:48 by avedrenn          #+#    #+#             */
/*   Updated: 2023/08/10 14:48:33 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s || !fd)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i ++;
	}
}

int	ft_putstr_fdi(char *s, int fd)
{
	int	i;

	if (!s || !fd)
		return (-1);
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i ++;
	}
	return (i);
}
