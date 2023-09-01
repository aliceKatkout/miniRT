/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 18:44:29 by mrabourd          #+#    #+#             */
/*   Updated: 2023/09/01 15:25:19 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project.h"

t_matrix_4	matrix_mult_4(t_matrix_4 a, t_matrix_4 b)
{
	t_matrix_4	c;
	int			x;
	int			y;
	int			u;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			u = 0;
			c.tab[x][y] = 0;
			while (u < 4)
			{
				c.tab[x][y] += a.tab[x][u] * b.tab[u][y];
				u++;
			}
			y++;
		}
		x++;
	}
	return (c);
}

double	res_mult(t_matrix_4 a, t_tuple point, int x)
{
	double	res;

	res = 0;
	res = a.tab[x][0] * point.x;
	res += a.tab[x][1] * point.y;
	res += a.tab[x][2] * point.z;
	res += a.tab[x][3] * point.w;
	return (res);
}

t_tuple	matrix_mult_tuple(t_matrix_4 a, t_tuple point)
{
	t_tuple	c;

	c.x = res_mult(a, point, 0);
	c.y = res_mult(a, point, 1);
	c.z = res_mult(a, point, 2);
	c.w = res_mult(a, point, 3);
	return (c);
}

t_matrix_4	transpose_mat(t_matrix_4 mat)
{
	t_matrix_4	res;
	int			x;
	int			y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			res.tab[y][x] = mat.tab[x][y];
			y++;
		}
		x++;
	}
	return (res);
}
