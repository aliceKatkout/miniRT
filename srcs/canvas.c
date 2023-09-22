/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:56:28 by mrabourd          #+#    #+#             */
/*   Updated: 2023/09/22 12:22:05 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

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
	int		x;
	int		y;
	t_tuple	color;

	x = 0;
	y = 0;
	render_background(&data->img, 0x000000);
	printf("Starting render!\n");
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
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.image, 0, 0);
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
	mlx_hook(data->win_ptr, 17, 0, &ft_free_all, data);
	mlx_loop(data->mlx_ptr);
}
