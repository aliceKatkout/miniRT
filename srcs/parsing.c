/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:53:38 by avedrenn          #+#    #+#             */
/*   Updated: 2023/08/07 18:25:09 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../miniRT.h"

void	parse_scene(char *argv, t_scene *scene)
{
	t_list	*buf;
	t_list	*tmp;

	if (ft_strncmp(argv + (ft_strlen(argv) - 3), ".rt", 3) != 0)
		printf("Scene given is not in .rt format.\n");
	scene->rt_file = open(argv, O_RDWR);
	if (scene->rt_file < 0)
		printf("Can't open scene.\n");
	buf = ft_lstnew((void *) get_next_line(scene->rt_file));
	if (!buf)
	{
		close(scene->rt_file);
		printf("Empty scene.\n");
	}
	tmp = buf;
	while (tmp)
	{
		ft_lstadd_back(&buf, ft_lstnew((void *) get_next_line(scene->rt_file)));
		tmp = tmp->next;
	}
	print_list_prefix(buf, NULL);
	//parse_forms();
	//parse_env();
	//free_buf;
	close(scene->rt_file);
}

void	print_list_prefix(t_list *lst, char *prefix)
{
	t_list	*tmp;

	if (!lst)
		printf("error : list is empty ...\n");
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