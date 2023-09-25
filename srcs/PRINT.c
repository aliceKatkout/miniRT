/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PRINT.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:20:20 by mrabourd          #+#    #+#             */
/*   Updated: 2023/09/25 14:08:54 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	print_objects_list(t_list *lst)
{
	t_list	*tmp;
	t_obj	*obj;

	tmp = lst;
	while (tmp != NULL)
	{
		obj = (t_obj *) tmp->content;
		printf("obj id:%d\n", obj->id);
		printf("obj shape : %d\n", obj->shape);
		if (obj->shape == SPHERE)
		{
			printf("obj diameter :%f\n", obj->diameter);
		}
		printf("obj color x:%f\n", obj->material.color.x);
		printf("obj color y:%f\n", obj->material.color.y);
		printf("obj color z:%f\n", obj->material.color.z);
		printf("obj x:%f\n", obj->x);
		printf("obj y:%f\n", obj->y);
		printf("obj z:%f\n", obj->z);
		printf("obj closed:%d\n", obj->closed);
		tmp = tmp->next;
	}
}

void	print_matrix(t_matrix_4 m)
{
	int	x;
	int	y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			printf("%f, ", m.tab[x][y]);
			y++;
		}
		printf("\n");
		x++;
	}
}
