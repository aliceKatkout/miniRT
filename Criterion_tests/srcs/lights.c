/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:10:09 by mrabourd          #+#    #+#             */
/*   Updated: 2023/09/07 11:52:56 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project.h"

t_tuple		normal_at(t_sphere sphere, t_tuple point)
{
	t_tuple	normal;
	(void)sphere;

	normal = create_vector(point.x, point.y, point.z);
	return (normal);
}