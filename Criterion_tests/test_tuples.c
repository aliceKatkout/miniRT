#include <criterion.h>
#include "project.h"
/*
//On declare une fonction de test Criterion en ecrivant
//Test("name of test serie", "name of current test")
Test(machin, machin0)
{
	cr_expect(ft_machin(0) == 3);
	//cr_expect est la fonction de base la plus simple de Criterion
	//si l'expression entre parenthese est TRUE, le test passe,
	//sinon, le test echoue
}

Test(machin, machin1)
{
	cr_expect(ft_machin(3) == 3);
	cr_expect(ft_machin(0) != 5);
	//quel que soit le nombre de "expect()" dans la fonction Test()
	//la fonction compte pour UN test
	//d'ou le but de tester UN comportement a la fois dans UNE fonction Test()
	//(pas tester les resultats attendus ET la gestion d'erreur par exemple
	//sinon, qd le test echoue, on ne sait immediatement pourquoi)
}

Test(machin, machin2)
{
	cr_expect(ft_machin(5) == 5, "ceci est un message informatif qui sera visible sur le terminal uniquement quand ce assert fail,\ntres utile pour expliquer quel test echoue (et peut etre meme pourquoi) sans avoir besoin de regarder le fichier de test");
	//si on fait echouer ce test, le message entre "" apparait sur le terminal
}
*/

Test(tuple, tuple_point)
{
	//Arrange
	t_tuple a;
	//Act
	a = create_point(4.3, -4, 1);
	//Assert
	cr_expect(a.w == 1.0);
	cr_expect(a.w != 0, "tuple should be a vector");
}

Test(tuple, tuple_vector)
{
	//Arrange
	t_tuple	b;
	//Act
	b = create_vector(4, -4.2, 3);
	//Assert
	cr_expect(b.w == 0);
	cr_expect(b.w != 1.0);
}

Test(tuple, tuple_cmp1)
{
	//Arrange
	t_tuple a;
	t_tuple	b;
	int		ret;
	//Act
	a = create_point(4.3, -4, 1);
	b = create_point(4, -4.2, 3);
	ret = tuples_cmp(a, b);
	//Assert
	cr_expect(ret == 0);
}

Test(tuple, tuple_cmp2)
{
	//Arrange
	t_tuple a;
	t_tuple	b;
	int		ret;
	//Act
	a = create_point(4.3, -4, 1.0);
	b = create_point(4.3, -4.0001, 1);
	ret = tuples_cmp(a, b);
	//Assert
	cr_expect(ret == 1);
}

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