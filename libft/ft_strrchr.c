/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:11:51 by avdrenn           #+#    #+#             */
/*   Updated: 2022/11/10 13:41:13 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = (ft_strlen(s) - 1);
	if (!c)
		return ((char *)(s + i + 1));
	while (i >= 0)
	{
		if (s[i] == (char) c)
			return ((char *)(s + i));
		i --;
	}
	return (NULL);
}
