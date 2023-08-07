/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:25:52 by avedrenn          #+#    #+#             */
/*   Updated: 2022/11/15 11:14:05 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char a, char sep)
{
	if (a == sep)
		return (1);
	return (0);
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (s[i])
	{
		while (is_sep(s[i], c) && s[i])
			i ++;
		if (!is_sep(s[i], c) && s[i])
			w ++;
		while (!is_sep(s[i], c) && s[i])
			i ++;
	}
	return (w);
}

static char	*strdup_from(char const *s, char c, int start)
{
	int		i;
	char	*res;

	i = 0;
	while (!is_sep(s[start + i], c) && s[start + i])
		i ++;
	res = (char *) malloc (i * sizeof(char) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (!is_sep(s[start + i], c) && s[start + i])
	{
		res[i] = s[start + i];
		i ++;
	}
	res[i] = 0;
	return (res);
}

static void	*ft_free(char **res, int i)
{
	while (i >= 0)
	{
		free(res[i]);
		i --;
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	res = (char **) malloc ((count_words(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (j < count_words(s, c) && s[i])
	{
		while (is_sep(s[i], c) && s[i])
			i ++;
		if (!is_sep(s[i], c) && s[i])
			res[j] = strdup_from(s, c, i);
		if (!res[j])
			return (ft_free(res, j - 1));
		while (!is_sep(s[i], c) && s[i])
			i ++;
		j ++;
	}
	res[j] = 0;
	return (res);
}
