#include <criterion.h>
#include "../project.h"

Test(matrix, matrix_4_1)
{
	//Arrange
	float	tab[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	t_matrix_4 matrix;
	//Act
	matrix = create_matrix_4(tab);
	//Assert
	cr_expect(matrix.tab[0][0] == 0);
	cr_expect(matrix.tab[0][2] == 2);
	cr_expect(matrix.tab[1][0] == 4);
	cr_expect(matrix.tab[1][1] == 5);
	cr_expect(matrix.tab[3][3] == 15);
}

Test(matrix, matrix_cmp1)
{
	//Arrange
	float	tab_a[16] = {0, 1.2, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	float	tab_b[16] = {0, 1.2, 2, 3, 4, 5, 7, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	t_matrix_4 mat_a;
	t_matrix_4 mat_b;
	//Act
	mat_a = create_matrix_4(tab_a);
	mat_b = create_matrix_4(tab_b);
	//Assert
	cr_expect(matrix_cmp_4(mat_a, mat_b) == -1);
}

Test(matrix, matrix_cmp2)
{
	//Arrange
	float	tab_a[16] = {0, 1.2, 2, 3, 4, 5, 6.236, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	float	tab_b[16] = {0, 1.2, 2, 3, 4, 5, 6.236, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	t_matrix_4 mat_a;
	t_matrix_4 mat_b;
	//Act
	mat_a = create_matrix_4(tab_a);
	mat_b = create_matrix_4(tab_b);
	//Assert
	cr_expect(matrix_cmp_4(mat_a, mat_b) == 0);
}

Test(matrix, matrix_mult1)
{
	//Arrange
	float	tab_a[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2};
	float	tab_b[16] = {-2, 1, 2, 3, 3, 2, 1, -1, 4, 3, 6, 5, 1, 2, 7, 8};
	t_matrix_4 mat_a;
	t_matrix_4 mat_b;
	t_matrix_4 mat_c;
	//Act
	mat_a = create_matrix_4(tab_a);
	mat_b = create_matrix_4(tab_b);
	mat_c = matrix_mult_4(mat_a, mat_b);
	//Assert
	cr_expect(mat_c.tab[0][0] == 20);
	cr_expect(mat_c.tab[0][1] == 22);
	cr_expect(mat_c.tab[0][3] == 48);
	cr_expect(mat_c.tab[1][1] == 54);
	cr_expect(mat_c.tab[1][2] == 114);
	cr_expect(mat_c.tab[3][1] == 26);

}

Test(matrix, matrix_mult1_tuple1)
{
	float	tab_a[16] = {1, 2, 3, 4, 2, 4, 4, 2, 8, 6, 4, 1, 0, 0, 0, 1};
	t_tuple	point;
	t_matrix_4 mat_a;
	t_tuple point_c;
	mat_a = create_matrix_4(tab_a);
	point = create_point(1, 2, 3);
	point_c = matrix_mult_tuple(mat_a, point);
	cr_expect(point_c.x == 18);
	cr_expect(point_c.y == 24);
	cr_expect(point_c.z == 33);
	cr_expect(point_c.w == 1);
}

Test(matrix, matrix_id1)
{
	float	tab_a[16] = {0, 1, 2, 4, 1, 2, 4, 8, 2, 4, 8, 16, 4, 8, 16, 32};
	t_matrix_4 mat_a;
	t_matrix_4	id;
	t_matrix_4 mult;

	mat_a = create_matrix_4(tab_a);
	id = identity_matrix();
	mult = matrix_mult_4(mat_a, id);
	cr_expect(matrix_cmp_4(mat_a, mult) == 0);
}

Test(matrix, matrix_id_tuple1)
{
	t_tuple a;
	t_matrix_4	id;
	t_tuple mult;

	a = create_tuple(1, 2, 3, 4);
	id = identity_matrix();
	mult = matrix_mult_tuple(id, a);
	cr_expect(mult.x == a.x);
	cr_expect(mult.y == a.y);
	cr_expect(mult.z == a.z);
	cr_expect(mult.w == a.w);
}

Test(matrix, transpose_1)
{
	t_matrix_4	a;
	t_matrix_4	b;
	float	tab_a[16] = {10, 9, 3, 10, 9, 8, 10, 8, 1, 8, 5, 3, 10, 10, 5, 8};

	a = create_matrix_4(tab_a);
	b = transpose_mat(a);
	//check a
	cr_expect(a.tab[0][2] = 3);
	//check b
	cr_expect(b.tab[0][0] == 10);
	cr_expect(b.tab[0][1] == 9);
	cr_expect(b.tab[0][2] == 1);
	cr_expect(b.tab[0][3] == 10);
	cr_expect(b.tab[1][0] == 9);
	cr_expect(b.tab[1][1] == 8);
	cr_expect(b.tab[1][2] == 8);
	cr_expect(b.tab[1][3] == 10);
	cr_expect(b.tab[2][0] == 3);
	cr_expect(b.tab[2][1] == 10);
	cr_expect(b.tab[2][2] == 5);
	cr_expect(b.tab[2][3] == 5);
	cr_expect(b.tab[3][0] == 10);
	cr_expect(b.tab[3][2] == 3);
}

Test(matrix, matrix2_1)
{
	t_matrix_2	a;
	int	b;
	float	tab_a[4] = {1, 5, -3, 2};

	a = create_matrix_2(tab_a);
	b = determine_two(a);
	cr_expect(b == 17);
}

Test(matrix, sub_matrix_1)
{
	t_matrix_3	a;
	t_matrix_2	b;
	float	tab_a[9] = {1, 5, 10, -3, 2, 7, 10, 6, -3};

	a = create_matrix_3(tab_a);
	b = submatrix_3(a, 0, 2);
	cr_expect(b.tab[0][0] == -3);
	cr_expect(b.tab[0][1] == 2);
	cr_expect(b.tab[1][0] == 10);
	cr_expect(b.tab[1][1] == 6);
}

Test(matrix, sub_matrix_2)
{
	t_matrix_4	a;
	t_matrix_3	b;
	float	tab_a[16] = {-6, 1, 1, 6, -8, 5, 8, 6, -1, 10, 8, 2, -7, 1, -1, 1};

	a = create_matrix_4(tab_a);
	b = submatrix_4(a, 2, 1);
	cr_expect(b.tab[0][0] == -6);
	cr_expect(b.tab[0][1] == 1);
	cr_expect(b.tab[0][2] == 6);
	cr_expect(b.tab[1][0] == -8);
	cr_expect(b.tab[1][1] == 8);
	cr_expect(b.tab[1][2] == 6);
	cr_expect(b.tab[2][0] == -7);
	cr_expect(b.tab[2][1] == -1);
	cr_expect(b.tab[2][2] == 1);
}