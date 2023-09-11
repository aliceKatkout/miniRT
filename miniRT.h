/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*  Created: 2023/08/07 16:39:08 by avedrenn          #+#    #+#             */
/*   Updated: 2023/08/11 12:20:14 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <limits.h>

//# include "mlx.h"
# include "libft/libft.h"

# define PI 3.14159265358979323846

typedef struct s_obj
{
	int		id;
	double	x;
	double	y;
	double	z;
	double diameter;
	int		r;
	int		g;
	int		b;
} t_obj;

typedef struct s_plane
{
	int		id;
	double	x;
	double	y;
	double	z;
	double	x_v;
	double	y_v;
	double	z_v;
	int		r;
	int		g;
	int		b;
} t_plane;

typedef struct s_cylinder
{
	int		id;
	double	x;
	double	y;
	double	z;
	double	x_v;
	double	y_v;
	double	z_v;
	double 	diameter;
	double	height;
	int		r;
	int		g;
	int		b;

} t_cylinder;

typedef struct s_cam
{
	double	x_view;
	double	y_view;
	double	z_view;
	double	x_vector;
	double	y_vector;
	double	z_vector;
	int		fov;
} t_cam;

typedef struct s_amb
{
	double	lighting;
	int		r;
	int		g;
	int		b;
} t_amb;

typedef struct s_light
{
	double	x;
	double	y;
	double	z;
	double	brightness;
} t_light;

typedef struct s_env
{
	t_cam		cam;
	t_amb		amb;
	t_light		light;
} t_env;

typedef struct s_scene
{
	int			rt_file;
	t_env		env;
	t_list		*objs;
	t_list		*cylinders;
	t_list		*planes;

} t_scene;


/* PRINT TEST - to remove */
void	print_cam(t_cam *cam);
void	print_amb(t_amb *amb);
void	print_light(t_light *light);
/* END */

void	init_scene(t_scene *scene);
void	print_list_prefix(t_list *lst, char *prefix);
void	parse_scene(char *argv, t_scene *scene);

int	    parse_env(t_scene *scene, t_list *buf);

double  ft_atof(char *str);

void	ft_error_parse(char *error, t_scene *s, t_list *buf);
int 	ft_arrlen(void **array);
int		ft_free_arr(void **array);
void	ft_free_parse(t_scene *s, t_list *buf);
void	ft_error(char *error);

int		parse_forms(t_list *buf, t_scene *scene);
int		create_plane(char *line, t_scene *scene);
int		create_obj(char *line, t_scene *scene);
int		create_cylinder(char *line, t_scene *scene);

int		init_obj(char **params, t_obj	*sp);
int		init_cylinder(char **params, t_cylinder	*sp);
int		init_plane(char **params, t_plane	*sp);

int		is_in_range(double val, double min, double max);
int		is_number(char *str);

double	set_diameter(char	*param);
char 	**get_params_from_line(char *line, int wanted_nb);
char	**check_rgb(char *line);
char	**check_vectors(char *line);
char	**get_new_params(char *line, int wanted_nb, char sep);

#endif