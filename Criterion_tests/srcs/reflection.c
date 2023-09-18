/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:48:38 by mrabourd          #+#    #+#             */
/*   Updated: 2023/09/18 19:46:33 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project.h"

t_tuple	reflect(t_tuple in, t_tuple normal)
{
	t_tuple	res;

	res = mult_tuples(normal, 2);
	res = mult_tuples(res, dot_product(in, normal));;
	res = sub_tuples(in, res);
	return (res);
}

t_light	point_light(t_tuple position, t_tuple intensity)
{
	t_light	light;

	light.position = position,
	light.intensity = intensity;
	return (light);
}

t_material	init_material(void)
{
	t_material	m;

	m.color = create_color(1, 1, 1);
	m.ambient = 0.1;
	m.diffuse = 0.9;
	m.specular = 0.9;
	m.shininess = 200.0;
	return (m);
}