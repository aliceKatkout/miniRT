/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_tuples3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:14:14 by mrabourd          #+#    #+#             */
/*   Updated: 2023/09/21 16:03:10 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_tuple	mult_3(t_tuple tuple1, double vec1, double vec2)
{
	t_tuple	res;

	res = mult_tuples(tuple1, vec1);
	res = mult_tuples(res, vec2);
	return (res);
}

t_tuple	add_3_tuples(t_tuple tuple1, t_tuple tuple2, t_tuple tuple3)
{
	t_tuple	res;

	res = add_tuples(tuple1, tuple2);
	res = add_tuples(res, tuple3);
	return (res);
}
