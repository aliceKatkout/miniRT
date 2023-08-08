/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:52:54 by avedrenn          #+#    #+#             */
/*   Updated: 2023/08/08 17:08:56 by avedrenn         ###   ########.fr       */
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
	
}

int	create_sphere(char *line, t_scene *scene)
{
	char 		**params;
	int			params_nb;
	t_sphere	*new_sp;

	params = ft_split(line, 32);
	if (!params)
		ft_error("Split hasn't splitted correctly.\n");
	params_nb = ft_arrlen(params);
	if (params_nb != 4)
	{
		free (params);
		ft_error("Invalid number of parameters for creating sphere.\n");
	}
	new_sp = malloc(sizeof(t_sphere));
	if (!new_sp)
		//error
	set_diameter(new_sp, params[2]);
	
	if (!scene->spheres)

	
	
}

void	set_diameter(t_sphere *sp, char	*param)
{

}

int	create_cylinder(char *line, t_scene *scene)
{
	
}