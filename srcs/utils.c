/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:12:44 by avedrenn          #+#    #+#             */
/*   Updated: 2023/08/10 17:13:25 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	ft_error_parse(char *error, t_scene *s, t_list *buf)
{
	ft_putstr_fd("Error\n❌ ", 2);
	ft_putstr_fd(error, 2);
	ft_free_parse(s, buf);
	exit(1);
}

int	ft_arrlen(void **array)
{
	int	i;

	i = 0;
	if (!array)
		return (i);
	while (array[i])
		i ++;
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

void	ft_free_parse(t_scene *s, t_list *buf)
{
	if (s->rt_file > 2)
		close(s->rt_file);
	if (buf)
	{
		ft_lstclear(&buf, free);
		free (buf);
	}
	if (s->spheres)
		ft_lstclear(&s->spheres, free);
	if (s->cylinders)
		ft_lstclear(&s->cylinders, free);
	if (s->planes)
		ft_lstclear(&s->planes, free);
}
