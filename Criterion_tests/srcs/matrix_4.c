/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 19:36:52 by mrabourd          #+#    #+#             */
/*   Updated: 2023/09/01 12:52:22 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project.h"

int	determine_four(t_matrix_4 a)
{
	int	cof;
	int	deter;

	deter = 0;
	cof = cofactor_4(a, 0, 0);
	deter += a.tab[0][0] * cof;
	cof = cofactor_4(a, 0, 1);
	deter += a.tab[0][1] * cof;
	cof = cofactor_4(a, 0, 2);
	deter += a.tab[0][2] * cof;
	cof = cofactor_4(a, 0, 3);
	deter += a.tab[0][3] * cof;
	return (deter);
}

t_matrix_3	submatrix_4(t_matrix_4 a, int row, int col)
{
	t_matrix_3	b;
	int			x;
	int			y;
	int			i;
	int			j;

	i = 0;
	x = 0;
	while (x < 4)
	{
		if (x != row)
		{
			y = 0;
			j = 0;
			while (y < 4)
			{
				if (y != col)
					b.tab[i][j++] = a.tab[x][y];
				y++;
			}
			i++;
		}
		x++;
	}
	return (b);
}

int	minor_4(t_matrix_4 a, int row, int col)
{
	t_matrix_3	b;
	int			minor;

	b = submatrix_4(a, row, col);
	minor = determine_three(b);
	return (minor);
}

int	cofactor_4(t_matrix_4 a, int row, int col)
{
	int	minor;
	int	signe;

	minor = minor_4(a, row, col);
	signe = row + col;
	if (signe % 2 != 0)
		signe = -1;
	else
		signe = 1;
	return (minor * signe);
}
