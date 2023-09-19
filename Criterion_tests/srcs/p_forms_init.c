/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_forms_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:28:28 by avedrenn          #+#    #+#             */
/*   Updated: 2023/09/19 15:38:17 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project.h"

int	init_rgb(t_obj *obj, char *param)
{
	char	**rgb;

	rgb = check_rgb(param);
	if (!rgb)
		return (1);
	obj->color = create_color(ft_atof(rgb[0]),
			ft_atof(rgb[1]), ft_atof(rgb[2]));
	ft_free_arr((void **)rgb);
	return (0);
}

int	init_xyz(t_obj *obj, char *param)
{
	char		**xyz;

	xyz = ft_split(param, ',');
	if (ft_arrlen((void **)xyz) != 3 || !is_number(xyz[0])
		|| !is_number(xyz[1]) || !is_number(xyz[2]))
		return (ft_free_arr((void **)xyz));
	obj->x = ft_atof(xyz[0]);
	obj->y = ft_atof(xyz[1]);
	obj->z = ft_atof(xyz[2]);
	ft_free_arr((void **)xyz);
	return (0);
}

int	init_sp(char **params, t_obj *sp)
{
	static int	id = 0;


	sp->id = id++;
	sp->shape = SPHERE;
	sp->diameter = set_diameter(params[2]);
	if (sp->diameter <= 0)
		return (ft_putstr_fdi("Sphere diameter is incorrect.\n", 2));
	if (init_xyz(sp, params[1]))
		return (1);
	if (init_rgb(sp, params[3]))
		return (1);
	sp->material = init_material();
	sp->transform = identity_matrix();
	return (0);
}

int	init_cylinder(char **params, t_obj	*cy)
{
	static int	id = 0;
	char		**vec;

	cy->id = id++;
	cy->shape = CYLINDER;
	if (set_diam_height_rad(params[3], params[4], cy))
		return (1);
	if (init_xyz(cy, params[1]))
		return (1);
	if (init_rgb(cy, params[5]))
		return (1);
	vec = check_vectors(params[2]);
	if (!vec)
		return (1);
	cy->direction = create_vector(ft_atof(vec[0]),
			ft_atof(vec[1]), ft_atof(vec[2]));
	ft_free_arr((void **)vec);
	cy->transform = identity_matrix();
	cy->material = init_material();
	return (0);
}

int	init_plane(char **params, t_obj	*pl)
{
	static int	id = 0;
	char		**vec;

	pl->id = id++;
	pl->shape = PLANE;
	if (init_xyz(pl, params[1]))
		return (1);
	if (init_rgb(pl, params[3]))
		return (1);
	vec = check_vectors(params[2]);
	if (!vec)
		return (1);
	pl->direction = create_vector(ft_atof(vec[0]),
			ft_atof(vec[1]), ft_atof(vec[2]));
	ft_free_arr((void **)vec);
	pl->transform = identity_matrix();
	return (0);
}
