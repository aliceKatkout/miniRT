/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:25:05 by avedrenn          #+#    #+#             */
/*   Updated: 2022/11/15 12:08:27 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_size;
	size_t	i;

	if (!size)
		return (ft_strlen(src));
	dst_size = ft_strlen(dst);
	i = 0;
	while ((dst_size + i) < (size - 1) && src[i])
	{
		dst[i + dst_size] = src[i];
		i ++;
	}
	if (i > 0)
		dst[i + dst_size] = 0;
	if (dst_size > size)
		return (size + ft_strlen(src));
	return (dst_size + ft_strlen(src));
}
