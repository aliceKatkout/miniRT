/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_cam_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:02:01 by mrabourd          #+#    #+#             */
/*   Updated: 2023/09/21 19:02:24 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_tuple	conv_vec(char **param)
{
	t_tuple		pos;

	pos.x = ft_atof(param[0]);
	pos.y = ft_atof(param[1]);
	pos.z = ft_atof(param[2]);
	pos.w = 1;
	ft_free_arr((void **) param);
	return (pos);
}

t_tuple	conv_cam_orientation(char **vec)
{
	t_tuple		to;

	to.x = ft_atof(vec[0]);
	to.y = ft_atof(vec[1]);
	to.z = ft_atof(vec[2]);
	if (to.z == 0)
		to.z = EPSILON;
	to.w = 0;
	ft_free_arr((void **) vec);
	return (to);
}
