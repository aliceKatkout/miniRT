/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shearing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:18:44 by avedrenn          #+#    #+#             */
/*   Updated: 2023/09/12 18:23:59 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project.h"

t_matrix_4	shearing(double xy, double xz, double yx, double yz, double zx, double zy)
{
	t_matrix_4	matrix;

	matrix = create_matrix_4((double [16]){
			1, xy, xz, 0,
			yx, 1, yz, 0,
			zx, zy, 1, 0,
			0, 0, 0, 1
		});
	return (matrix);
}