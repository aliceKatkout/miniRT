/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:14:03 by mrabourd          #+#    #+#             */
/*   Updated: 2023/08/10 15:27:55 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../miniRT.h"

void    ft_print_info(char **info)
{
    int i;

    i = 0;
    while(info[i])
    {
        printf("info[%d]: %s\n", i, info[i]);
        i++;
    }
}

int		init_cam(t_scene *scene, char **info)
{
	char	**param;
	int		nb_info;

	param = ft_split(info[1], ',');
	if (!param)
	{
		ft_error("Split hasn't splitted correctly.\n");
		return (1);
	}
	nb_info = ft_arrlen((void **) param);
	if (nb_info != 3)
	{
		ft_free_arr((void **) param);
		ft_error("Invalid number of views for creating camera.\n");
		return (1);
	}
	scene->env.cam.x_view = ft_atof(param[0]);
	scene->env.cam.y_view = ft_atof(param[1]);
	scene->env.cam.z_view = ft_atof(param[2]);
	ft_free_arr((void **) param);
	param = ft_split(info[2], ',');
	if (!param)
		ft_error("Split hasn't splitted correctly.\n");
	scene->env.cam.x_vector = ft_atof(param[0]);
	scene->env.cam.y_vector = ft_atof(param[1]);
	scene->env.cam.z_vector = ft_atof(param[2]);
	scene->env.cam.fov = ft_atoi(info[3]);
	ft_free_arr((void **) param);
	return (0);
}

int		create_cam(char *line, t_scene *scene)
{
    char    **info;
	int		nb_info;

	info = ft_split(line, ' ');
    if (!info)
	{
		ft_error("Split hasn't splitted correctly.\n");
		return (1);
	}
	nb_info = ft_arrlen((void **) info);
	if (nb_info != 4)
	{
		ft_free_arr((void **) info);
		ft_error("Invalid number of parameters for creating camera.\n");
		return (1);
	}
	ft_bzero((void *)&scene->env.cam, sizeof(t_cam));
	if (init_cam(scene, info))
		return (1);
	ft_free_arr((void **) info);
	return (0);
}

void	create_amb(char *line, t_scene *scene)
{
    char    **info;
	char	**param;

	info = ft_split(line, ' ');
    if (!info)
		ft_error("Split hasn't splitted correctly.\n");
	scene->env.amb.lighting = ft_atof(info[1]);
	param = ft_split(info[2], ',');
	if (!param)
		ft_error("Split hasn't splitted correctly.\n");
	scene->env.amb.r = ft_atoi(param[0]);
	scene->env.amb.g = ft_atoi(param[1]);
	scene->env.amb.b = ft_atoi(param[2]);
	ft_free_arr((void **) param);
	ft_free_arr((void **) info);
}

void	create_light(char *line, t_scene *scene)
{
	char	**info;
	char	**param;

	info = ft_split(line, ' ');
	if (!info)
		ft_error("Split hasn't splitted correctly.\n");
	param = ft_split(info[1], ',');
	if (!param)
		ft_error("Split hasn't splitted correctly.\n");
	scene->env.light.x = ft_atof(param[0]);
	scene->env.light.y = ft_atof(param[1]);
	scene->env.light.z = ft_atof(param[2]);
	ft_free_arr((void **) param);
	scene->env.light.brightness = ft_atof(info[2]);
	ft_free_arr((void **) info);
}

void    parse_env(t_scene *scene, t_list *buf)
{
    t_list  *tmp;
    
	if (!buf)
		return ;
    tmp = buf;
    while(tmp)
    {
        if (ft_strncmp(tmp->content, "C", 1) == 0)
            create_cam(tmp->content, scene);
		if (ft_strncmp(tmp->content, "A", 1) == 0)
            create_amb(tmp->content, scene);
		if (ft_strncmp(tmp->content, "L", 1) == 0)
            create_light(tmp->content, scene);
		// ft_print_info(info);
        // check_info(scene, info);//checker si bon nombre d'elements dans info
        // scene->cam->x_view = ft_atof(info[1]);
        tmp = tmp->next;
    }
}