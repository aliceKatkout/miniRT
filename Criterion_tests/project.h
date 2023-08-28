#ifndef PROJECT_H
# define PROJECT_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

# define EPSILON 0.001

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_tuple;

typedef struct s_data
{
	t_tuple	*tuple;
}	t_data;

/* UTILS */
void	*ft_calloc(size_t nmemb, size_t size);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);

/* CREATE */
t_tuple	create_point(double x, double y, double z);
t_tuple	create_vector(double x, double y, double z);
int		tuples_cmp(t_tuple a, t_tuple b);
t_tuple	add_tuples(t_tuple a, t_tuple b);
t_tuple	sub_tuples(t_tuple a, t_tuple b);

#endif