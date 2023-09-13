/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 19:36:52 by mrabourd          #+#    #+#             */
/*   Updated: 2023/09/13 15:03:33 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project.h"

double	determine_two(t_matrix_2 a)
{
	double	b;

	b = (a.tab[0][0] * a.tab[1][1])
		- (a.tab[0][1] * a.tab[1][0]);
	return (b);
}

double	determine_three(t_matrix_3 a)
{
	double	cof;
	double	deter;

	deter = 0;
	cof = cofactor_3(a, 0, 0);
	deter += a.tab[0][0] * cof;
	cof = cofactor_3(a, 0, 1);
	deter += a.tab[0][1] * cof;
	cof = cofactor_3(a, 0, 2);
	deter += a.tab[0][2] * cof;
	return (deter);
}

t_matrix_2	submatrix_3(t_matrix_3 a, int row, int col)
{
	t_matrix_2	b;
	int			x;
	int			y;
	int			i;
	int			j;

	i = 0;
	x = 0;
	while (x < 3)
	{
		if (x != row)
		{
			y = 0;
			j = 0;
			while (y < 3)
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

double	minor_3(t_matrix_3 a, int row, int col)
{
	t_matrix_2	b;
	double			minor;

	b = submatrix_3(a, row, col);
	minor = determine_two(b);
	return (minor);
}

double	cofactor_3(t_matrix_3 a, int row, int col)
{
	double	minor;

	minor = minor_3(a, row, col);
	if ((row + col) % 2 != 0)
		minor *= -1;
	return (minor);
}
