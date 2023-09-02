/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_tuples2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:56:06 by mrabourd          #+#    #+#             */
/*   Updated: 2023/09/02 13:24:34 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project.h"

/* The distance represented by a vector is
called its magnitude, or length. It’s how far you would travel in a straight line
if you were to walk from one end of the vector to the other. */
double	magn_tuple(t_tuple a)
{
	double	add_sqrs;
	double	c;

	add_sqrs = (a.x * a.x) + (a.y * a.y)
		+ (a.z * a.z) + (a.w * a.w);
	c = sqrtf(add_sqrs);
	return (c);
}

/* Vectors with magnitudes of 1 are called a unit vectors.
Normalization is the process of taking an arbitrary vector and converting it
into a unit vector. To normalize a vector, you divide it by its magnitude. */
t_tuple	normalize(t_tuple vec)
{
	t_tuple	normlzd;
	double	magn;

	magn = magn_tuple(vec);
	normlzd.x = vec.x / magn;
	normlzd.y = vec.y / magn;
	normlzd.z = vec.z / magn;
	normlzd.w = 0;
	return (normlzd);
}

/* Dot product = You get a scalar value from 2 vectors*/
double	dot_product(t_tuple a, t_tuple b)
{
	double	ret;

	ret = (a.x * b.x) + (a.y * b.y)
		+ (a.z * b.z) + (a.w * b.w);
	return (ret);
}

/*Cross product = You get a new vector that is perpendicular
to both of the original vectors */
t_tuple	cross_product(t_tuple a, t_tuple b)
{
	t_tuple	vec;

	vec.x = (a.y * b.z) - (a.z * b.y);
	vec.y = (a.z * b.x) - (a.x * b.z);
	vec.z = (a.x * b.y) - (a.y * b.x);
	vec.w = 0;
	return (vec);
}
