/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_in_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:19:06 by avedrenn          #+#    #+#             */
/*   Updated: 2023/09/18 12:19:26 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(int	*a, int	*b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < size - 1)
	{
		if (tab[i] > tab[j])
		{
			ft_swap(&tab[i], &tab[j]);
		}
		i++;
		j++;
	}
	i = 0;
	j = 1;
	while (i < size - 1)
	{
		if (tab[i] > tab[j])
		{
			ft_sort_int_tab(tab, size);
		}
		i++;
		j++;
	}
}
