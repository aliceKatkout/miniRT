#include <criterion.h>
#include "../miniRT.h"

Test(matrix, rotation_x)
{
	t_matrix_4	half_quarter;
	t_matrix_4	full_quarter;
	t_tuple point;
	t_tuple	res;

	point = create_point(0, 1, 0);
	half_quarter = rotation_x(M_PI / 4);
	full_quarter = rotation_x(M_PI / 2);
	res = matrix_mult_tuple(half_quarter, point);
	cr_expect((int)res.x == 0);
	cr_expect(fabs(res.y - (sqrt(2) / 2)) < EPSILON);
	cr_expect(fabs(res.z - (sqrt(2) / 2)) < EPSILON);
	res = matrix_mult_tuple(full_quarter, point);
	cr_expect((int)res.x == 0);
	cr_expect((int)res.y == 0);
	cr_expect((int)res.z == 1);

}

Test(matrix, rotation_y)
{
	t_matrix_4	half_quarter;
	t_matrix_4	full_quarter;
	t_tuple point;
	t_tuple	res;

	point = create_point(0, 0, 1);
	half_quarter = rotation_y(M_PI / 4);
	full_quarter = rotation_y(M_PI / 2);
	res = matrix_mult_tuple(half_quarter, point);
	cr_expect(fabs(res.x - (sqrt(2) / 2)) < EPSILON);
	cr_expect(fabs(res.y - 0) < EPSILON);
	cr_expect(fabs(res.z - (sqrt(2) / 2)) < EPSILON);
	res = matrix_mult_tuple(full_quarter, point);
	cr_expect((int)res.x == 1);
	cr_expect((int)res.y == 0);
	cr_expect((int)res.z == 0);

}

Test(matrix, rotation_z)
{
	t_matrix_4	half_quarter;
	t_matrix_4	full_quarter;
	t_tuple point;
	t_tuple	res;

	point = create_point(0, 1, 0);
	half_quarter = rotation_z(M_PI / 4);
	full_quarter = rotation_z(M_PI / 2);
	res = matrix_mult_tuple(half_quarter, point);
	cr_expect(fabs(res.x - (-(sqrt(2) / 2))) < EPSILON);
	cr_expect(fabs(res.y - (sqrt(2) / 2)) < EPSILON);
	cr_expect(fabs(res.z - 0) < EPSILON);
	res = matrix_mult_tuple(full_quarter, point);
	cr_expect((int)res.x == -1);
	cr_expect((int)res.y == 0);
	cr_expect((int)res.z == 0);

}