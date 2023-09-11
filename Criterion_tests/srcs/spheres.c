/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spheres.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:31:09 by avedrenn          #+#    #+#             */
/*   Updated: 2023/09/11 14:20:48 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../project.h"

t_sphere	void_sphere(void)
{
	t_sphere	sphere;
	static int	id = 0;

	sphere.id = id++;
	sphere.x = 0;
	sphere.y = 0;
	sphere.z = 0;
	sphere.diameter = 1;
	sphere.transform = identity_matrix();
	sphere.color = create_color(0, 0, 0);
	return (sphere);
}

void	set_transform(t_sphere *s, t_matrix_4 m)
{
	int	x;
	int	y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			s->transform.tab[x][y] = m.tab[x][y];
			y++;
		}
		x++;
	}
	(void)s;
}
