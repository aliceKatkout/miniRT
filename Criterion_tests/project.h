/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:13:21 by mrabourd          #+#    #+#             */
/*   Updated: 2023/08/30 19:10:43 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECT_H
# define PROJECT_H

#include <stdio.h>
#include <stdlib.h>
# include <sys/stat.h>
# include "mlx_linux/mlx.h"
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
#include <math.h>

# define EPSILON 0.001
# define WINDOW_WIDTH 720	
# define WINDOW_HEIGHT 480

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

typedef struct s_projectile
{
	t_tuple	position;
	t_tuple	velocity;
}	t_projectile;

typedef struct s_env
{
	t_tuple	gravity;
	t_tuple	wind;
}	t_env;

typedef struct s_canvas
{
	int	w;
	int	h;
}	t_canvas;

typedef struct s_image
{
	void	*image;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_image	img;
	// t_projectile	proj;
	// t_env	env;
	t_canvas	canvas;
}	t_data;

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
t_tuple	normalize(t_tuple vec);
double	dot_product(t_tuple a, t_tuple b);
t_tuple	cross_product(t_tuple a, t_tuple b);

/* PRINT ON CANVAS */
t_tuple	create_color(double red, double green, double blue);
t_tuple	mult_colors(t_tuple a, t_tuple b);

void	write_pix_canvas(t_canvas canvas, int x, int y, t_tuple color);

void	render_background(t_image *img, int color);
void	render_map(t_data *data);
void	img_pxl_put(t_image *img, int x, int y, int color);
int		render(t_data *data);
void	init_canvas(t_data *data);

/* HOOK */
int	handle_keypress(int keysym, t_data *data);
// int	handle_mouse(int button, int x, int y, t_data *data);

/* EXIT */
int	ft_free_all(t_data *data);

#endif