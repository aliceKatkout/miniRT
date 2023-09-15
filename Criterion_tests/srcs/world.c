/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:08:55 by avedrenn          #+#    #+#             */
/*   Updated: 2023/09/15 15:29:53 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project.h"

t_world	create_world()
{
	t_world	w;
	//w.light = NULL;
	w.objs = NULL;
	return (w);
}

t_world	default_world()
{
	t_world	w;
	t_obj	*s1;
	t_obj	*s2;
	t_list	*new;

	w.light = point_light(create_point(-10, 10, -10), create_color(1, 1, 1));
	s1 = void_obj();
	s1->material.color = create_color(0.8, 1.0, 0.6);
	s1->material.diffuse = 0.7;
	s1->material.specular = 0.2;
	s2 = void_obj();
	s2->transform = scaling(0.5, 0.5, 0.5);
	new = ft_lstnew((void *) s1);
	new->next = ft_lstnew((void *) s2);
	w.objs = new;
	return (w);
}

void	sort_list(t_xs_world *xs_world)
{
	int		i;
	int		j;
	t_xs	tmp;

	i = 0;
	while (i < xs_world->count)
	{
		j = i + 1;
		while (j < xs_world->count)
		{
			if (xs_world->tab_xs[i].t > xs_world->tab_xs[j].t)
			{
				tmp = xs_world->tab_xs[i];
				xs_world->tab_xs[i] = xs_world->tab_xs[j];
				xs_world->tab_xs[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

t_xs_world	intersect_world(t_world w, t_ray r)
{
	t_list		*lst;
	t_obj		*obj;
	t_xs		xs;
	t_xs_world	xs_world;
	int			i;

	i = 0;
	xs_world.count = 0;
	lst = w.objs;
	while (lst)
	{
		obj = (t_obj *)lst->content;
		// printf("obj->id : %d\n", obj->id);
		xs = intersect(obj, r);
		if (xs.count > 0)
		{
			xs_world.tab_xs[i] = xs;
			xs_world.count++;
			i++;
		}
		lst = lst->next;
	}

	sort_list(&xs_world);
	// i = 0;
	// while (i < xs_world.count)
	// {
	// 	printf("xs_world.tab_xs[%d].t : %f\n", i, xs_world.tab_xs[i].t);
	// 	i++;
	// }
	return (xs_world);
}