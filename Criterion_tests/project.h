/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:13:21 by mrabourd          #+#    #+#             */
/*   Updated: 2023/08/28 18:33:25 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/* OPERATIONS */
t_tuple	add_tuples(t_tuple a, t_tuple b);
t_tuple	sub_tuples(t_tuple a, t_tuple b);
t_tuple	neg_tuples(t_tuple a);
t_tuple	mult_tuples(t_tuple a, double vec);
t_tuple	div_tuples(t_tuple a, double vec);

double	magn_tuple(t_tuple a);

#endif