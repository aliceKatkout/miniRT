#include <criterion.h>
#include "../project.h"

Test(print, color1)
{
	t_tuple a;

	a = create_color(-0.5, 0.4, 1.7);
	cr_expect(a.x == -0.5);
	cr_expect(a.y == 0.4);
	cr_expect(a.z == 1.7);
}

Test(print, add_colors1)
{
	t_tuple a;
	t_tuple b;
	t_tuple c;

	a = create_color(0.9, 0.6, 0.75);
	b = create_color(0.7, 0.1, 0.25);
	c = add_tuples(a, b);
	cr_expect(c.x == 1.6);
	cr_expect(c.y == 0.7);
	cr_expect(c.z == 1.0);
}

Test(print, sub_colors1)
{
	t_tuple a;
	t_tuple b;
	t_tuple c;

	a = create_color(0.9, 0.6, 0.75);
	b = create_color(0.7, 0.1, 0.25);
	c = sub_tuples(a, b);
	// cr_expect(c.x == 0.2);
	cr_expect(c.y == 0.5);
	cr_expect(c.z == 0.5);
}

Test(print, mult_colors1)
{
	t_tuple a;
	t_tuple c;

	a = create_color(0.2, 0.3, 0.4);
	c = mult_tuples(a, 2);
	cr_expect(c.x == 0.4);
	cr_expect(c.y == 0.6);
	cr_expect(c.z == 0.8);
}


Test(print, mult_colors2)
{
	t_tuple a;
	t_tuple b;
	t_tuple c;

	a = create_color(1, 0.2, 0.4);
	b = create_color(0.9, 1, 0.1);
	c = mult_colors(a, b);
	cr_expect(c.x == 0.9);
	cr_expect(c.y == 0.2);
	cr_expect(c.z == 0.4 * 0.1);
}