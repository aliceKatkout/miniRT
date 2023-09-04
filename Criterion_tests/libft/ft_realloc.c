/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:31:52 by avedrenn          #+#    #+#             */
/*   Updated: 2022/12/10 15:32:07 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	char	*res;
	size_t	i;

	if (ptr && size == 0)
	{
		free(ptr);
		return (NULL);
	}
	res = malloc(size);
	if (!res)
		return (NULL);
	i = 0;
	while (ptr && ((char *)ptr)[i] && i < size)
	{
		res[i] = ((char *)ptr)[i];
		i++;
	}
	while (i < size)
	{
		res[i] = 0;
		i++;
	}
	free(ptr);
	return ((void *) res);
}
