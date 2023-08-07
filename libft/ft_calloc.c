/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:04:13 by avedrenn          #+#    #+#             */
/*   Updated: 2022/11/13 14:03:23 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;

	if (SIZE_MAX / size < nmemb)
		return (NULL);
	mem = malloc (nmemb * size);
	if (!mem)
		return (NULL);
	mem = ft_memset(mem, 0, nmemb * size);
	return (mem);
}
