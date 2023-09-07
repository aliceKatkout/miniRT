/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:23:24 by avedrenn          #+#    #+#             */
/*   Updated: 2023/09/07 14:29:35 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project.h"

/* void print_matrix_4(t_matrix_4 a)
{
	int	x;
	int	y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			printf("a.tab[%d][%d]: %f\n", x, y, a.tab[x][y]);
			y++;
		}
		x++;
	}
} */

t_matrix_4	rotation_x(float rad)
{
	t_matrix_4	matrix;

	matrix = create_matrix_4((float [16]){
			1, 0, 0, 0,
			0, cos(rad), -sin(rad), 0,
			0, sin(rad), cos(rad), 0,
			0, 0, 0, 1
		});
	return (matrix);
}

t_matrix_4	rotation_y(float rad)
{
	t_matrix_4	matrix;

	matrix = create_matrix_4((float [16]){
			cos(rad), 0, sin(rad), 0,
			0, 1, 0, 0,
			-sin(rad), 0, cos(rad), 0,
			0, 0, 0, 1
		});
	return (matrix);
}

t_matrix_4	rotation_z(float rad)
{
	t_matrix_4	matrix;

	matrix = create_matrix_4((float [16]){
			cos(rad), -sin(rad), 0, 0,
			sin(rad), cos(rad), 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		});
	return (matrix);
}