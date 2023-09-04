/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:13:21 by mrabourd          #+#    #+#             */
/*   Updated: 2023/09/04 12:09:28 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECT_H
# define PROJECT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "mlx_linux/mlx.h"
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

# define EPSILON 0.0001
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

typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
}	t_ray;

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

typedef struct s_image
{
	void	*image;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_matrix_4
{
	float	tab[4][4];
}	t_matrix_4;

typedef struct s_matrix_3
{
	float	tab[3][3];
}	t_matrix_3;

typedef struct s_matrix_2
{
	float	tab[2][2];
}	t_matrix_2;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_image			img;
	t_projectile	proj;
	t_env			env;
}	t_data;

/* TUPLES CREATE */
t_tuple		create_point(double x, double y, double z);
t_tuple		create_vector(double x, double y, double z);
t_tuple		create_tuple(double x, double y, double z, double w);
int			tuples_cmp(t_tuple a, t_tuple b);

/* TUPLES OPERATIONS */
t_tuple		add_tuples(t_tuple a, t_tuple b);
t_tuple		sub_tuples(t_tuple a, t_tuple b);
t_tuple		neg_tuples(t_tuple a);
t_tuple		mult_tuples(t_tuple a, double vec);
t_tuple		div_tuples(t_tuple a, double vec);

double		magn_tuple(t_tuple a);
t_tuple		normalize(t_tuple vec);
double		dot_product(t_tuple a, t_tuple b);
t_tuple		cross_product(t_tuple a, t_tuple b);

/* PRINT ON CANVAS */
t_projectile	ft_tick(t_env env, t_projectile proj);
t_tuple		create_color(double red, double green, double blue);
t_tuple		mult_colors(t_tuple a, t_tuple b);
int			transform_color(t_tuple color);

/* FOR MLX */
void		render_background(t_image *img, int color);
void		render_map(t_data *data);
void		img_pxl_put(t_image *img, int x, int y, int color);
int			render(t_data *data);
void		init_canvas(t_data *data);

/* HOOK --- with MLX */
int			handle_keypress(int keysym, t_data *data);
// int	handle_mouse(int button, int x, int y, t_data *data);

/* MATRICES CREATE*/
t_matrix_4	create_matrix_4(float tab[16]);
t_matrix_3	create_matrix_3(float tab[9]);
t_matrix_2	create_matrix_2(float tab[4]);
double		matrix_cmp_4(t_matrix_4 a, t_matrix_4 b);

/* MATRIX OPERATIONS */
t_matrix_4	matrix_mult_4(t_matrix_4 a, t_matrix_4 b);
t_tuple		matrix_mult_tuple(t_matrix_4 a, t_tuple point);
t_matrix_4	identity_matrix(void);
t_matrix_4	transpose_mat(t_matrix_4 mat);

/* SUBMATRICES */
int			determine_two(t_matrix_2 a);
int			determine_three(t_matrix_3 a);
int			determine_four(t_matrix_4 a);

t_matrix_2	submatrix_3(t_matrix_3 a, int row, int col);
t_matrix_3	submatrix_4(t_matrix_4 a, int row, int col);
int			minor_3(t_matrix_3 a, int row, int col);
int			cofactor_3(t_matrix_3 a, int row, int col);

int			minor_4(t_matrix_4 a, int row, int col);
int			cofactor_4(t_matrix_4 a, int row, int col);

/* MATRIX INVERSION */
int			is_invertible(t_matrix_4 a);
t_matrix_4	mat_inversion_4(t_matrix_4 a);

/* MATRIX TRANSFORMATIONS */
t_matrix_4	translation(double x, double y, double z);
t_matrix_4	scaling(double x, double y, double z);

/* MATRIX ROTATIONS */
t_matrix_4	rotation_x(float rad);
t_matrix_4	rotation_y(float rad);
t_matrix_4	rotation_z(float rad);

t_matrix_4	shearing(float xy, float xz, float yx, float yz, float zx, float zy);

/* RAYS */
t_ray		create_ray(t_tuple origin, t_tuple direction);
t_tuple		position(t_ray sray, double t);

/* EXIT */
int			ft_free_all(t_data *data);

#endif