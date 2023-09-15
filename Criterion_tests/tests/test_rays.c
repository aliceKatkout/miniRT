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
	t_obj		*obj;
	t_xs		xs;

	ray = create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
	obj = void_obj();
	xs = intersect(obj, ray);
	cr_expect(xs.count == 2);
	cr_expect(xs.x0 == 4);
	cr_expect(xs.x1 == 6);

	ray = create_ray(create_point(0, 1, -5), create_vector(0, 0, 1));
	obj = void_obj();
	xs = intersect(obj, ray);
	cr_expect(xs.count == 2);
	cr_expect(xs.x0 == 5);
	cr_expect(xs.x1 == 5);

	ray = create_ray(create_point(0, 2, -5), create_vector(0, 0, 1));
	obj = void_obj();
	xs = intersect(obj, ray);
	cr_expect(xs.count == 0);

	ray = create_ray(create_point(0, 0, 0), create_vector(0, 0, 1));
	obj = void_obj();
	xs = intersect(obj, ray);
	cr_expect(xs.count == 1);
	cr_expect(xs.x0 == -1);
	cr_expect(xs.x1 == 1);

	ray = create_ray(create_point(0, 0, 5), create_vector(0, 0, 1));
	obj = void_obj();
	xs = intersect(obj, ray);
	cr_expect(xs.count == 0);
	cr_expect(xs.x0 == -6);
	cr_expect(xs.x1 == -4);
}


Test(rays, transform1)
{
	t_ray		r;
	t_matrix_4	m;
	t_ray		r2;

	r = create_ray(create_point(1, 2, 3), create_vector(0, 1, 0));
	m = translation(3, 4, 5);
	r2 = transform_ray(r, m);

	cr_expect(r2.origin.x == 4);
	cr_expect(r2.origin.y == 6);
	cr_expect(r2.origin.z == 8);
	cr_expect(r2.direction.x == 0);
	cr_expect(r2.direction.y == 1);
	cr_expect(r2.direction.z == 0);
}

Test(rays, transform2)
{
	t_ray		r;
	t_matrix_4	m;
	t_ray		r2;

	r = create_ray(create_point(1, 2, 3), create_vector(0, 1, 0));
	m = scaling(2, 3, 4);
	r2 = transform_ray(r, m);

	cr_expect(r2.origin.x == 2);
	cr_expect(r2.origin.y == 6);
	cr_expect(r2.origin.z == 12);
	cr_expect(r2.direction.x == 0);
	cr_expect(r2.direction.y == 3);
	cr_expect(r2.direction.z == 0);
}

Test(Intersections, local_intersect)
{
	t_obj		*obj;
	t_ray		ray;
	//t_xs		xs;

	obj = void_obj();
	set_transform(obj, scaling(2, 2, 2));
	ray = create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
	intersect(obj, ray);

	cr_expect(obj->saved_ray.origin.x == 0);
	cr_expect(obj->saved_ray.origin.y == 0);
	cr_expect(obj->saved_ray.origin.z == -2.5);
	cr_expect(obj->saved_ray.direction.x == 0);
	cr_expect(obj->saved_ray.direction.y == 0);
	cr_expect(obj->saved_ray.direction.z == 0.5);
}

Test(Intersections, local_intersect2)
{
	t_obj		*obj;
	t_ray		ray;
	//t_xs		xs;

	ray = create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
	obj = void_obj();
	set_transform(obj, translation(5, 0, 0));

	intersect(obj, ray);

	cr_expect(obj->saved_ray.origin.x == -5);
	cr_expect(obj->saved_ray.origin.y == 0);
	cr_expect(obj->saved_ray.origin.z == -5);
	cr_expect(obj->saved_ray.direction.x == 0);
	cr_expect(obj->saved_ray.direction.y == 0);
	cr_expect(obj->saved_ray.direction.z == 1);
}
