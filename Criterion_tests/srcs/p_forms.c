/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_forms.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:00 by avedrenn          #+#    #+#             */
/*   Updated: 2023/09/19 15:03:54 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project.h"

int	parse_forms(t_list *buf, t_data *data)
{
	t_list	*tmp;
	int		err;

	if (!buf)
		return (1);
	tmp = buf;
	err = 0;
	while (tmp)
	{
		if (!ft_strncmp((char *) tmp->content, "pl ", 3))
			err = create_obj((char *) tmp->content, data, PLANE);
		else if (!ft_strncmp((char *) tmp->content, "sp ", 3))
			err = create_obj((char *) tmp->content, data, SPHERE);
		else if (!ft_strncmp((char *) tmp->content, "cy  ", 3))
			err = create_obj((char *) tmp->content, data, CYLINDER);
		if (err)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}


int	create_obj(char *line, t_data *data, int shape)
{
	char		**params;
	t_obj		*new_obj;
	t_list		*new_elem;
	int			err;

	if (shape == SPHERE || shape == PLANE)
		params = get_params_from_line(line, 4);
	else if (shape == CYLINDER)
		params = get_params_from_line(line, 6);
	if (!params)
		return (1);
	new_obj = ft_calloc(1, sizeof(t_obj));
	if (!new_obj)
		return (ft_free_arr((void **) params));
	if (shape == SPHERE)
		err = init_sp(params, new_obj);
	else if (shape == CYLINDER)
		err = init_cylinder(params, new_obj);
	else if (shape == PLANE)
		err = init_plane(params, new_obj);
	if (err)
	{
		free (new_obj);
		return (ft_free_arr((void **) params));
	}
	new_elem = ft_lstnew((void *) new_obj);
	if (!new_elem)
	{
		free (new_obj);
		return (ft_free_arr((void **) params));
	}
	ft_lstadd_back(data->world.objs, new_elem);
	ft_free_arr((void **) params);
	return (0);
}

int	init_sp(char **params, t_obj	*sp)
{
	static int	id = 0;
	char		**xyz;

	sp->id = id++;
	sp->shape = SPHERE;
	sp->diameter = set_diameter(params[2]);
	if (sp->diameter <= 0)
		return (ft_putstr_fdi("Sphere diameter is incorrect.\n", 2));
	xyz = ft_split(params[1], ',');
	if (ft_arrlen((void **)xyz) != 3 || !is_number(xyz[0])
		|| !is_number(xyz[1]) || !is_number(xyz[2]))
		return (ft_free_arr((void **)xyz));
	sp->x = ft_atof(xyz[0]);
	sp->y = ft_atof(xyz[1]);
	sp->z = ft_atof(xyz[2]);
	ft_free_arr((void **)xyz);
	if (init_rgb(sp, params[3]))
		return (1);
	sp->material = init_material();
	sp->transform = identity_matrix();
	return (0);
}

int	init_cylinder(char **params, t_obj	*cy)
{
	static int	id = 0;
	char		**xyz;
	char		**vec;

	cy->id = id++;
	if (set_diam_height_rad(params[3], params[4], cy))
		return (1);
	xyz = ft_split(params[1], ',');
	if (ft_arrlen((void **)xyz) != 3 || !is_number(xyz[0])
		|| !is_number(xyz[1]) || !is_number(xyz[2]))
		return (ft_free_arr((void **)xyz));
	cy->x = ft_atof(xyz[0]);
	cy->y = ft_atof(xyz[1]);
	cy->z = ft_atof(xyz[2]);
	ft_free_arr((void **)xyz);
	vec = check_vectors(params[2]);
	if (!vec)
		return (1);
	cy->direction = create_vector(ft_atof(vec[0]),
			ft_atof(vec[1]), ft_atof(vec[2]));
	ft_free_arr((void **)vec);
	if (init_rgb(cy, params[5]))
		return (1);
	cy->transform = identity_matrix();
	cy->material = init_material();
	return (0);
}

int	init_rgb(t_obj *obj, char **param)
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

int	init_plane(char **params, t_obj	*pl)
{
	static int	id = 0;
	char		**xyz;
	char		**vec;

	pl->id = id++;
	xyz = ft_split(params[1], ',');
	if (ft_arrlen((void **)xyz) != 3 || !is_number(xyz[0])
		|| !is_number(xyz[1]) || !is_number(xyz[2]))
		return (ft_free_arr((void **)xyz));
	pl->x = ft_atof(xyz[0]);
	pl->y = ft_atof(xyz[1]);
	pl->z = ft_atof(xyz[2]);
	ft_free_arr((void **)xyz);
	vec = check_vectors(params[2]);
	if (!vec)
		return (ft_free_arr((void **)xyz));
	pl->direction = create_vector(ft_atof(vec[0]),
			ft_atof(vec[1]), ft_atof(vec[2]));
	pl->transform = identity_matrix();
	ft_free_arr((void **)vec);
	if (init_rgb(pl, params[3]))
		return (1);
	return (0);
}