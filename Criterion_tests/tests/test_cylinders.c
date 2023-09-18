#include <criterion.h>
#include "../project.h"

Test(cylinder, intersect_void)
{
	t_ray	ray;
	t_tuple direction;
	t_obj	*obj;
	t_xs	xs;

	obj = void_cylinder();
	direction = normalize(create_vector(0, 1, 0));
	ray = create_ray(create_point(1, 0, 0), direction);
	xs = intersect (obj, ray);
	cr_expect(xs.count == 0);

	direction = normalize(create_vector(0, 1, 0));
	ray = create_ray(create_point(0, 0, 0), direction);
	xs = intersect (obj, ray);
	cr_expect(xs.count == 0);

	direction = normalize(create_vector(1, 1, 1));
	ray = create_ray(create_point(0, 0, -5), direction);
	xs = intersect (obj, ray);
	cr_expect(xs.count == 0);
}

Test(cylinder, intersect)
{
	t_ray	ray;
	t_tuple direction;
	t_obj	*obj;
	t_xs	xs;

	obj = void_cylinder();
	direction = normalize(create_vector(0, 0, 1));
	ray = create_ray(create_point(1, 0, -5), direction);
	xs = intersect (obj, ray);
	cr_expect(xs.count == 2);
	cr_expect(xs.x0 == 5);
	cr_expect(xs.x1 == 5);

	direction = normalize(create_vector(0, 0, 1));
	ray = create_ray(create_point(0, 0, -5), direction);
	xs = intersect (obj, ray);
	cr_expect(xs.count == 2);
	cr_expect(xs.x0 == 4);
	cr_expect(xs.x1 == 6);

	direction = normalize(create_vector(0.1, 1, 1));
	ray = create_ray(create_point(0.5, 0, -5), direction);
	xs = intersect (obj, ray);
	cr_expect(xs.count == 2);
	cr_expect(fabs(xs.x0 - 6.80798) < EPSILON);
	cr_expect(fabs(xs.x1 - 7.08872) < EPSILON);
}

Test(cylinder, normal_at)
{
	//t_obj	*obj;
	t_tuple normal;

	//obj = void_cylinder();
	normal = normal_at_cylinder(create_point(1, 0, 0));
	cr_expect(fabs(normal.x - 1) < EPSILON);
	cr_expect(fabs(normal.y) < EPSILON);
	cr_expect(fabs(normal.z) < EPSILON);

	normal = normal_at_cylinder(create_point(0, 5, -1));
	cr_expect(fabs(normal.x - 0) < EPSILON);
	cr_expect(fabs(normal.y - 0) < EPSILON);
	cr_expect(fabs(normal.z + 1) < EPSILON);

	normal = normal_at_cylinder(create_point(0, -2, 1));
	cr_expect(fabs(normal.x - 0) < EPSILON);
	cr_expect(fabs(normal.y) < EPSILON);
	cr_expect(fabs(normal.z -1) < EPSILON);

	normal = normal_at_cylinder(create_point(-1, 1, 0));
	cr_expect(fabs(normal.x + 1) < EPSILON);
	cr_expect(fabs(normal.y) < EPSILON);
	cr_expect(fabs(normal.z) < EPSILON);
}

Test(cylinder, min_max)
{
	t_obj	*obj;
	t_tuple direction;
	t_ray	r;
	t_xs	xs;

	obj = void_cylinder();
	cr_expect(obj->min == -INFINITY);
	cr_expect(obj->max == INFINITY);

	obj->min = 1;
	obj->max = 2;
	direction = normalize(create_vector(0.1, 1, 0));
	r = create_ray(create_point(0, 1.5, 0), direction);
	xs = intersect(obj, r);
	cr_expect(xs.count == 0);

	direction = normalize(create_vector(0, 0, 1));
	r = create_ray(create_point(0, 3, -5), direction);
	xs = intersect(obj, r);
	cr_expect(xs.count == 0);

	direction = normalize(create_vector(0, 0, 1));
	r = create_ray(create_point(0, 0, -5), direction);
	xs = intersect(obj, r);
	cr_expect(xs.count == 0);

	direction = normalize(create_vector(0, 0, 1));
	r = create_ray(create_point(0, 2, -5), direction);
	xs = intersect(obj, r);
	cr_expect(xs.count == 0);

	direction = normalize(create_vector(0, 0, 1));
	r = create_ray(create_point(0, 1, -5), direction);
	xs = intersect(obj, r);
	cr_expect(xs.count == 0);

	direction = normalize(create_vector(0, 0, 1));
	r = create_ray(create_point(0, 1.5, -2), direction);
	xs = intersect(obj, r);
	cr_expect(xs.count == 2);

}