/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:21:41 by avedrenn          #+#    #+#             */
/*   Updated: 2023/09/21 16:03:10 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	ft_swap_double(double	*a, double	*b)
{
	double	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_double_tab(double *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < size - 1)
	{
		if (tab[i] > tab[j])
			ft_swap_double(&tab[i], &tab[j]);
		i++;
		j++;
	}
	i = 0;
	j = 1;
	while (i < size - 1)
	{
		if (tab[i] > tab[j])
			ft_sort_double_tab(tab, size);
		i++;
		j++;
	}
}
