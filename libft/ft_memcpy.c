/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:40:22 by avedrenn          #+#    #+#             */
/*   Updated: 2022/11/09 21:10:23 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	while (n != 0 && dst != src)
	{
		((char *)dst)[n - 1] = ((char *)src)[n - 1];
		n --;
	}
	return (dst);
}
