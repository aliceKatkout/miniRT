#include <criterion.h>
#include "../miniRT.h"

Test(plane, local_normal)
{
	t_obj	*p;
	p = void_plane();
	t_tuple	n1 = normal_at(p, create_point(0, 0, 0));
	t_tuple n2 = normal_at(p, create_point(10, 0, -10));
	t_tuple n3 = normal_at(p, create_point(-5, 0, 150));

	cr_expect(n1.x == 0);
	cr_expect(n1.y == 1);
	cr_expect(n1.z == 0);
	cr_expect(n2.x == 0);
	cr_expect(n2.y == 1);
	cr_expect(n2.z == 0);
	cr_expect(n3.x == 0);
	cr_expect(n3.y == 1);
	cr_expect(n3.z == 0);
}

Test(plane, local_intersect1)
{
	t_obj	*plane;
	plane = void_plane();
	t_ray	r;
	r = create_ray(create_point(0, 10, 0), create_vector(0, 0, 1));
	t_xs	xs;
	xs = intersect(plane, r);

	cr_expect(xs.count == 0);
}

Test(plane, local_intersect2)
{
	t_obj	*plane;
	plane = void_plane();
	t_ray	r;
	r = create_ray(create_point(0, 0, 0), create_vector(0, 0, 1));
	t_xs	xs;
	xs = intersect(plane, r);

	cr_expect(xs.count == 0);
}

Test(plane, local_intersect3)
{
	t_obj	*plane;
	plane = void_plane();
	t_ray	r;
	r = create_ray(create_point(0, 1, 0), create_vector(0, -1, 0));
	t_xs	xs;
	xs = intersect(plane, r);

	cr_expect(xs.count == 1);
	cr_expect(xs.t == 1);
}

Test(plane, local_intersect4)
{
	t_obj	*plane;
	plane = void_plane();
	t_ray	r;
	r = create_ray(create_point(0, -1, 0), create_vector(0, 1, 0));
	t_xs	xs;
	xs = intersect(plane, r);

	cr_expect(xs.count == 1);
	cr_expect(xs.t == 1);
}