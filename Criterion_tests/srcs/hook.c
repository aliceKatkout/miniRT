/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:59:17 by mrabourd          #+#    #+#             */
/*   Updated: 2023/08/31 16:36:19 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		ft_free_all(data);
	}
	return (0);
}

// int	handle_mouse(int button, int x, int y, t_data *data)
// {
// 	(void)x;
// 	(void)y;
// 	if (button == 4)
// 	{
// 		data->iso.space *= 1.5;
// 	}
// 	if (button == 5)
// 	{
// 		if (data->iso.space < 1)
// 		{
// 			data->iso.space = 1;
// 		}
// 		if (data->iso.space >= 1)
// 		{
// 			data->iso.space /= 1.5;
// 		}
// 	}
// 	render_map(mlx);
// 	return (0);
// }
