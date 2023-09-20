/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:03:44 by mrabourd          #+#    #+#             */
/*   Updated: 2023/09/20 17:36:07 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project.h"

t_tuple	normal_at_cylinder(t_obj *cyl, t_tuple point)
{
	double	dist;

	dist = point.x * point.x + point.z * point.z;
	if (dist < 1 && (point.y >= cyl->max - EPSILON))
		return (create_vector(0, 1, 0));
	else if (dist < 1 && point.y <= cyl->min + EPSILON)
		return (create_vector(0, -1, 0));
	else
		return (create_vector(point.x, 0, point.z));
}

t_tuple	normal_at(t_obj *obj, t_tuple point)
{
	t_tuple	local_point;
	t_tuple	local_normal;
	t_tuple	world_normal;

	local_point = matrix_mult_tuple(mat_inversion_4(obj->transform), point);
	if (obj->shape == SPHERE)
		local_normal = sub_tuples(local_point,
				create_point(obj->x, obj->y, obj->z));
	else if (obj->shape == PLANE)
		local_normal = create_vector(0, 1, 0);
	else if (obj->shape == CYLINDER)
		local_normal = normal_at_cylinder(obj, local_point);
	world_normal = matrix_mult_tuple(
			transpose_mat(mat_inversion_4(obj->transform)), local_normal);
	world_normal.w = 0;
	return (normalize(world_normal));
}

t_tuple	lighting(t_material m, t_comp comp, t_light l, int in_shadow)
{
	t_tuple	ambient;
	double	reflect_dot_eye;
	t_tuple	res;

	l.eff_color = mult_colors(m.color, l.intensity);
	ambient = mult_colors(l.eff_color, l.amb.color);
	l.lightv = normalize(sub_tuples(l.position, comp.point));
	l.light_dot_normal = dot_product(l.lightv, comp.normalv);
	if (l.light_dot_normal < 0 || in_shadow == 1)
		return (ambient);
	else
	{
		l.diff = mult_3(l.eff_color, m.diffuse, l.light_dot_normal);
		l.lightv = reverse_tuple(l.lightv);
		l.reflectv = reflect(l.lightv, comp.normalv);
		reflect_dot_eye = dot_product(l.reflectv, comp.eyev);
		if (reflect_dot_eye <= 0)
			l.spec = create_color(0, 0, 0);
		else
			l.spec = mult_3(l.intensity, m.specular,
					pow(reflect_dot_eye, m.shininess));
	}
	res = add_3_tuples(ambient, l.diff, l.spec);
	return (res);
}
