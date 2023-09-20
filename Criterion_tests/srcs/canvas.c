/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:56:28 by mrabourd          #+#    #+#             */
/*   Updated: 2023/09/20 16:40:10 by avedrenn         ###   ########.fr       */
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

	printf("cam fov: %f\n", data->cam.fov);
	printf("cam orientation.x: %f\n", data->cam.orientation.x);
	printf("cam orientation.y: %f\n", data->cam.orientation.y);
	printf("cam orientation.z: %f\n", data->cam.orientation.z);
	printf("cam position.x: %f\n", data->cam.position.x);
	printf("cam position.y: %f\n", data->cam.position.y);
	printf("cam position.z: %f\n", data->cam.position.z);
	print_objects_list(data->world.objs);
	x = 0;
	y = 0;
	render_background(&data->img, 0x000000);
	printf("coucou\n");
	// data->cam.position.x = 0;
	// data->cam.position.y = 0;
	// data->cam.position.z = 0;
	// printf("cam position.x: %f\n", data->cam.position.x);
	// printf("cam position.y: %f\n", data->cam.position.y);
	// printf("cam position.z: %f\n", data->cam.position.z);
	// t_light	light;
	// light.position = create_point(-3, 4, -5);
	// light.intensity = create_color (1, 1, 1);
	// data->world.light = light;
	//data->cam = create_camera(WINDOW_WIDTH, WINDOW_HEIGHT, M_PI / 3);
	while (y < data->cam.vsize)
	{
		x = 0;
		while (x < data->cam.hsize)
		{
			ray = ray_for_pixel(data->cam, x, y);
			color = color_at(data->world, ray);
			img_pxl_put(&data->img, x, y, transform_color(color));
			x++;
		}
		y++;
	}
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
