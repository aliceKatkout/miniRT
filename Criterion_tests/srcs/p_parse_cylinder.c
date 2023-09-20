/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:02:41 by mrabourd          #+#    #+#             */
/*   Updated: 2023/09/20 14:43:22 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project.h"

double	cylinder_min(t_obj *cyl)
{
	double	min;

	min = 0 + cyl->y;
	return (min);
}

double	cylinder_max(t_obj *cyl)
{
	double	max;

	max = cyl->height + cyl->y;
	return (max);
}

t_matrix_4	fuse_rotate(t_obj	*cy)
{
	t_matrix_4	matrix;
	t_matrix_4	matrix1;
	t_matrix_4	matrix2;
	t_matrix_4	matrix3;

	matrix1 = rotation_x((PI * cy->direction.x));
	matrix2 = rotation_y((PI * cy->direction.y));
	matrix3 = rotation_z((PI * cy->direction.z));
	matrix = matrix_mult_4(matrix1, matrix2);
	matrix = matrix_mult_4(matrix, matrix3);
	return (matrix);
}

t_matrix_4	cyl_transfo_matr(t_obj *cy)
{
	t_matrix_4	res;
	t_matrix_4	rotate_matrix;

	rotate_matrix = fuse_rotate(cy);
	res = rotate_matrix;
	res = matrix_mult_4(res, scaling(cy->radius, 1, cy->radius));
	res = matrix_mult_4(res, translation(cy->x, cy->y, cy->z));
	return (res);
}

int	init_cylinder(char **params, t_obj	*cy)
{
	char		**vec;

	cy->shape = CYLINDER;
	cy->closed = 1;
	if (set_diam_height_rad(params[3], params[4], cy))
		return (1);
	if (init_xyz(cy, params[1]))
		return (1);
	if (init_rgb(cy, params[5]))
		return (1);
	vec = check_vectors(params[2]);
	if (!vec)
		return (1);
	cy->direction = create_vector(ft_atof(vec[0]),
			ft_atof(vec[1]), ft_atof(vec[2]));
	ft_free_arr((void **)vec);
	cy->transform = cyl_transfo_matr(cy);
	cy->min = cylinder_min(cy);
	cy->max = cylinder_max(cy);
	return (0);
}
