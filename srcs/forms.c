/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:52:54 by avedrenn          #+#    #+#             */
/*   Updated: 2023/09/19 14:06:38 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

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
			err = create_plane((char *) tmp->content, data);
		else if (!ft_strncmp((char *) tmp->content, "sp ", 3))
			err = create_obj((char *) tmp->content, data);
		else if (!ft_strncmp((char *) tmp->content, "cy  ", 3))
			err = create_cylinder((char *) tmp->content, data);
		if (err)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	create_plane(char *line, t_scene *scene)
{
	char	**params;
	t_plane	*new;
	t_list		*new_elem;

	params = get_params_from_line(line, 4);
	if (!params)
		return (1);
	new = malloc(sizeof(t_plane));
	if (!new)
		return (ft_free_arr((void **) params));
	if (init_plane(params, new))
	{
		free (new);
		return (ft_free_arr((void **) params));
	}
	new_elem = ft_lstnew((void *) new);
	if (!new_elem)
	{
		free (new);
		return (ft_free_arr((void **) params));
	}
	ft_lstadd_back(&scene->planes, new_elem);
	ft_free_arr((void **) params);
	return (0);
}

int	create_obj(char *line, t_scene *scene)
{
	char		**params;
	t_obj		*new_sp;
	t_list		*new_elem;

	params = get_params_from_line(line, 4);
	if (!params)
		return (1);
	new_sp = malloc(sizeof(t_obj));
	if (!new_sp)
		return (ft_free_arr((void **) params));
	if (init_obj(params, new_sp))
	{
		free (new_sp);
		return (ft_free_arr((void **) params));
	}
	new_elem = ft_lstnew((void *) new_sp);
	if (!new_elem)
	{
		free (new_sp);
		return (ft_free_arr((void **) params));
	}
	ft_lstadd_back(&scene->objs, new_elem);
	ft_free_arr((void **) params);
	return (0);
}



int	create_cylinder(char *line, t_scene *scene)
{
	char		**params;
	t_cylinder	*new_cy;
	t_list		*new_elem;

	params = get_params_from_line(line, 6);
	if (!params)
		return (1);
	new_cy = malloc(sizeof(t_cylinder));
	if (!new_cy)
		return (ft_free_arr((void **) params));
	if (init_cylinder(params, new_cy))
	{
		free (new_cy);
		return (ft_free_arr((void **) params));
	}
	new_elem = ft_lstnew((void *) new_cy);
	if (!new_elem)
	{
		free (new_cy);
		return (ft_free_arr((void **) params));
	}
	ft_lstadd_back(&scene->cylinders, new_elem);
	ft_free_arr((void **) params);
	return (0);
}
