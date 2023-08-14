/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:14:03 by mrabourd          #+#    #+#             */
/*   Updated: 2023/08/14 16:02:21 by mrabourd         ###   ########.fr       */
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
	char	**vec;
    char	**param;

	param = get_new_params(info[1], 3, ',');
	if (!param)
		return (1);
	scene->env.cam.x_view = ft_atof(param[0]);
	scene->env.cam.y_view = ft_atof(param[1]);
	scene->env.cam.z_view = ft_atof(param[2]);
	ft_free_arr((void **) param);
	vec = check_vectors(info[2]);
    if (!vec)
    {
        ft_free_arr((void **)info);
        return (1);
    }
	scene->env.cam.x_vector = ft_atof(vec[0]);
	scene->env.cam.y_vector = ft_atof(vec[1]);
	scene->env.cam.z_vector = ft_atof(vec[2]);
	scene->env.cam.fov = ft_atoi(info[3]);
	ft_free_arr((void **) vec);
	// print_cam(&scene->env.cam);
	return (0);
}

int		create_cam(char *line, t_scene *scene)
{
    char    **info;

	info = get_params_from_line(line, 4);
	if (!info)
		return (1);
	ft_bzero((void *)&scene->env.cam, sizeof(t_cam));
	if (init_cam(scene, info))
		return (1);
	ft_free_arr((void **) info);
	return (0);
}

int	create_amb(char *line, t_scene *scene)
{
    char    **info;
	char	**param;

	info = get_params_from_line(line, 3);
	if (!info)
		return (1);
	scene->env.amb.lighting = ft_atof(info[1]);
    param = check_rgb(info[2]);
    if (!param)
    {
        ft_free_arr((void **)info);
		return (1);
    }
	scene->env.amb.r = ft_atoi(param[0]);
	scene->env.amb.g = ft_atoi(param[1]);
	scene->env.amb.b = ft_atoi(param[2]);
	ft_free_arr((void **) param);
	ft_free_arr((void **) info);
	// print_amb(&scene->env.amb);
	return (0);
}

int	create_light(char *line, t_scene *scene)
{
	char	**info;
	char	**param;
	int		nb_info;

	info = ft_split(line, 32);
	if (!info)
		return (1);
	nb_info = ft_arrlen((void **) info);
	if (nb_info < 3 || nb_info > 4)
	{
		ft_free_arr((void **) info);
		return (1);
	}
	param = get_new_params(info[1], 3, ',');
	if (!param)
		return (1);
	scene->env.light.x = ft_atof(param[0]);
	scene->env.light.y = ft_atof(param[1]);
	scene->env.light.z = ft_atof(param[2]);
	ft_free_arr((void **) param);
	scene->env.light.brightness = ft_atof(info[2]);
	ft_free_arr((void **) info);
	// print_light(&scene->env.light);
	return (0);
}

int     check_nb_env(t_list *current, char *c)
{
    t_list  *tmp;

    tmp = current;
    while(tmp)
    {
        tmp = tmp->next;
        if (tmp && ft_strncmp(tmp->content, c, 1) == 0)
            return (1);
    }
    return (0);
}

int    parse_env(t_scene *scene, t_list *buf)
{
    t_list  *tmp;
	int		err;
    
	if (!buf)
		return (1);
    tmp = buf;
	err = 0;
    while(tmp)
    {
		if (ft_strncmp(tmp->content, "C", 1) == 0)
        {
			err = create_cam(tmp->content, scene);
            err = check_nb_env(tmp, "C");
        }
        if (ft_strncmp(tmp->content, "A", 1) == 0)
        {
			err = create_amb(tmp->content, scene);
            err = check_nb_env(tmp, "A");
        }
		if (ft_strncmp(tmp->content, "L", 1) == 0)
        {
			err = create_light(tmp->content, scene);
            err = check_nb_env(tmp, "L");
        }
		if (err)
			return (1);
        tmp = tmp->next;
    }
	return (0);
}