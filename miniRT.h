/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:39:08 by avedrenn          #+#    #+#             */
/*   Updated: 2023/08/08 17:00:45 by mrabourd         ###   ########.fr       */
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

typedef struct s_form
{
	//
} t_form;

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
	t_form		form;

} t_scene;

void	print_list_prefix(t_list *lst, char *prefix);
void	parse_scene(char *argv, t_scene *scene);

void    parse_env(t_scene *scene, t_list *buf);

double  ft_atof(char *str);

void	ft_error(char *error);

#endif