/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:12:44 by avedrenn          #+#    #+#             */
/*   Updated: 2023/09/25 14:08:48 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	ft_error_parse(char *error, t_data *data, t_list *buf)
{
	ft_putstr_fd("Error\n❌ ", 2);
	ft_putstr_fd(error, 2);
	ft_free_parse(data, buf);
	exit(1);
}

int	ft_arrlen(void **array)
{
	int	i;

	i = 0;
	if (!array)
		return (i);
	while (array[i])
		i++;
	return (i);
}

int	ft_free_arr(void **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (2);
}

void	ft_free_parse(t_data *data, t_list *buf)
{
	if (buf)
	{
		ft_lstclear(&buf, free);
		free (buf);
	}
	if (data)
	{
		if (data->world.objs)
			ft_lstclear(&data->world.objs, free);
		if (data->rt_file > 2)
			close(data->rt_file);
	}
}

void	ft_replace(char *str, char old, char new)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == old)
		{
			str[i] = new;
		}
		i++;
	}
}
