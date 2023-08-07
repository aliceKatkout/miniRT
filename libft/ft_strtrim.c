/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:52:05 by avedrenn          #+#    #+#             */
/*   Updated: 2022/11/13 13:33:49 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	totrim(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i ++;
	}
	return (0);
}

static size_t	find_size(char const *s1, char const *set, size_t i)
{
	size_t	size;

	size = ft_strlen(s1);
	while (totrim(s1[size - 1], set) && s1[size - 1])
		size --;
	if (i >= size)
		size = 0;
	else
		size = size - i;
	return (size);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	size;
	char	*res;
	size_t	j;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (totrim(s1[i], set) && s1[i])
		i ++;
	size = find_size(s1, set, i);
	j = 0;
	res = (char *) malloc (size + 1);
	if (!res)
		return (NULL);
	while (s1[j] && j < size)
	{
		res[j] = s1[i + j];
		j ++;
	}
	res[j] = 0;
	return (res);
}
