/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:25:22 by mrabourd          #+#    #+#             */
/*   Updated: 2023/08/31 20:18:07 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project.h"

t_matrix_4	create_matrix_4(float tab[16])
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

t_matrix_3	create_matrix_3(float tab[9])
{
	t_matrix_3	matrix;
	int			i;
	int			x;
	int			y;

	x = 0;
	y = 0;
	i = 0;
	while (x < 3)
	{
		y = 0;
		while (y < 3)
		{
			matrix.tab[x][y] = tab[i];
			y++;
			i++;
		}
		x++;
	}
	return (matrix);
}

t_matrix_2	create_matrix_2(float tab[4])
{
	t_matrix_2	matrix;
	int			i;
	int			x;
	int			y;

	x = 0;
	y = 0;
	i = 0;
	while (x < 2)
	{
		y = 0;
		while (y < 2)
		{
			matrix.tab[x][y] = tab[i];
			y++;
			i++;
		}
		x++;
	}
	return (matrix);
}

int	matrix_cmp_4(t_matrix_4 a, t_matrix_4 b)
{
	int	x;
	int	y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (a.tab[x][y] - b.tab[x][y] != 0)
				return (a.tab[x][y] - b.tab[x][y]);
			y++;
		}
		x++;
	}
	return (0);
}

t_matrix_4	identity_matrix(void)
{
	t_matrix_4	id;

	float		tab[16] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
	id = create_matrix_4(tab);
	return (id);
}
