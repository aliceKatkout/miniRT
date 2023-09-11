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

/* Test(World, default)
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
	 cr_expect(sub_tuple(w.light.position, l.position) < EPSILON);
	cr_expect(sub_tuple(w.light.intensity, l.intensity) < EPSILON);
	cr_expect(sub_tuple(w.objs->content.transform, s1->transform) < EPSILON);
	 cr_expect(sub_tuple(w.objs->content->material.color, s1->material.color) < EPSILON);
	cr_expect(sub_tuple(w.objs->content->material.diffuse, s1->material.diffuse) < EPSILON);
	cr_expect(sub_tuple(w.objs->content->material.specular, s1->material.specular) < EPSILON);
	cr_expect(sub_tuple(w.objs->next->content->transform, s2->transform) < EPSILON);

} */