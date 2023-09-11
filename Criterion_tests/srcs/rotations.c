/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:23:24 by avedrenn          #+#    #+#             */
/*   Updated: 2023/09/11 14:03:13 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project.h"


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