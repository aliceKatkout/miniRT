/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:56:28 by mrabourd          #+#    #+#             */
/*   Updated: 2023/09/07 18:17:05 by mrabourd         ###   ########.fr       */
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

void	render_map(t_data *data)
{

	t_ray	ray;
	t_tuple	origin;
	t_tuple	pos;
	t_sphere	sphere;
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
	origin = create_point(0, 0, -50);
	render_background(&data->img, 0x000000);
	sphere = void_sphere();
	sphere.material = init_material();
	sphere.material.color = create_color(255, 20, 255);
	light.position = create_point(-10, 10, -10);
	light.intensity = create_color(255, 100, 100);
	set_transform(&sphere, scaling(50, 50, 30));
	while (y < 1000)
	{
		x = 0;
		world_y = WINDOW_HEIGHT - (y * 2);
		while (x < 1000)
		{
			world_x = -WINDOW_WIDTH + (x * 2);
			pos = create_point(world_x, world_y, 10);
			ray = create_ray(origin, normalize(sub_tuples(pos, origin)));
			xs = intersect(sphere, ray);
			normal = normal_at(sphere, pos);
			eye = reverse_tuple(ray.direction);
			color = lighting(sphere.material, light, pos, eye, normal);
			color2 = transform_color(color);
			if (xs.count > 0)
				img_pxl_put(&data->img, x, y, color2);
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
			WINDOW_WIDTH, WINDOW_HEIGHT, "MiniRT");
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
