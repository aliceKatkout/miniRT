/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:14:03 by mrabourd          #+#    #+#             */
/*   Updated: 2023/09/25 16:18:48 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	check_nb_env(t_list *current)
{
	t_list	*tmp;
	int		a;
	int		l;
	int		c;

	a = 0;
	l = 0;
	c = 0;
	tmp = current;
	while (tmp)
	{
		if (tmp && (ft_strncmp(tmp->content, "C ", 2) == 0))
			c++;
		else if (tmp && (ft_strncmp(tmp->content, "A ", 2) == 0))
			a++;
		else if (tmp && (ft_strncmp(tmp->content, "L ", 2) == 0))
			l++;
		tmp = tmp->next;
	}
	if (a != 1 || l != 1 || c != 1)
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
