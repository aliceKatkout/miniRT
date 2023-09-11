/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:53:38 by avedrenn          #+#    #+#             */
/*   Updated: 2023/09/11 18:24:45 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	init_scene(t_scene *scene)
{
	/* scene->cylinders = ft_calloc(1, sizeof(t_list *));
	scene->planes = ft_calloc(1, sizeof(t_list *));
	scene->objs = ft_calloc(1, sizeof(t_list *)); */
	scene->objs = 0;
	scene->planes = 0;
	scene->cylinders = 0;
	scene->rt_file = -1;
}

void	parse_scene(char *argv, t_scene *scene)
{
	t_list	*buf;
	t_list	*tmp;

	if (ft_strncmp(argv + (ft_strlen(argv) - 3), ".rt", 3) != 0)
		ft_error_parse("Scene given is not in .rt format.\n", scene, NULL);
	scene->rt_file = open(argv, O_RDWR);
	if (scene->rt_file < 0)
		ft_error_parse("Can't open scene.\n", scene, NULL);
	buf = ft_lstnew((void *) get_next_line(scene->rt_file));
	if (!buf)
		ft_error_parse("Empty scene.\n", scene, NULL);
	tmp = buf;
	while (tmp)
	{
		ft_lstadd_back(&buf, ft_lstnew((void *) get_next_line(scene->rt_file)));
		tmp = tmp->next;
	}
	//print_list_prefix(buf, NULL);
	if (parse_forms(buf, scene))
		return (ft_error_parse("Occured when parsing forms.\n", scene, buf));
	if (parse_env(scene, buf))
		return (ft_error_parse("Occured when parsing env.\n", scene, buf));
	//free_buf;
	ft_lstclear(&buf, free);
	free (buf);
	close(scene->rt_file);
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
