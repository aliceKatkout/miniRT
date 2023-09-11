/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:08:55 by avedrenn          #+#    #+#             */
/*   Updated: 2023/09/11 18:40:06 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project.h"

t_world	create_world()
{
	t_world	w;
	w.light = NULL;
	w.objs = NULL;
	return (w);
}

t_world	default_world()
{
	t_world	w;
	t_light	l;
	t_obj	*s1;
	t_obj	*s2;
	t_list	*new;

	w = create_world();
	l = point_light(create_point(-10, 10, -10), create_color(1, 1, 1));
	s1 = void_obj();
	s1->material.color = create_color(0.8, 1.0, 0.6);
	s1->material.diffuse = 0.7;
	s1->material.specular = 0.2;
	s2 = void_obj();
	s2->transform = scaling(0.5, 0.5, 0.5);
	w.light = &l;
	new = ft_lstnew((void *) s1);
	new->next = ft_lstnew((void *) s2);
	w.objs = new;
	return (w);
}