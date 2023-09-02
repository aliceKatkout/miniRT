/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_shearing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:15:41 by avedrenn          #+#    #+#             */
/*   Updated: 2023/09/02 16:25:00 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion.h>
#include "../project.h"

Test(matrix, shearing1)
{
	t_matrix_4	transform;
	t_tuple		p;
	t_tuple		res;

	transform = shearing(1, 0, 0, 0, 0, 0);
	p = create_point(2, 3, 4);
	res = matrix_mult_tuple(transform, p);
	cr_expect(res.x == 5);
	cr_expect(res.y == 3);
	cr_expect(res.z == 4);
}

Test(matrix, shearing2)
{
	t_matrix_4	transform;
	t_tuple		p;
	t_tuple		res;

	transform = shearing(0, 1, 0, 0, 0, 0);
	p = create_point(2, 3, 4);
	res = matrix_mult_tuple(transform, p);
	cr_expect(res.x == 6);
	cr_expect(res.y == 3);
	cr_expect(res.z == 4);
}

Test(matrix, shearing3)
{
	t_matrix_4	transform;
	t_tuple		p;
	t_tuple		res;

	transform = shearing(0, 0, 1, 0, 0, 0);
	p = create_point(2, 3, 4);
	res = matrix_mult_tuple(transform, p);
	cr_expect(res.x == 2);
	cr_expect(res.y == 5);
	cr_expect(res.z == 4);
}

Test(matrix, shearing4)
{
	t_matrix_4	transform;
	t_tuple		p;
	t_tuple		res;

	transform = shearing(0, 0, 0, 1, 0, 0);
	p = create_point(2, 3, 4);
	res = matrix_mult_tuple(transform, p);
	cr_expect(res.x == 2);
	cr_expect(res.y == 7);
	cr_expect(res.z == 4);
}

Test(matrix, shearing5)
{
	t_matrix_4	transform;
	t_tuple		p;
	t_tuple		res;

	transform = shearing(0, 0, 0, 0, 1, 0);
	p = create_point(2, 3, 4);
	res = matrix_mult_tuple(transform, p);
	cr_expect(res.x == 2);
	cr_expect(res.y == 3);
	cr_expect(res.z == 6);
}

Test(matrix, shearing6)
{
	t_matrix_4	transform;
	t_tuple		p;
	t_tuple		res;

	transform = shearing(0, 0, 0, 0, 0, 1);
	p = create_point(2, 3, 4);
	res = matrix_mult_tuple(transform, p);
	cr_expect(res.x == 2);
	cr_expect(res.y == 3);
	cr_expect(res.z == 7);
}