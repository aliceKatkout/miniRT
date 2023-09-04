/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spheres.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:31:09 by avedrenn          #+#    #+#             */
/*   Updated: 2023/09/04 15:18:09 by avedrenn         ###   ########.fr       */
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

t_xs	intersect(t_sphere s, t_ray r)
{
	t_xs	xs;
	t_tuple	sphere_to_ray;
	double	a;
	double	b;
	double	c;
	double	discriminant;

	sphere_to_ray = sub_tuples(r.origin, create_point(s.x, s.y, s.z));
	a = dot_product(r.direction, r.direction);
	b = 2 * dot_product(r.direction, sphere_to_ray);
	c = dot_product(sphere_to_ray, sphere_to_ray) - 1;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
	{
		xs.count = 0;
		return (xs);
	}
	xs.x0 = (-b - sqrtf(discriminant)) / (2 * a);
	xs.x1 = (-b + sqrtf(discriminant)) / (2 * a);
	xs.count = 2;
	return (xs);
}