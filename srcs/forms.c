/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:52:54 by avedrenn          #+#    #+#             */
/*   Updated: 2023/08/10 16:51:25 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../miniRT.h"

int	parse_forms(t_list *buf, t_scene *scene)
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
			err = create_plane((char *) tmp->content, scene);
		else if (!ft_strncmp((char *) tmp->content, "sp ", 3))
			err = create_sphere((char *) tmp->content, scene);
		else if (!ft_strncmp((char *) tmp->content, "cy  ", 3))
			err = create_cylinder((char *) tmp->content, scene);
		if (err)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	create_plane(char *line, t_scene *scene)
{
	char **params;

	params = ft_split(line, 32);
	if (!params)
		return (ft_putstr_fdi("Split hasn't splitted correctly.\n", 2));

	if (!scene->planes)
		printf("houhou\n");
	ft_free_arr((void **) params);
	return (0);
	
}

int	create_sphere(char *line, t_scene *scene)
{
	char 		**params;
	t_sphere	*new_sp;
	t_list		*new_elem;

	params = get_params_from_line(line, 4);
	if (!params)
		return (1); 
	new_sp = malloc(sizeof(t_sphere));
	if (!new_sp)
	{
		ft_free_arr((void **) params);
		return (1);
	}
	if (init_sphere(params, new_sp))
	{
		ft_free_arr((void **) params);
		free (new_sp);
		return (1);
	}
	new_elem = ft_lstnew((void *) new_sp);
	if (!new_elem)
	{
		free (new_sp);
		ft_free_arr((void **) params);
		return (1);
	}
	ft_lstadd_back(&scene->spheres, new_elem);
	ft_free_arr((void **) params);
	return (0);
}

int	init_sphere(char **params, t_sphere	*sp)
{
	static int id = 0;
	char	**xyz;
	char	**rgb;

	sp->id = id++;
	sp->diameter = set_diameter(params[2]);
	if (sp->diameter <= 0)
		return (ft_putstr_fdi("Sphere diameter is incorrect.\n", 2)); // ou 1
	xyz = ft_split(params[1], ',');
	if (ft_arrlen((void **)xyz) != 3 || !is_number(xyz[0]) || !is_number(xyz[1]) || !is_number(xyz[2]))
		return(ft_free_arr((void **)xyz));
	sp->x = ft_atof(xyz[0]);
	sp->y = ft_atof(xyz[1]);
	sp->z = ft_atof(xyz[2]);
	rgb = check_rgb(params[3]);
	if (!rgb)
		return(ft_free_arr((void **)xyz));
	sp->r = ft_atof(rgb[0]);
	sp->g = ft_atof(rgb[1]);
	sp->b = ft_atof(rgb[2]);
	ft_free_arr((void **)xyz);
	ft_free_arr((void **)rgb);
	return (0);
}

double	set_diameter(char	*param)
{
	double	diameter;

	diameter = ft_atof(param);
	if (diameter <= 0 || !is_number(param))
		return (-1);
	else
		return (diameter);
}



int	create_cylinder(char *line, t_scene *scene)
{
	char 		**params;
	t_cylinder	*new_cy;

	params = ft_split(line, 32);
	if (!params)
		return (1); 
	
	//if (params_nb != 6)
	/* {
		ft_free_arr((void **) params);
		ft_error("Invalid number of parameters for creating cylinder.\n");
	} */
	new_cy = malloc(sizeof(t_cylinder));
	if (!new_cy)
		printf("error\n");
	//new_cy->diameter = set_diameter(params[2]);	
	if (!scene->cylinders)
		printf("Coucou cylinder\n");
	ft_free_arr((void **) params);
	return (0);
}

