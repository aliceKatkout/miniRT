/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:56:28 by mrabourd          #+#    #+#             */
/*   Updated: 2023/09/19 16:57:25 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project.h"

void	img_pxl_put(t_image *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_length + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
		{
			*pixel++ = (color >> i) & 0xFF;
		}
		else
		{
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		}
		i -= 8;
	}
}

void	render_background(t_image *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			img_pxl_put(img, j, i, color);
			j++;
		}
		i++;
	}
}

// void	print_list(t_world world)
// {
// 	t_list	*tmp;

// 	tmp = world.objs;
// 	while (tmp != NULL)
// 	{
// 		printf("obj: %s\n", tmp->content->type);
// 		tmp = tmp->next;
// 	}
// }

// void	set_scene(t_data *data)
// {
// 	t_obj	*floor;
// 	t_obj	*cylinder;
// 	//t_obj	*right_wall;
// 	t_obj	*middle;
// 	t_obj	*right;
// 	t_obj	*left;
// 	t_world w;
// 	t_list	*new;

// 	floor = void_plane();
// 	// floor->transform = scaling(10, 0.01, 10);
// 	floor->material = init_material();
// 	floor->material.color = create_color(1, 0.8, 0.8);
// 	floor->material.diffuse = 0.5;
// 	floor->material.specular = 0.8;
// 	w.objs = ft_lstnew((void *) floor);
// 	// ft_lstadd_back(&w.objs, new);
// 	cylinder = void_cylinder();
// 	cylinder->transform = matrix_mult_4(cylinder->transform, translation(-5, 0, 1));
// 	// cylinder->transform = matrix_mult_4(cylinder->transform, scaling(10, 0.01, 10));
// 	// cylinder->transform = matrix_mult_4(cylinder->transform, rotation_x(M_PI / 2));
// 	// cylinder->transform = matrix_mult_4(cylinder->transform, rotation_y(-(M_PI) / 4));
// 	cylinder->min = 0;
// 	cylinder->max = 1;
// 	cylinder->closed = 1;
// 	cylinder->transform = matrix_mult_4(cylinder->transform, translation(0, 0, 5));
// 	cylinder->material = init_material();
// 	cylinder->material.color = create_color(0, 1, 0.1);
// 	cylinder->material.diffuse = 0.7;
// 	cylinder->material.specular = 0.3;
// 	new = ft_lstnew((void *) cylinder);
// 	ft_lstadd_back(&w.objs, new); //SEFGAULT
// 	/* right_wall = void_obj();
// 	right_wall->transform = matrix_mult_4(right_wall->transform, translation(0, 0, 5));
// 	right_wall->transform = matrix_mult_4(right_wall->transform, rotation_y(M_PI / 4));
// 	right_wall->transform = matrix_mult_4(right_wall->transform, rotation_x(M_PI / 2));
// 	right_wall->transform = matrix_mult_4(right_wall->transform, scaling(10, 0.01, 10));
// 	right_wall->material = floor->material;
// 	new = ft_lstnew((void *) right_wall);
// 	ft_lstadd_back(&w.objs, new); */
// 	cylinder = void_cylinder();
// 	//cylinder->transform = matrix_mult_4(translation(-1.5, 0, 0), scaling(0.5, 1, 0.5));
// 	cylinder->closed = 1;
// 	cylinder->min = 0;
// 	cylinder->max = 1;
// 	cylinder->material = init_material();
// 	cylinder->material.color = create_color(1, 0.8, 0.1);
// 	cylinder->material.diffuse = 0.7;
// 	cylinder->material.specular = 0.9;

// 	new = ft_lstnew((void *) cylinder);
// 	ft_lstadd_back(&w.objs, new);

// 	middle = void_obj();
// 	middle->transform = translation(-0.5, 1, 0.5);
// 	middle->material = init_material();
// 	middle->material.color = create_color(0.1, 1, 0.5);
// 	middle->material.diffuse = 0.7;
// 	middle->material.specular = 0.3;
// 	new = ft_lstnew((void *) middle);
// 	ft_lstadd_back(&w.objs, new);
// 	right = void_obj();
// 	right->transform = matrix_mult_4(translation(1.5, 0.5, -0.5), scaling(0.5, 0.5, 0.5));
// 	right->material = init_material();
// 	right->material.color = create_color(0.5, 1, 0.1);
// 	right->material.diffuse = 0.7;
// 	right->material.specular = 0.3;
// 	new = ft_lstnew((void *) right);
// 	ft_lstadd_back(&w.objs, new);
// 	left = void_obj();
// 	left->transform = matrix_mult_4(translation(-1.5, 0.33, -0.75), scaling(0.33, 0.33, 0.33));
// 	left->material = init_material();
// 	left->material.color = create_color(1, 0.8, 0.1);
// 	left->material.diffuse = 0.7;
// 	left->material.specular = 0.3;
// 	new = ft_lstnew((void *) left);
// 	ft_lstadd_back(&w.objs, new);
// 	data->world = w;
// 	// print_list(data->world);
// }

void	print_objects_list(t_list *lst)
{
	t_list	*tmp;
	t_obj	*obj;

	tmp = lst;
	while (tmp != NULL)
	{
		obj = (t_obj *) tmp->content;
		printf("obj id:%d\n", obj->id);
		printf("obj shape : %d\n", obj->shape);
		if (obj->shape == SPHERE)
		{
			printf("obj diameter :%f\n", obj->diameter);
		}
		printf("obj color x:%f\n", obj->material.color.x);
		printf("obj color y:%f\n", obj->material.color.y);
		printf("obj color z:%f\n", obj->material.color.z);
		printf("obj x:%f\n", obj->x);
		printf("obj y:%f\n", obj->y);
		printf("obj z:%f\n", obj->z);
		printf("obj closed:%d\n", obj->closed);

		tmp = tmp->next;
	}
}

void	render_map(t_data *data)
{
	t_ray	ray;
	int x;
	int y;
	t_tuple	color;
//	int	world_x;
	//int	world_y;
	// t_tuple	eye;
	// t_tuple	normal;

	printf("cam fov: %f\n", data->cam.fov);
	printf("cam orientation.x: %f\n", data->cam.orientation.x);
	printf("cam orientation.y: %f\n", data->cam.orientation.y);
	printf("cam orientation.z: %f\n", data->cam.orientation.z);
	// printf("world.lightcolor.x: %f\n", data->world.light.intensity.x);
	// printf("world.lightcolor.y: %f\n", data->world.light.intensity.y);
	// printf("world.lightcolor.z: %f\n", data->world.light.intensity.z);
	//set_scene(data);

	print_objects_list(data->world.objs);
	x = 0;
	y = 0;
	render_background(&data->img, 0x000000);
	printf("coucou\n");
	t_light	light;
	light.position = create_point(-3, 4, -5);
	light.intensity = create_color (1, 1, 1);
	data->world.light = light;
	//data->cam = create_camera(WINDOW_WIDTH, WINDOW_HEIGHT, M_PI / 3);
	while (y < data->cam.hsize)
	{
		x = 0;
		//world_y = data->cam.hsize - (y * 2);
		while (x < data->cam.vsize)
		{
			//world_x = -data->cam.vsize + (x * 2);
			ray = ray_for_pixel(data->cam, x, y);
			color = color_at(data->world, ray);
			// printf("color.x: %f\n", color.x);
			img_pxl_put(&data->img, x, y, transform_color(color));
			x++;
		}
		y++;
	}
	// printf("obj color x:%f\n", obj->material.color.x);
	// printf("obj color y:%f\n", obj->material.color.y);
	// printf("obj color z:%f\n", obj->material.color.z);
	printf("Done!\n");
}

int	render(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.image, 0, 0);
	return (0);
}

void	init_canvas(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return ;
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT, "project");
	if (data->win_ptr == NULL)
		return ;
	data->img.image = mlx_new_image(data->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.image,
			&data->img.bpp, &data->img.line_length, &data->img.endian);
	if (data->win_ptr != NULL)
		render_map(data);
	mlx_loop_hook(data->mlx_ptr, &render, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	// mlx_hook(data->win_ptr, 2, 1, &handle_keypress, data);
	mlx_hook(data->win_ptr, 17, 0, &ft_free_all, data);
	mlx_loop(data->mlx_ptr);
}
