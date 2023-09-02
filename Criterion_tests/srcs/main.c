/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:16:31 by mrabourd          #+#    #+#             */
/*   Updated: 2023/09/02 13:50:57 by avedrenn         ###   ########.fr       */
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
		t_matrix_4	scaled;
	t_matrix_4	inverse;
	t_tuple vec;
	t_tuple	res;

	scaled = scaling(2, 3, 4);
	inverse = mat_inversion_4(scaled);
	vec = create_vector(-1, 6, 8);
	res = matrix_mult_tuple(inverse, vec);
	printf("res.x : %f\n", res.x);
	printf("res.y : %f\n", res.y);
	printf("res.z : %f\n", res.z);
	printf("res.w : %f\n", res.w);

	init_canvas(&data);
	ft_free_all(&data);
	return (0);
}