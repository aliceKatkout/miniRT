#include <criterion.h>
#include "../project.h"

Test(matrix, translation_1)
{
	t_matrix_4	transform;
	t_tuple point;
	t_tuple	res;

	transform = translation(5, -3, 2);
	point = create_point(-3, 4, 5);
	res = matrix_mult_tuple(transform, point);
	cr_expect(res.x == 2);
	cr_expect(res.y == 1);
	cr_expect(res.z == 7);
}

Test(matrix, translation_2)
{
	t_matrix_4	transform;
	t_matrix_4	inverse;
	t_tuple point;
	t_tuple	res;

	transform = translation(5, -3, 2);
	inverse = mat_inversion_4(transform);
	point = create_point(-3, 4, 5);
	res = matrix_mult_tuple(inverse, point);
	cr_expect(res.x == -8);
	cr_expect(res.y == 7);
	cr_expect(res.z == 3);
}

Test(matrix, translation_3)
{
	t_matrix_4	transform;
	t_tuple	vector;
	t_tuple	res;

	transform = translation(5, -3, 2);
	vector = create_vector(-3, 4, 5);
	res = matrix_mult_tuple(transform, vector);
	cr_expect(res.x == vector.x);
	cr_expect(res.y == vector.y);
	cr_expect(res.z == vector.z);
}

Test(matrix, scaling_1)
{
	t_matrix_4	scaled;
	t_tuple	point;
	t_tuple	res;

	scaled = scaling(2, 3, 4);
	point = create_point(-4, 6, 8);
	res = matrix_mult_tuple(scaled, point);
	cr_expect(res.x == -8);
	cr_expect(res.y == 18);
	cr_expect(res.z == 32);
}

Test(matrix, scaling_2)
{
	t_matrix_4	scaled;
	t_tuple	vector;
	t_tuple	res;

	scaled = scaling(2, 3, 4);
	vector = create_vector(-4, 6, 8);
	res = matrix_mult_tuple(scaled, vector);
	cr_expect(fabs(res.x - -8) < EPSILON);
	cr_expect(res.y == 18);
	cr_expect(res.z == 32);
}

Test(matrix, scaling_3)
{
	t_matrix_4	scaled;
	t_matrix_4	inverse;
	t_tuple vec;
	t_tuple	res;
	t_tuple	cmp;

	scaled = scaling(2, 3, 4);
	inverse = mat_inversion_4(scaled);
	vec = create_vector(-4, 6, 8);
	res = matrix_mult_tuple(inverse, vec);
	cmp = create_point(-2, 2, 2);
	cr_expect(fabs(res.x - cmp.x) < EPSILON);
	cr_expect(fabs(res.y - cmp.y) < EPSILON);
	cr_expect(fabs(res.z - cmp.z) < EPSILON);
}

Test(matrix, reflection_1)
{
	t_matrix_4	transform;
	t_tuple		point;
	t_tuple		res;

	point = create_point(2, 3, 4);
	transform = scaling(-1, 1, 1);
	res = matrix_mult_tuple(transform, point);
	cr_expect(fabs(res.x - (-2)) < EPSILON);
	cr_expect(fabs(res.y - 3) < EPSILON);
	cr_expect(fabs(res.z - 4) < EPSILON);
	cr_expect(res.x == -2);
	cr_expect(res.y == 3);
}
