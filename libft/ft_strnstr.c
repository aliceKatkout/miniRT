/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:30:01 by avedrenn          #+#    #+#             */
/*   Updated: 2022/11/15 11:13:17 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	search_in(const char *s1, const char *s2, size_t n, size_t start)
{
	size_t	j;

	j = 0;
	while (start + j <= n && s1[start + j] && s2[j])
	{
		if (s1[start + j] == s2[j])
			j++;
		else
			return (0);
	}
	return (1);
}

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(s2);
	if (! *s2)
		return ((char *)s1);
	if (!s1)
		return (NULL);
	i = 0;
	while (s1[i] && i <= n)
	{
		if (s1[i] == s2[0] && search_in(s1, s2, n, i) && i + len <= n)
			return ((char *)(s1 + i));
		i ++;
	}
	return (NULL);
}
