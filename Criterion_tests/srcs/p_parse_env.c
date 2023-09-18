/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:14:03 by mrabourd          #+#    #+#             */
/*   Updated: 2023/09/18 16:43:47 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../project.h"

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

int    parse_env(t_data *data, t_list *buf)
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
			err = parse_cam(tmp->content, data);
            err = check_nb_env(tmp, "C");
        }
        // if (ft_strncmp(tmp->content, "A", 1) == 0)
        // {
		// 	err = create_amb(tmp->content, data);
        //     err = check_nb_env(tmp, "A");
        // }
		if (ft_strncmp(tmp->content, "L", 1) == 0)
        {
			err = create_light(tmp->content, data);
            err = check_nb_env(tmp, "L");
        }
		if (err)
			return (1);
        tmp = tmp->next;
    }
	return (0);
}