/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:56:28 by mrabourd          #+#    #+#             */
/*   Updated: 2023/08/30 19:17:23 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project.h"

// void	fill_canvas(t_canvas canvas)
// {
// 	int	x;
// 	int	y;
// 	t_tuple	black;

// 	x = 0;
// 	y = 0;
// 	black = create_color(0, 0, 0);
// 	while (y < canvas.w)
// 	{
// 		x = 0;
// 		while (x < canvas.h)
// 		{
// 			write_pixel(canvas, x, y, black);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	write_pix_canvas(t_canvas canvas, int x, int y, t_tuple color)
// {
// 	if (x >= 0 && x <= canvas.h)
// 	{
// 		if (y >= 0 && y <= canvas.w)
// 		{
			
// 		}
// 	}
// }

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
	// int	x;
	// int	y;

	// x = 0;
	// y = 0;
	render_background(&data->img, 0x000000);
	img_pxl_put(&data->img, 2, 2, 0xFF00);
	// while (y < WINDOW_HEIGHT - 1)
	// {
	// 	x = 0;
	// 	while (x < WINDOW_WIDTH)
	// 	{
	// 		render_proj(data, x, y);
	// 		x++;
	// 	}
	// 	y++;
	// }
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
	// mlx_hook(data->win_ptr, ButtonPress, ButtonPressMask, &handle_mouse, data);
	mlx_hook(data->win_ptr, 2, 1, &handle_keypress, data);
	mlx_hook(data->win_ptr, 17, 0, &ft_free_all, data);
	mlx_loop(data->mlx_ptr);
}
