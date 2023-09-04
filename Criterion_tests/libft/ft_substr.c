/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:21:39 by avedrenn          #+#    #+#             */
/*   Updated: 2022/11/13 14:18:50 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	size_src;

	if (!s)
		return (NULL);
	size_src = ft_strlen(s);
	if ((size_t) start + len > size_src && start < size_src && len <= size_src)
		len = len - (size_t) start;
	else if (start >= size_src)
		len = 0;
	else if (len > size_src)
		len = size_src - (size_t) start;
	res = (char *) malloc (len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len && s[(size_t)start + i])
	{
		res[i] = s[start + i];
		i ++;
	}
	res[i] = 0;
	return (res);
}
