/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:53:38 by avedrenn          #+#    #+#             */
/*   Updated: 2023/09/26 15:58:51 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	init_scene(t_data *data)
{
	ft_bzero(&data->world.light, sizeof(data->world.light));
	ft_bzero(&data->cam, sizeof(data->cam));
	data->rt_file = -1;
}

void	get_map(t_list *buf, int file)
{
	t_list	*tmp;
	t_list	*new;

	ft_replace((char *)buf->content, '	', ' ');
	ft_replace((char *)buf->content, '\n', ' ');
	tmp = buf;
	while (tmp)
	{
		new = ft_lstnew((void *) get_next_line(file));
		if (new)
		{
			ft_replace((char *)new->content, '	', ' ');
			ft_replace((char *)new->content, '\n', ' ');
			ft_lstadd_back(&buf, new);
		}
		tmp = tmp->next;
	}
}

void	parse_scene(char *argv, t_data *data)
{
	t_list	*buf;

	if (ft_strncmp(argv + (ft_strlen(argv) - 3), ".rt", 3) != 0)
		ft_error_parse("Scene given is not in .rt format.\n", NULL, NULL);
	data->rt_file = open(argv, O_RDWR);
	if (data->rt_file < 0)
		ft_error_parse("Can't open scene.\n", NULL, NULL);
	buf = ft_lstnew((void *) get_next_line(data->rt_file));
	if (!buf)
	{
		close(data->rt_file);
		ft_error_parse("Empty scene.\n", NULL, NULL);
	}
	get_map(buf, data->rt_file);
	if (parse_forms(buf, data))
		return (ft_error_parse("Occured when parsing forms.\n", data, buf));
	if (parse_env(data, buf))
		return (ft_error_parse("Occured when parsing env.\n", data, buf));
	ft_lstclear(&buf, free);
	free (buf);
	close(data->rt_file);
}

void	print_list_prefix(t_list *lst, char *prefix)
{
	t_list	*tmp;

	if (!lst)
		return ;
	tmp = lst;
	while (tmp != NULL)
	{
		if (!prefix)
			printf("%s\n", (char *) tmp->content);
		else
			printf("%s %s\n", prefix, (char *) tmp->content);
		tmp = tmp->next;
	}
}
