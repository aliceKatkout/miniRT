/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:56:28 by mrabourd          #+#    #+#             */
/*   Updated: 2023/09/18 16:35:59 by mrabourd         ###   ########.fr       */
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

void	set_scene(t_data *data)
{
	t_obj	*floor;
	t_obj	*cylinder;
	//t_obj	*right_wall;
	t_obj	*middle;
	t_obj	*right;
	t_obj	*left;
	t_world w;
	t_list	*new;

	floor = void_plane();
	floor->transform = scaling(10, 0.01, 10);
	floor->material = init_material();
	floor->material.color = create_color(1, 0.9, 0.9);
	floor->material.specular = 0;
	w.objs = ft_lstnew((void *) floor);
	// ft_lstadd_back(&w.objs, new);
	cylinder = void_cylinder();
	cylinder->transform = matrix_mult_4(cylinder->transform, translation(-5, 0, 1));
	// cylinder->transform = matrix_mult_4(cylinder->transform, scaling(10, 0.01, 10));
	// cylinder->transform = matrix_mult_4(cylinder->transform, rotation_x(M_PI / 2));
	// cylinder->transform = matrix_mult_4(cylinder->transform, rotation_y(-(M_PI) / 4));
	cylinder->min = 0;
	cylinder->max = 10;
	cylinder->transform = matrix_mult_4(cylinder->transform, translation(0, 0, 5));
	cylinder->material = init_material();
	cylinder->material.color = create_color(0, 1, 0.2);
	cylinder->material.diffuse = 0.7;
	cylinder->material.specular = 0.3;
	new = ft_lstnew((void *) cylinder);
	ft_lstadd_back(&w.objs, new); //SEFGAULT
	/* right_wall = void_obj();
	right_wall->transform = matrix_mult_4(right_wall->transform, translation(0, 0, 5));
	right_wall->transform = matrix_mult_4(right_wall->transform, rotation_y(M_PI / 4));
	right_wall->transform = matrix_mult_4(right_wall->transform, rotation_x(M_PI / 2));
	right_wall->transform = matrix_mult_4(right_wall->transform, scaling(10, 0.01, 10));
	right_wall->material = floor->material;
	new = ft_lstnew((void *) right_wall);
	ft_lstadd_back(&w.objs, new); */
	middle = void_obj();
	middle->transform = translation(-0.5, 1, 0.5);
	middle->material = init_material();
	middle->material.color = create_color(0.1, 1, 0.5);
	middle->material.diffuse = 0.7;
	middle->material.specular = 0.3;
	new = ft_lstnew((void *) middle);
	ft_lstadd_back(&w.objs, new);
	right = void_obj();
	right->transform = matrix_mult_4(translation(1.5, 0.5, -0.5), scaling(0.5, 0.5, 0.5));
	right->material = init_material();
	right->material.color = create_color(0.5, 1, 0.1);
	right->material.diffuse = 0.7;
	right->material.specular = 0.3;
	new = ft_lstnew((void *) right);
	ft_lstadd_back(&w.objs, new);
	left = void_obj();
	left->transform = matrix_mult_4(translation(-1.5, 0.33, -0.75), scaling(0.33, 0.33, 0.33));
	left->material = init_material();
	left->material.color = create_color(1, 0.8, 0.1);
	left->material.diffuse = 0.7;
	left->material.specular = 0.3;
	new = ft_lstnew((void *) left);
	ft_lstadd_back(&w.objs, new);
	data->world = w;
	// print_list(data->world);
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

	set_scene(data);
	x = 0;
	y = 0;
	render_background(&data->img, 0x000000);
	printf("coucou\n");
	while (y < data->cam.hsize)
	{
		x = 0;
		//world_y = data->cam.hsize - (y * 2);
		while (x < data->cam.vsize)
		{
			//world_x = -data->cam.vsize + (x * 2);
			ray = ray_for_pixel(data->cam, x, y);
			color = color_at(data->world, ray);
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

/* OLD:
void	render_map(t_data *data)
{

	t_ray	ray;
	t_tuple	origin;
	t_tuple	pos;
	t_tuple	point;
	t_obj	*obj;
	t_xs	xs;
	int	world_x;
	int	world_y;
	int x;
	int y;
	t_tuple	color;
	int	color2;
	t_light	light;
	t_tuple	eye;
	t_tuple	normal;

	x = 0;
	y = 0;
	world_x = 0;
	world_y = 0;
	origin = create_point(0, 0, -1.5);
	render_background(&data->img, 0x000000);
	obj = void_obj();
	set_transform(obj, scaling(1, 1, 1));
	obj->material.color = create_color(1, 0.2, 1);
	light.position = create_point(-3, 4, -5);
	light.intensity = create_color(1, 1, 1);
	light = point_light(light.position, light.intensity);
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		world_y = WINDOW_HEIGHT - (y * 2);
		while (x < WINDOW_WIDTH)
		{
			world_x = -WINDOW_WIDTH + (x * 2);
			pos = create_point(world_x, world_y, 60);
			ray = create_ray(origin, normalize(sub_tuples(pos, origin)));
			xs = intersect(obj, ray);
			if (xs.count > 0)
			{
				point = position(ray, xs.t);
				normal = normal_at(xs.obj, point);
				eye = reverse_tuple(ray.direction);
				color = lighting(xs.obj->material, light, point, eye, normal, 0);
				color2 = transform_color(color);
				img_pxl_put(&data->img, x, y, color2);
			}
			x++;
		}
		y++;
	}
	printf("obj color x:%f\n", obj->material.color.x);
	printf("obj color y:%f\n", obj->material.color.y);
	printf("obj color z:%f\n", obj->material.color.z);
	printf("Done!\n");
}*/

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
