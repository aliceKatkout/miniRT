#include <criterion.h>
#include "../project.h"

Test(light, normal1)
{
	t_sphere	s;
	t_tuple		n;

	s = void_sphere();
	n = normal_at(s, create_point(1, 0, 0));
	cr_expect(n.x == 1);
	cr_expect(n.y == 0);
	cr_expect(n.z == 0);
	n = normal_at(s, create_point(0, 1, 0));
	cr_expect(n.x == 0);
	cr_expect(n.y == 1);
	cr_expect(n.z == 0);
}

Test(light, normalize)
{
	t_sphere	s;
	t_tuple		n;
	t_tuple		cmp;

	s = void_sphere();
	n = normal_at(s, create_point(1, 0.5, 0.5));
	cr_expect(n.x == 1);
	cr_expect(n.y == 0.5);
	cr_expect(n.z == 0.5);
	cmp = normalize(n);
	cr_expect(n.x - cmp.x < EPSILON);
	cr_expect(n.y - cmp.y < EPSILON);
	cr_expect(n.z - cmp.z < EPSILON);
}