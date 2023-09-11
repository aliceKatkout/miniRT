#include <criterion.h>
#include "../project.h"

Test(matrix, chaining)
{
	t_matrix_4	a;
	t_matrix_4	b;
	t_matrix_4	c;
	t_tuple		p;
	t_tuple		res;

	a = rotation_x(M_PI / 2);
	b = scaling(5, 5, 5);
	c = translation(10, 5, 7);
	p = create_point(1, 0, 1);
	res = matrix_mult_tuple(a, p);
	cr_expect((int)res.x == 1);
	cr_expect((int)res.y == -1);
	cr_expect((int)res.z == 0);
	res = matrix_mult_tuple(b, res);
	cr_expect((int)res.x == 5);
	cr_expect((int)res.y == -5);
	cr_expect((int)res.z == 0);
	res = matrix_mult_tuple(c, res);
	cr_expect((int)res.x == 15);
	cr_expect((int)res.y == 0);
	cr_expect(fabs(res.z - 7) < EPSILON);
}

Test(transform, set_transform)
{
	t_matrix_4	transform;
	t_obj		*s;

	s = void_obj();
	cr_expect(matrix_cmp_4(s->transform, identity_matrix()) == 0);
	transform = translation(2, 3, 4);
	set_transform(s, transform);
	cr_expect(matrix_cmp_4(s->transform, transform) == 0);
}

Test(transform, set_transform2)
{
	t_obj		*s;
	t_ray		r;
	t_xs	xs;

	r= create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
	s = void_obj();

	set_transform(s, scaling(2, 2, 2));

	xs = intersect(s, r);
	cr_expect(xs.count == 2);
	cr_expect(xs.x0 - 3 < EPSILON);
	cr_expect(xs.x1 - 7 < EPSILON);
}

Test(transform, set_transform3)
{
	t_obj	*s;
	t_ray		r;
	t_xs	xs;

	r= create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
	s = void_obj();

	set_transform(s, translation(5, 0, 0));

	xs = intersect(s, r);
	cr_expect(xs.count == 0);
}