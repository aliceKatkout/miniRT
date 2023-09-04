#include <criterion.h>
#include "../project.h"

Test(rays, rays1)
{
	//Arrange
	t_tuple	origin = create_point(2, 3, 4);
	t_tuple	direction = create_vector(1, 0, 0);
	t_ray	ray;
	t_tuple	pos;
	//Act
	ray = create_ray(origin, direction);
	pos = position(ray, 0);
	//Assert
	cr_expect(pos.x == 2);
	cr_expect(pos.y == 3);
	cr_expect(pos.z == 4);

	pos = position(ray, 1);
	cr_expect(pos.x == 3);
	cr_expect(pos.y == 3);
	cr_expect(pos.z == 4);

	pos = position(ray, -1);
	cr_expect(pos.x == 1);
	cr_expect(pos.y == 3);
	cr_expect(pos.z == 4);

	pos = position(ray, 2.5);
	cr_expect(pos.x == 4.5);
	cr_expect(pos.y == 3);
	cr_expect(pos.z == 4);
}

Test(rays, intersect)
{
	t_ray		ray;
	t_sphere	sphere;
	t_xs		xs;

	ray = create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
	sphere = void_sphere();
	xs = intersect(sphere, ray);
	cr_expect(xs.count == 2);
	cr_expect(xs.x0 == 4);
	cr_expect(xs.x1 == 6);

	ray = create_ray(create_point(0, 1, -5), create_vector(0, 0, 1));
	sphere = void_sphere();
	xs = intersect(sphere, ray);
	cr_expect(xs.count == 2);
	cr_expect(xs.x0 == 5);
	cr_expect(xs.x1 == 5);

	ray = create_ray(create_point(0, 2, -5), create_vector(0, 0, 1));
	sphere = void_sphere();
	xs = intersect(sphere, ray);
	cr_expect(xs.count == 0);

	ray = create_ray(create_point(0, 0, 0), create_vector(0, 0, 1));
	sphere = void_sphere();
	xs = intersect(sphere, ray);
	cr_expect(xs.count == 2);
	cr_expect(xs.x0 == -1);
	cr_expect(xs.x1 == 1);

	ray = create_ray(create_point(0, 0, 5), create_vector(0, 0, 1));
	sphere = void_sphere();
	xs = intersect(sphere, ray);
	cr_expect(xs.count == 2);
	cr_expect(xs.x0 == -6);
	cr_expect(xs.x1 == -4);
}