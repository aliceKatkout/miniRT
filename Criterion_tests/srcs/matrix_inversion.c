/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_inversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 14:34:52 by mrabourd          #+#    #+#             */
/*   Updated: 2023/09/07 15:23:12 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project.h"

int	is_invertible(t_matrix_4 a)
{
	if (determine_four(a) == 0)
		return (0);
	return (1);
}

t_matrix_4	mat_inversion_4(t_matrix_4 a)
{
	int	x;
	int	y;
	int	deter;
	int	cofact;
	t_matrix_4	res;

	x = 0;
	deter = determine_four(a);
	if (is_invertible(a) != 0)
	{
		while (x < 4)
		{
			y = 0;
			while (y < 4)
			{
				cofact = cofactor_4(a, x, y);
				res.tab[y][x] = (double)cofact / (double)deter;
				y++;
			}
			x++;
		}
	}
	else
		res = identity_matrix();
	return (res);
}