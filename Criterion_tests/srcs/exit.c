/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:00:47 by mrabourd          #+#    #+#             */
/*   Updated: 2023/08/31 20:16:46 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project.h"

int	ft_free_all(t_data *data)
{
	if (data->mlx_ptr)
	{
		render_background(&data->img, 0x000000);
		mlx_destroy_image(data->mlx_ptr, data->img.image);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free (data->mlx_ptr);
		exit(EXIT_SUCCESS);
	}
	return (1);
}
