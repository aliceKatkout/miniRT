/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:39:08 by avedrenn          #+#    #+#             */
/*   Updated: 2023/08/08 16:58:39 by avedrenn         ###   ########.fr       */
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

typedef struct s_sphere
{
	int		id;
	double	x;
	double	y;
	double	z;	
	double diameter;
	int		r;
	int		g;
	int		b;
} t_sphere;

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

typedef struct s_scene
{	
	int			rt_file;
	t_list		*spheres;
	t_list		*cylinders;
	t_list		*planes;

} t_scene;

void	init_scene(t_scene *scene);
void	print_list_prefix(t_list *lst, char *prefix);
void	parse_scene(char *argv, t_scene *scene);

void	ft_error(char *error);
int 	ft_arrlen(void **array);

int		parse_forms(t_list *buf, t_scene *scene);
int		create_plane(char *line, t_scene *scene);
int		create_sphere(char *line, t_scene *scene);
int		create_cylinder(char *line, t_scene *scene);

#endif