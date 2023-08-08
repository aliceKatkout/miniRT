/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:52:54 by avedrenn          #+#    #+#             */
/*   Updated: 2023/08/08 20:38:23 by avedrenn         ###   ########.fr       */
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
		printf("oh non\n");
	return (0);
	
}

int	create_sphere(char *line, t_scene *scene)
{
	char 		**params;
	int			params_nb;
	t_sphere	*new_sp;

	params = ft_split(line, 32);
	if (!params)
		ft_error("Split hasn't splitted correctly.\n");
	params_nb = ft_arrlen((void **) params);
	if (params_nb != 4)
	{
		free (params);
		ft_error("Invalid number of parameters for creating sphere.\n");
	}
	new_sp = malloc(sizeof(t_sphere));
	if (!new_sp)
		printf("error\n");
	new_sp->diameter = set_diameter(params[2]);
	
	if (!scene->spheres)
		printf("error\n");
	
	return (0);
}

double	set_diameter(char	*param)
{
	double	diameter;

	diameter = ft_atof(param);
	printf("%f", diameter);
	diameter = 1;
	if (diameter <= 0)
	{
		ft_error("Problem\n");
		return (-1);
	}
	else
		return (diameter);
	// if in range
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
		free (params);
		ft_error("Invalid number of parameters for creating cylinder.\n");
	}
	new_cy = malloc(sizeof(t_cylinder));
	if (!new_cy)
		printf("error\n");
	new_cy->diameter = set_diameter(params[2]);	
	if (!scene->cylinders)
		printf("error\n");
	printf("Coucou cylinder\n");

	return (0);
}