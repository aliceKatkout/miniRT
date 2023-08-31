/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:16:31 by mrabourd          #+#    #+#             */
/*   Updated: 2023/08/31 20:18:36 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project.h"

t_projectile	ft_tick(t_env env, t_projectile proj)
{
	t_projectile	ret;

	ret.position = add_tuples(proj.position, proj.velocity);
	ret.velocity = add_tuples(proj.velocity, env.gravity);
	ret.velocity = add_tuples(ret.velocity, env.wind);
	return (ret);
}

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

int	main(void)
{
	t_data	data;
	(void)data;
	t_matrix_3	a;
	t_matrix_2	b;
	float	tab_a[9] = {1, 5, 10, -3, 2, 7, 10, 6, -3};

	a = create_matrix_3(tab_a);
	print_matrix_3(a);
	b = submatrix_3(a, 0, 2);
	print_matrix_2(b);
	(void)b;
	// init_canvas(&data);
	// ft_free_all(&data);
	return (0);
}