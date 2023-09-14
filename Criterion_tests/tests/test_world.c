#include <criterion.h>
#include "../project.h"

Test(World, empty_world)
{
	//Arrange
	t_world	w;
	//Act
	w = create_world();
	//Assert
	//cr_expect(w.light == NULL);
	cr_expect(w.objs == NULL);
}

Test(World, default)
{
	t_world	w;
	t_light	l;
	t_obj	*s1;
	t_obj	*s2;
	t_obj	*content;

	w = default_world();
	l = point_light(create_point(-10, 10, -10), create_color(1, 1, 1));
	s1 = void_obj();
	s1->material.color = create_color(0.8, 1.0, 0.6);
	s1->material.diffuse = 0.7;
	s1->material.specular = 0.2;
	s2 = void_obj();
	s2->transform = scaling(0.5, 0.5, 0.5);
	cr_expect(w.light.position.x == l.position.x);
	cr_expect(w.light.intensity.x == l.intensity.x);
	content = (t_obj *)w.objs->content;
	cr_expect(matrix_cmp_4(content->transform, s1->transform) == 0);
	content = (t_obj *)w.objs->next->content;
	cr_expect(matrix_cmp_4(content->transform, s2->transform) == 0);
}

Test(World, default1)
{
	t_obj	*s2;
	t_xs	xs;
	t_ray	r;

	s2 = void_obj();
	s2->transform = scaling(0.5, 0.5, 0.5);
	r = create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
	xs = intersect(s2, r);
	cr_expect(xs.count == 2);
	cr_expect(xs.x0 == 4.5);
	cr_expect(xs.x1 == 5.5);
}

Test(World, shadow_hit)
{
	t_world		w;
	t_ray		r;
	t_xs_world	xs_world;
	t_comp		comp;
	t_tuple 	c;

	w = default_world();
	r = create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
	xs_world = intersect_world(w, r);
	comp = prepare_comp(xs_world.tab_xs[0], r);
	printf("first xs.t = %f\n", xs_world.tab_xs[0].t);
	c = shade_hit(w, comp);
	printf("c.x = %f\n", c.x);
	printf("c.y = %f\n", c.y);
	printf("c.z = %f\n", c.z);
	cr_expect(fabs(c.x - 0.38066) < EPSILON);
	cr_expect(fabs(c.y - 0.47583) < EPSILON);
	cr_expect(fabs(c.z - 0.2855) < EPSILON);
}

Test(World, shadow_hit2)
{
	t_world		w;
	t_ray		r;
	t_xs		xs;
	t_comp		comp;
	t_tuple 	c;
	t_obj		*obj;

	w = default_world();
	w.light = point_light(create_point(0, 0.25, 0), create_color(1, 1, 1));
	r = create_ray(create_point(0, 0, 0), create_vector(0, 0, 1));
	obj = (t_obj *)w.objs->next->content;
	xs = intersect(obj, r);
	printf("shadow_hit2:\n");
	printf("xs.t = %f\n", xs.t);
	printf("xs.x0 = %f\n", xs.x0);
	printf("xs.x1 = %f\n", xs.x1);
	comp = prepare_comp(xs, r);
	c = shade_hit(w, comp);
	printf("c.x = %f\n", c.x);
	printf("c.y = %f\n", c.y);
	printf("c.z = %f\n", c.z);
	cr_expect(fabs(c.x - 0.90498) < EPSILON);
	cr_expect(fabs(c.y - 0.90498) < EPSILON);
	cr_expect(fabs(c.z - 0.90498) < EPSILON);
}

// Test(World, intersect1)
// {
// 	t_world		w;
// 	t_ray		r;
// 	t_xs_world	xs_world;

// 	w = default_world();
// 	r = create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
// 	xs_world = intersect_world(w, r);
// 	cr_expect(xs_world.count == 2);
// 	cr_expect(xs_world.tab_xs[0].t == 4);
// 	cr_expect(xs_world.tab_xs[1].t == 4.5);
// }
