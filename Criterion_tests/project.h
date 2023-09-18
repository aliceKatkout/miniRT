/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:13:21 by mrabourd          #+#    #+#             */
/*   Updated: 2023/09/18 17:45:32 by avedrenn         ###   ########.fr       */
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
# include "libft/libft.h"
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

# define EPSILON 0.0001
# define WINDOW_WIDTH 860
# define WINDOW_HEIGHT 640
# define PI 3.14159265359

# define SPHERE 1
# define PLANE 2
# define CYLINDER 3

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
	double	tab[4][4];
}	t_matrix_4;

typedef struct s_matrix_3
{
	double	tab[3][3];
}	t_matrix_3;

typedef struct s_matrix_2
{
	double	tab[2][2];
}	t_matrix_2;

typedef struct s_xs
{
	double			xs[4];
	double			t;
	int				count;
	struct s_obj	*obj;
}	t_xs;

typedef struct s_xs_world
{
	int		count;
	t_xs	tab_xs[100];
}	t_xs_world;

typedef struct s_light
{
	t_tuple	position;
	t_tuple	intensity;
}	t_light;

typedef struct s_material
{
	t_tuple	color;
	double	ambient;
	double	diffuse;
	double	specular;
	double	shininess;
} t_material;

typedef struct s_obj
{
	int			id;
	int			shape;
	t_matrix_4	transform;
	double		x;
	double		y;
	double		z;
	double		radius;
	double		diameter;
	double		min;
	double		max;
	int			closed;
	t_material	material;
	t_tuple 	color;
	t_ray		saved_ray;
}	t_obj;

typedef struct s_world
{
	t_light		light;
	t_list		*objs;

} t_world;

typedef struct s_comp
{
	double		t;
	t_obj		*obj;
	t_tuple		point;
	t_tuple		over_point;
	t_tuple		eyev;
	t_tuple		normalv;
	t_tuple		reflectv;
	int			inside;
} t_comp;

typedef struct s_intersection
{
	double		t;
	t_obj	*s;
}	t_intersection;

typedef struct s_cam
{
	double		hsize;
	double		vsize;
	double		fov;
	double		pixel_size;
	double		half_width;
	double		half_height;
	t_matrix_4	transform;
}	t_cam;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_world			world;
	t_cam			cam;
	t_image			img;
}	t_data;



void print_matrix_4(t_matrix_4 a);

/* TUPLES CREATE */
t_tuple		create_point(double x, double y, double z);
t_tuple		create_vector(double x, double y, double z);
t_tuple		create_tuple(double x, double y, double z, double w);
int			tuples_cmp(t_tuple a, t_tuple b);
t_tuple		reverse_tuple(t_tuple a);

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
t_tuple		color_at(t_world w, t_ray r);
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
t_matrix_4	create_matrix_4(double tab[16]);
t_matrix_3	create_matrix_3(double tab[9]);
t_matrix_2	create_matrix_2(double tab[4]);
double		matrix_cmp_4(t_matrix_4 a, t_matrix_4 b);

/* MATRIX OPERATIONS */
t_matrix_4	matrix_mult_4(t_matrix_4 a, t_matrix_4 b);
t_tuple		matrix_mult_tuple(t_matrix_4 a, t_tuple point);
t_matrix_4	identity_matrix(void);
t_matrix_4	transpose_mat(t_matrix_4 mat);

/* SUBMATRICES */
double			determine_two(t_matrix_2 a);
double			determine_three(t_matrix_3 a);
double			determine_four(t_matrix_4 a);

t_matrix_2	submatrix_3(t_matrix_3 a, int row, int col);
t_matrix_3	submatrix_4(t_matrix_4 a, int row, int col);
double			minor_3(t_matrix_3 a, int row, int col);
double			cofactor_3(t_matrix_3 a, int row, int col);

double			minor_4(t_matrix_4 a, int row, int col);
double 		cofactor_4(t_matrix_4 a, int row, int col);

/* MATRIX INVERSION */
int			is_invertible(t_matrix_4 a);
t_matrix_4	mat_inversion_4(t_matrix_4 a);

/* MATRIX TRANSFORMATIONS */
t_matrix_4	translation(double x, double y, double z);
t_matrix_4	scaling(double x, double y, double z);

/* MATRIX ROTATIONS */
t_matrix_4	rotation_x(double rad);
t_matrix_4	rotation_y(double rad);
t_matrix_4	rotation_z(double rad);

t_matrix_4	shearing(double xy, double xz, double yx, double yz, double zx, double zy);

/* RAYS */
t_ray		create_ray(t_tuple origin, t_tuple direction);
t_tuple		position(t_ray sray, double t);
t_ray	transform_ray(t_ray r, t_matrix_4 m);
t_intersection	create_intersection(double t, t_obj *s);

/* OBJS */
t_obj	*void_obj(void);
t_obj	*void_plane(void);
void	set_transform(t_obj *s, t_matrix_4 m);

/* LIGHTS */
t_tuple		normal_at(t_obj *obj, t_tuple p);
t_tuple	reflect(t_tuple in, t_tuple normal);
t_light	point_light(t_tuple position, t_tuple intensity);
t_material	init_material(void);
t_tuple	lighting(t_material m, t_comp comp, t_light l, int in_shadow);

/* WORLD */
t_world		create_world(void);
t_world		default_world(void);
t_xs_world	intersect_world(t_world w, t_ray r);
void		sort_list(t_xs_world *xs_world);

/* INTERSECTIONS */



void	find_hit(t_xs *xs);
t_xs	intersect(t_obj *obj, t_ray ray);
t_xs	intersect_sphere(t_obj *s, t_ray r);
t_xs	intersect_plane(t_obj *obj, t_ray r);


/* SHADOW */
t_comp		prepare_comp(t_xs xs, t_ray r);
t_tuple		shade_hit(t_world w, t_comp	comp);
int			is_shadowed(t_world world, t_tuple point);

/* CAMERA */
t_cam		create_camera(double hsize, double vsize, double fov);
t_ray		ray_for_pixel(t_cam c, int px, int py);
t_matrix_4	view_transform(t_tuple from, t_tuple to, t_tuple up);

/* CYLINDERS */
t_obj	*void_cylinder(void);
t_tuple	normal_at_cylinder(t_obj *cyl, t_tuple point);
t_xs	intersect_cylinder(t_obj *obj, t_ray r);
void	find_xs_cylinder(t_xs *xs, t_obj *obj, t_ray r);
double	check_cap(t_ray ray, double t);
void 	intersect_caps(t_obj *obj, t_ray r, t_xs *xs);
void	find_hit_cylinder(t_xs *xs);

/* EXIT */
int			ft_free_all(t_data *data);

void	ft_swap_double(double	*a, double	*b);
void	ft_sort_double_tab(double *tab, int size);

#endif