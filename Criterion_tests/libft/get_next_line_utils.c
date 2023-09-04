/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:01:55 by avedrenn          #+#    #+#             */
/*   Updated: 2023/01/17 12:22:00 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	res = (char *) malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j] && j < BUFFER_SIZE)
	{
		if (j > 0 && s2[j - 1] == '\n')
			break ;
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = 0;
	free(s1);
	return (res);
}

void	ft_strcpy(char *dst, const char *src, long int ret)
{
	long int	i;

	if (!dst || !src)
		return ;
	i = 0;
	while (src[i] != 0 && i < ret)
	{
		dst[i] = src[i];
		i ++;
	}
	dst[i] = 0;
}
