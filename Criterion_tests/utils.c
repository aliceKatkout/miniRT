#include "project.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*s;

	if (nmemb == 0 || size == 0)
	{
		s = malloc(1);
		if (s == 0)
			return (0);
		s[0] = 0;
	}
	if (nmemb > 2147483647 || size > 2147483647 || size * nmemb > 2147483647)
		return (0);
	s = malloc(size * nmemb);
	if (s == 0)
		return (0);
	ft_bzero(s, (size * nmemb));
	return (s);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	if (!content)
		return (NULL);
	new = malloc (sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = *lst;
	if (!new)
		return ;
	if (*lst)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*lst = new;
}
