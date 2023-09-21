/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:35:59 by mrabourd          #+#    #+#             */
/*   Updated: 2023/09/21 16:03:10 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_matrix_4	translation(double x, double y, double z)
{
	t_matrix_4	res;

	res = identity_matrix();
	res.tab[0][3] = x;
	res.tab[1][3] = y;
	res.tab[2][3] = z;
	res.tab[3][3] = 1;
	return (res);
}

t_matrix_4	scaling(double x, double y, double z)
{
	t_matrix_4	res;

	res = identity_matrix();
	res.tab[0][0] = x;
	res.tab[1][1] = y;
	res.tab[2][2] = z;
	res.tab[3][3] = 1;
	return (res);
}
