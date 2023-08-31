/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   submatrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 19:36:52 by mrabourd          #+#    #+#             */
/*   Updated: 2023/08/31 20:12:33 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project.h"

int	determine_two(t_matrix_2 a)
{
	int	b;

	b = (a.tab[0][0] * a.tab[1][1])
		- (a.tab[0][1] * a.tab[1][0]);
	return (b);
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
