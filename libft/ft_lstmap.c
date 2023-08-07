/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:49:12 by avedrenn          #+#    #+#             */
/*   Updated: 2022/11/09 17:50:48 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*first;

	if (!lst || !(f))
		return (NULL);
	first = ft_lstnew((f)(lst->content));
	if (!first)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		new = ft_lstnew((f)(lst->content));
		if (!new)
		{
			ft_lstclear(&first, (del));
			return (NULL);
		}
		ft_lstadd_back(&first, new);
		lst = lst->next;
	}
	return (first);
}
