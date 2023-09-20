/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:14:03 by mrabourd          #+#    #+#             */
/*   Updated: 2023/09/20 17:58:04 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project.h"

void	ft_print_info(char **info)
{
	int	i;

	i = 0;
	while (info[i])
	{
		printf("info[%d]: %s\n", i, info[i]);
		i++;
	}
}

int	check_nb_env(t_list *current)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = current;
	while (tmp)
	{
		tmp = tmp->next;
		if (tmp && (ft_strncmp(tmp->content, "C ", 2) == 0
				|| ft_strncmp(tmp->content, "A ", 2) == 0
				|| ft_strncmp(tmp->content, "L ", 2) == 0))
			i++;
	}
	if (i != 3)
		return (1);
	return (0);
}

int	parse_env(t_data *data, t_list *buf)
{
	t_list	*tmp;
	int		err;

	if (!buf || check_nb_env(buf))
		return (1);
	tmp = buf;
	err = 0;
	while (tmp)
	{
		if (ft_strncmp(tmp->content, "C", 1) == 0)
			err = parse_cam(tmp->content, data);
		if (ft_strncmp(tmp->content, "A", 1) == 0)
			err = create_amb(tmp->content, data);
		if (ft_strncmp(tmp->content, "L", 1) == 0)
			err = create_light(tmp->content, data);
		if (err)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
