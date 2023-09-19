/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_forms.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:00 by avedrenn          #+#    #+#             */
/*   Updated: 2023/09/19 18:57:47 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project.h"

int	parse_forms(t_list *buf, t_data *data)
{
	t_list	*tmp;
	int		err;

	if (!buf)
		return (1);
	data->world.objs = NULL;
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

	if (shape == SPHERE || shape == PLANE)
		params = get_params_from_line(line, 4);
	else if (shape == CYLINDER)
		params = get_params_from_line(line, 6);
	if (!params)
		return (1);
	new_obj = init_fill_obj(params, shape);
	if (!new_obj)
		return (1);
	new_elem = ft_lstnew((void *) new_obj);
	if (!new_elem)
	{
		free (new_obj);
		return (ft_free_arr((void **) params));
	}
	if (data->world.objs == NULL)
		data->world.objs = new_elem;
	else if (data->world.objs != NULL)
		ft_lstadd_back(&data->world.objs, new_elem);
	ft_free_arr((void **) params);
	return (0);
}

t_obj	*init_fill_obj(char **params, int shape)
{
	t_obj		*new_obj;
	int			err;
	static int	id = 0;

	err = 0;
	new_obj = ft_calloc(1, sizeof(t_obj));
	if (!new_obj)
	{
		ft_free_arr((void **) params);
		return (NULL);
	}
	if (shape == SPHERE)
		err = init_sp(params, new_obj);
	else if (shape == CYLINDER)
		err = init_cylinder(params, new_obj);
	else if (shape == PLANE)
		err = init_plane(params, new_obj);
	if (err)
	{
		free (new_obj);
		ft_free_arr((void **) params);
		return (NULL);
	}
	new_obj->id = id++;
	return (new_obj);
}

t_tuple	color_to_unit(t_tuple color)
{
	t_tuple	res;

	res.x = color.x / 255;
	res.y = color.y / 255;
	res.z = color.z / 255;
	return (res);
}
