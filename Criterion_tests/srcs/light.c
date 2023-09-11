/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:03:44 by mrabourd          #+#    #+#             */
/*   Updated: 2023/09/11 14:40:11 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project.h"

t_tuple		normal_at(t_sphere *s, t_tuple p)
{
	t_tuple	obj_point;
	t_tuple	obj_normal;
	t_tuple	world_normal;
	t_matrix_4	inversion;
	t_matrix_4	m;

	// print_matrix_4(s->transform);
	inversion = mat_inversion_4(s->transform);
	obj_point = matrix_mult_tuple(inversion, p);
	obj_normal = sub_tuples(obj_point, create_point(0, 0, 0));
	m = mat_inversion_4(s->transform);
	m = transpose_mat(m);
	world_normal = matrix_mult_tuple(m, obj_normal);
	world_normal.w = 0;
	return (world_normal);
}

/*It expects five arguments: 
-the material itself, 
-the point being illuminated,
-the light source
-the eye 
-and normal vectors from thePhong reflection model.*/
t_tuple	lighting(t_material m, t_light l, t_tuple pos, t_tuple eyev, t_tuple normalv)
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
	printf("m.color.x : %f\n", m.color.x);
	printf("m.color.y : %f\n", m.color.y);
	printf("m.color.z : %f\n", m.color.z);
	lightv = normalize(sub_tuples(l.position, pos));
	ambient = mult_tuples(eff_color, m.ambient);
	light_dot_normal = dot_product(lightv, normalv);
	printf("light dot normal: %f\n", light_dot_normal);
	if (light_dot_normal < 0)
	{
		diff = create_color(0, 0, 0);
		spec = create_color(0, 0, 0);
	}
	else
	{
		diff = mult_tuples(eff_color, m.diffuse);
		diff = mult_tuples(diff, light_dot_normal);
		lightv = reverse_tuple(lightv);
		reflectv = reflect(lightv, normalv);
		reflect_dot_eye = dot_product(reflectv, eyev);
		if (reflect_dot_eye <= 0)
			spec = create_color(0, 0, 0);
		else
		{
			factor = pow(reflect_dot_eye, m.shininess);
			spec = mult_tuples(l.intensity, m.specular);
			spec = mult_tuples(spec, factor);
		}
	}
	(void) ambient;
	(void) spec;
	res = diff;
	//res = add_tuples(ambient, diff);
	//res = add_tuples(res, spec);
	return (res);
}
