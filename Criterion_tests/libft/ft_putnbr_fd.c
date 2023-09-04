/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:50:31 by avedrenn          #+#    #+#             */
/*   Updated: 2022/11/15 11:14:36 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	if (n < 0)
	{
		nb = n * -1;
		write(fd, "-", 1);
	}
	else
		nb = n;
	if (nb <= 9)
		ft_putchar_fd(nb + 48, fd);
	else if (nb >= 9)
	{
		ft_putnbr_fd((int)(nb / 10), fd);
		ft_putchar_fd(nb % 10 + 48, fd);
	}
}
