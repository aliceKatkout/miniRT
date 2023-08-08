/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:52:54 by avedrenn          #+#    #+#             */
/*   Updated: 2023/08/08 23:36:14 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../miniRT.h"

int	parse_forms(t_list *buf, t_scene *scene)
{
	t_list	*tmp;

	if (!buf)
		return (1);
	tmp = buf;
	while (tmp)
	{
		if (!ft_strncmp((char *) tmp->content, "pl ", 3))
			create_plane((char *) tmp->content, scene);
		else if (!ft_strncmp((char *) tmp->content, "sp ", 3))
			create_sphere((char *) tmp->content, scene);
		else if (!ft_strncmp((char *) tmp->content, "cy  ", 3))
			create_cylinder((char *) tmp->content, scene);
		tmp = tmp->next;
	}
	return (0);
}

int	create_plane(char *line, t_scene *scene)
{
	char **params;

	params = ft_split(line, 32);
	if (!params)
		ft_error("Split hasn't splitted correctly.\n");

	if (!scene->planes)
		printf("houhou\n");
	ft_free_arr((void **) params);
	return (0);
	
}

int	create_sphere(char *line, t_scene *scene)
{
	char 		**params;
	int			params_nb;
	t_sphere	*new_sp;
	t_list		*new_elem;

	params = ft_split(line, 32);
	if (!params)
		ft_error("Split hasn't splitted correctly.\n");
	params_nb = ft_arrlen((void **) params);
	if (params_nb != 4)
	{
		ft_free_arr((void **) params);
		ft_error("Invalid number of parameters for creating sphere.\n");
	}
	new_sp = malloc(sizeof(t_sphere));
	if (!new_sp)
		printf("error sp\n");
	init_sphere(params, new_sp);
	new_elem = ft_lstnew((void *) new_sp);
	if (!new_elem)
		printf("error elem");
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
	xyz = ft_split(params[1], ',');
	if (ft_arrlen((void **)xyz) != 3 || !is_number(xyz[0]) || !is_number(xyz[1]) || !is_number(xyz[2]))
	{
		ft_error("Coordinates of a spĥere are incorrects.\n");
	}
	//protect
	sp->x = ft_atof(xyz[0]);
	sp->y = ft_atof(xyz[1]);
	sp->z = ft_atof(xyz[2]);
	params[3][ft_strlen(params[3]) - 1] = ',';
	rgb = ft_split(params[3], ',');
	if (ft_arrlen((void **)rgb) != 3 || !is_number(rgb[0]) || !is_number(rgb[1]) || !is_number(rgb[2]))
	{
		printf("rgb :%s", rgb[0]);
		printf("rgb :%s", rgb[1]);
		printf("rgb :%s", rgb[2]);
		ft_error("RGB must be numbers.\n");
	}
	//protect
	sp->r = ft_atof(rgb[0]);
	sp->g = ft_atof(rgb[1]);
	sp->b = ft_atof(rgb[2]);
	if (!is_in_range(sp->r, 0.0, 255.0) || !is_in_range(sp->b, 0.0, 255.0) || !is_in_range(sp->g, 0.0, 255.0))
	{
		ft_error("RGB must be numbers in range 0 to 255.\n");
	}
	return (0);
}

double	set_diameter(char	*param)
{
	double	diameter;

	diameter = ft_atof(param);
	if (diameter <= 0 || !is_number(param))
	{
		//free_all
		ft_error("Diameter must be a number superior to zero.\n");
		return (-1);
	}
	else
		return (diameter);
}



int	create_cylinder(char *line, t_scene *scene)
{
	char 		**params;
	int			params_nb;
	t_cylinder	*new_cy;

	params = ft_split(line, 32);
	if (!params)
		ft_error("Split hasn't splitted correctly.\n");
	params_nb = ft_arrlen((void **) params);
	if (params_nb != 6)
	{
		ft_free_arr((void **) params);
		ft_error("Invalid number of parameters for creating cylinder.\n");
	}
	new_cy = malloc(sizeof(t_cylinder));
	if (!new_cy)
		printf("error\n");
	//new_cy->diameter = set_diameter(params[2]);	
	if (!scene->cylinders)
		printf("Coucou cylinder\n");
	ft_free_arr((void **) params);
	return (0);
}