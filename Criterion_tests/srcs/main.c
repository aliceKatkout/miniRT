/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:16:31 by mrabourd          #+#    #+#             */
/*   Updated: 2023/09/07 11:48:24 by mrabourd         ###   ########.fr       */
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
 	// init_canvas(&data);
	t_sphere	s;
	t_tuple		n;
	t_tuple		cmp;

	s = void_sphere();
	n = normal_at(s, create_point(sqrt(3/3), sqrt(3/3), sqrt(3/3)));
	cmp = normalize(n);
	printf("cmp.x: %f\n", cmp.x);
	printf("cmp.y: %f\n", cmp.y);
	printf("cmp.z: %f\n", cmp.z);
	// ft_free_all(&data);
	return (0);
}