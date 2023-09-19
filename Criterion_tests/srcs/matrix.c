/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:25:22 by mrabourd          #+#    #+#             */
/*   Updated: 2023/09/19 18:44:21 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project.h"

t_matrix_4	create_matrix_4(double tab[16])
{
	t_matrix_4	matrix;
	int			i;
	int			x;
	int			y;

	x = 0;
	y = 0;
	i = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			matrix.tab[x][y] = tab[i];
			y++;
			i++;
		}
		x++;
	}
	return (matrix);
}

double	matrix_cmp_4(t_matrix_4 a, t_matrix_4 b)
{
	int	x;
	int	y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (fabs(a.tab[x][y] - b.tab[x][y]) > EPSILON)
				return (a.tab[x][y] - b.tab[x][y]);
			y++;
		}
		x++;
	}
	return (0);
}

/* If you multiply any
matrix or tuple by the identity matrix, you get back the matrix or tuple you
started with. */
t_matrix_4	identity_matrix(void)
{
	t_matrix_4	id;
	double		tab[16];

	tab[0] = 1;
	tab[1] = 0;
	tab[2] = 0;
	tab[3] = 0;
	tab[4] = 0;
	tab[5] = 1;
	tab[6] = 0;
	tab[7] = 0;
	tab[8] = 0;
	tab[9] = 0;
	tab[10] = 1;
	tab[11] = 0;
	tab[12] = 0;
	tab[13] = 0;
	tab[14] = 0;
	tab[15] = 1;
	id = create_matrix_4(tab);
	return (id);
}
