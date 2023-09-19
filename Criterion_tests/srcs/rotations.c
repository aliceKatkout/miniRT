/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:23:24 by avedrenn          #+#    #+#             */
/*   Updated: 2023/09/19 19:06:35 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project.h"

t_matrix_4	rotation_x(double rad)
{
	t_matrix_4	matrix;

	matrix = create_matrix_4((double [16]){
			1, 0, 0, 0,
			0, cos(rad), -sin(rad), 0,
			0, sin(rad), cos(rad), 0,
			0, 0, 0, 1
		});
	return (matrix);
}

t_matrix_4	rotation_y(double rad)
{
	t_matrix_4	matrix;

	matrix = create_matrix_4((double [16]){
			cos(rad), 0, sin(rad), 0,
			0, 1, 0, 0,
			-sin(rad), 0, cos(rad), 0,
			0, 0, 0, 1
		});
	return (matrix);
}

t_matrix_4	rotation_z(double rad)
{
	t_matrix_4	matrix;

	matrix = create_matrix_4((double [16]){
			cos(rad), -sin(rad), 0, 0,
			sin(rad), cos(rad), 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		});
	return (matrix);
}
