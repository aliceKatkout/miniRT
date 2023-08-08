/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:14:03 by mrabourd          #+#    #+#             */
/*   Updated: 2023/08/08 17:09:54 by mrabourd         ###   ########.fr       */
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

void    parse_env(t_scene *scene, t_list *buf)
{
    t_list  *tmp;
    int     i;
    char    **info;
    (void)scene;
    
    info = NULL;
    i = 0;
    tmp = buf;
    while(tmp)
    {
        if (ft_strncmp(tmp->content, "C", 1) == 0)
        {
            info = ft_split(tmp->content, ' ');
            ft_print_info(info);
        }
        // check_info(scene, info);//checker si bon nombre d'elements dans info
        // scene->cam->x_view = ft_atof(info[1]);
        i++;
    }
}