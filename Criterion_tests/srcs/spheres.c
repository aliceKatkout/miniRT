/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spheres.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:31:09 by avedrenn          #+#    #+#             */
/*   Updated: 2023/09/04 15:56:21 by avedrenn         ###   ########.fr       */
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
	return (sphere);
}
