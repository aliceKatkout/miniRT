#include <criterion.h>
#include "../project.h"

Test(tuple, tuple_add_point_and_vector1)
{
	//Arrange
	t_tuple a;
	t_tuple	b;
	t_tuple c;
	//Act
	a = create_point(3, -2, 5);
	b = create_vector(-2, 3, 1);
	c = add_tuples(a, b);
	//Assert
	cr_expect(c.x == 1);
	cr_expect(c.y == 1);
	cr_expect(c.z == 6);
	cr_expect(c.w == 1);
}

Test(tuple, tuple_add_point_and_vector2)
{
	//Arrange
	t_tuple a;
	t_tuple	b;
	t_tuple c;
	//Act
	a = create_point(3, 22, 5);
	b = create_vector(2, -3, 1);
	c = add_tuples(a, b);
	//Assert
	cr_expect(c.x == 5);
	cr_expect(c.y == 19);
	cr_expect(c.z == 6);
	cr_expect(c.w == 1);
}

Test(tuple, tuple_add_point_and_point)
{
	//Arrange
	t_tuple a;
	t_tuple	b;
	t_tuple c;
	//Act
	a = create_point(3, 22, 5);
	b = create_point(2, -3, 1);
	c = add_tuples(a, b);
	//Assert
	cr_expect(c.x == 5);
	cr_expect(c.y == 19);
	cr_expect(c.z == 6);
	cr_expect(c.w == 2);
}

Test(tuple, tuple_sub_point_vector)
{
	//Arrange
	t_tuple a;
	t_tuple	b;
	t_tuple c;
	//Act
	a = create_point(3, -2, 5);
	b = create_vector(-2, 3, 1);
	c = sub_tuples(a, b);
	//Assert
	cr_expect(c.x == 5);
	cr_expect(c.y == -5);
	cr_expect(c.z == 4);
	cr_expect(c.w == 1);
}

Test(tuple, tuple_sub_point_point)
{
	//Arrange
	t_tuple a;
	t_tuple	b;
	t_tuple c;
	//Act
	a = create_point(3, -10, 5);
	b = create_point(-2, 3, 1);
	c = sub_tuples(a, b);
	//Assert
	cr_expect(c.x == 5);
	cr_expect(c.y == -13);
	cr_expect(c.z == 4);
	cr_expect(c.w == 0);
}

Test(tuple, tuple_sub_vec_vec)
{
	//Arrange
	t_tuple a;
	t_tuple	b;
	t_tuple c;
	//Act
	a = create_vector(3, 2, 1);
	b = create_vector(5, 6, 7);
	c = sub_tuples(a, b);
	//Assert
	cr_expect(c.x == -2);
	cr_expect(c.y == -4);
	cr_expect(c.z == -6);
	cr_expect(c.w == 0);
}

Test(tuple, tuple_neg_vec)
{
	t_tuple a;
	t_tuple c;
	a = create_vector(1, -2, 3);
	c = neg_tuples(a);
	cr_expect(c.x == -1);
	cr_expect(c.y == 2);
	cr_expect(c.z == -3);
	cr_expect(c.w == 0);
}

Test(tuple, tuple_mult_vec1)
{
	t_tuple a;
	double	vec = 3.5;
	t_tuple c;
	a = create_vector(1, -2, 3);
	c = mult_tuples(a, vec);
	cr_expect(c.x == 3.5);
	cr_expect(c.y == -7);
	cr_expect(c.z == 10.5);
	cr_expect(c.w == 0);
}

Test(tuple, tuple_div_vec1)
{
	t_tuple a;
	double	vec = 2;
	t_tuple c;
	a = create_vector(1, -2, 3);
	c = div_tuples(a, vec);
	cr_expect(c.x == 0.5);
	cr_expect(c.y == -1);
	cr_expect(c.z == 1.5);
	cr_expect(c.w == 0);
}

Test(tuple, tuple_magnitude1)
{
	t_tuple a;
	double c;
	a = create_vector(1, 0, 0);
	c = magn_tuple(a);
	cr_expect(c == 1);
}

Test(tuple, tuple_magnitude2)
{
	t_tuple a;
	double c;
	a = create_vector(1, 2, 3);
	c = magn_tuple(a);
	cr_expect(c == sqrtf(14));
}

Test(tuple, tuple_magnitude3)
{
	t_tuple a;
	double c;
	a = create_vector(4, 0, 3);
	c = magn_tuple(a);
	cr_expect(c == 5);
}

Test(tuple, tuple_normalize1)
{
	t_tuple a;
	t_tuple	res;
	double c;
	a = create_vector(4, 0, 0);
	c = magn_tuple(a);
	cr_expect(c == 4);
	res = normalize(a);
	cr_expect(res.x == 1);
	cr_expect(res.y == 0);
	cr_expect(res.z == 0);
}

Test(tuple, tuple_normalize2)
{
	t_tuple a;
	t_tuple	res;
	double c;
	a = create_vector(1, 2, 3);
	c = magn_tuple(a);
	cr_expect(c == sqrtf(14));
	res = normalize(a);
	cr_expect(res.x == a.x / c);
	cr_expect(res.y == a.y / c);
	cr_expect(res.z == a.z / c);
}

Test(tuple, dot_prod1)
{
	t_tuple a;
	t_tuple b;
	a = create_vector(1, 2, 3);
	b = create_vector(2, 3, 4);
	cr_expect(dot_product(a, b) == 20);
}

Test(tuple, cross_product1)
{
	t_tuple a;
	t_tuple b;
	t_tuple vec;

	a = create_vector(1, 2, 3);
	b = create_vector(2, 3, 4);
	vec = cross_product(a, b);
	cr_expect(vec.x == -1);
	cr_expect(vec.y == 2);
	cr_expect(vec.z == -1);
}

Test(tuple, cross_product2)
{
	t_tuple a;
	t_tuple b;
	t_tuple vec;

	a = create_vector(1, 2, 3);
	b = create_vector(2, 3, 4);
	vec = cross_product(b, a);
	cr_expect(vec.x == 1);
	cr_expect(vec.y == -2);
	cr_expect(vec.z == 1);
}