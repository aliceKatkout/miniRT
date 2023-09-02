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