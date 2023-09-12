#include <criterion.h>
#include "../project.h"

Test(World, empty_world)
{
	//Arrange
	t_world	w;
	//Act
	w = create_world();
	//Assert
	cr_expect(w.light == NULL);
	cr_expect(w.objs == NULL);
}

Test(World, default)
{
	t_world	w;
	t_light	l;
	t_obj	*s1;
	t_obj	*s2;

	w = default_world();
	l = point_light(create_point(-10, 10, -10), create_color(1, 1, 1));
	s1 = void_obj();
	s1->material.color = create_color(0.8, 1.0, 0.6);
	s1->material.diffuse = 0.7;
	s1->material.specular = 0.2;
	s2 = void_obj();
	s2->transform = scaling(0.5, 0.5, 0.5);
	cr_expect(w.light->position.x == l.position.x);
	cr_assert(false, "%f should be %f", w.light->position.x,  l.position.x);
	cr_expect(w.light->intensity.x == l.intensity.x);
	cr_assert(false, "%f should be %f", w.light->intensity.x,  l.intensity.x);
	/* cr_expect(matrix_cmp_4(w->objs->(t_obj *)content->transform, s1->transform) == 0);
	cr_expect(matrix_cmp_4(w->objs->(t_obj *)content->material.color, s1->material.color) == 0);
	cr_expect(w.objs->(t_obj *)content->material.diffuse == s1->material.diffuse);
	cr_expect(w.objs->(t_obj *)content->material.specular == s1->material.specular);
	cr_expect(matrix_cmp_4(w.objs->next->(t_obj *)content->transform, s2->transform) == 0);

  */
}