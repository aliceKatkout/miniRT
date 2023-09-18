/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:16:31 by mrabourd          #+#    #+#             */
/*   Updated: 2023/09/18 18:45:48 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project.h"

void	print_matrix_3(t_matrix_3 a)
{
	int	x;
	int	y;

	x = 0;
	while (x < 3)
	{
		y = 0;
		while (y < 3)
		{
			printf("a.tab[%d][%d]: %f\n", x, y, a.tab[x][y]);
			y++;
		}
		x++;
	}
}

void	print_matrix_2(t_matrix_2 b)
{
	int	x;
	int	y;

	x = 0;
	while (x < 2)
	{
		y = 0;
		while (y < 2)
		{
			printf("b.tab[%d][%d]: %f\n", x, y, b.tab[x][y]);
			y++;
		}
		x++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	
	if (argc != 2)
	{
		printf("One argument expected. \n");
		return (1);
	}
	parse_scene(argv[1], &data);
 	init_canvas(&data);

	ft_free_all(&data);
	return (0);
}