#include <criterion.h>
#include "../miniRT.h"
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
