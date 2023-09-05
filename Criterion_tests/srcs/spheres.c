/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spheres.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:31:09 by avedrenn          #+#    #+#             */
/*   Updated: 2023/09/05 14:57:13 by avedrenn         ###   ########.fr       */
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
	return (sphere);
}

void	set_transform(t_sphere s, t_matrix_4 m)
{
	s.transform = m;
	(void)s;
}
