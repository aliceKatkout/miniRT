/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:03:44 by mrabourd          #+#    #+#             */
/*   Updated: 2023/09/18 19:07:54 by mrabourd         ###   ########.fr       */
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

/*It expects five arguments:
-the material itself,
-the point being illuminated,
-the light source
-the eye
-and normal vectors from thePhong reflection model.*/
t_tuple	lighting(t_material m, t_comp comp, t_light l, int in_shadow)
{
	t_tuple	eff_color;
	t_tuple	lightv;
	t_tuple	ambient;
	double	light_dot_normal;
	t_tuple	diff;
	t_tuple	spec;
	t_tuple	reflectv;
	double	reflect_dot_eye;
	double	factor;
	t_tuple	res;

	eff_color = mult_colors(m.color, l.intensity);
	lightv = normalize(sub_tuples(l.position, comp.point));
	ambient = mult_tuples(eff_color, m.ambient);
	light_dot_normal = dot_product(lightv, comp.normalv);
	if (light_dot_normal < 0 || in_shadow == 1)
	{
		diff = create_color(0, 0, 0);
		spec = create_color(0, 0, 0);
	}
	else
	{
		diff = mult_tuples(eff_color, m.diffuse);
		diff = mult_tuples(diff, light_dot_normal);
		lightv = reverse_tuple(lightv);
		reflectv = reflect(lightv, comp.normalv);
		reflect_dot_eye = dot_product(reflectv, comp.eyev);
		if (reflect_dot_eye <= 0)
			spec = create_color(0, 0, 0);
		else
		{
			factor = pow(reflect_dot_eye, m.shininess);
			spec = mult_tuples(l.intensity, m.specular);
			spec = mult_tuples(spec, factor);
		}
	}
	res = add_tuples(ambient, diff);
	res = add_tuples(res, spec);
	return (res);
}
