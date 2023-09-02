/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shearing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:18:44 by avedrenn          #+#    #+#             */
/*   Updated: 2023/09/02 16:21:25 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project.h"

t_matrix_4	shearing(float xy, float xz, float yx, float yz, float zx, float zy)
{
	t_matrix_4	matrix;

	matrix = create_matrix_4((float [16]){
			1, xy, xz, 0,
			yx, 1, yz, 0,
			zx, zy, 1, 0,
			0, 0, 0, 1
		});
	return (matrix);
}