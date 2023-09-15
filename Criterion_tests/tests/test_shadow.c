#include <criterion.h>
#include "../project.h"

Test(shadow, is_shadowed1)
{
	t_world	w = default_world();
	t_tuple	p = create_point(0, 10, 0);
	
	cr_expect(is_shadowed(w, p) == 0);
}

Test(shadow, is_shadowed2)
{
	t_world	w = default_world();
	t_tuple	p = create_point(10, -10, 10);
	
	cr_expect(is_shadowed(w, p) == 1);
}

Test(shadow, is_shadowed3)
{
	t_world	w = default_world();
	t_tuple	p = create_point(-20, 20, -20);

	cr_expect(is_shadowed(w, p) == 0);
}

Test(shadow, is_shadowed4)
{
	t_world	w = default_world();
	t_tuple	p = create_point(-2, 2, -2);

	cr_expect(is_shadowed(w, p) == 0);
}

Test(hadow, shade_hit_inshadow)
{
	t_world	w;
	t_obj	*obj1;
	t_obj	*obj2;
	t_ray	r;
	t_xs_world	xs;
	t_comp	comp;
	t_tuple c;

	w = default_world();
	w.light = point_light(create_point(0, 0, -10), create_color(1, 1, 1));
	obj1 = void_obj();
	obj2 = void_obj();
	obj2->transform = translation(0, 0, 10);
	obj1 = (t_obj *)w.objs->content;
	obj2 = (t_obj *)w.objs->next->content;
	r = create_ray(create_point(0, 0, 5), create_vector(0, 0, 1));
	xs = intersect_world(w, r);
	comp = prepare_comp(xs, r);
	c = shade_hit(w, comp);
	cr_expect(fabs(c.x - 0.1) < EPSILON);
	cr_expect(fabs(c.y - 0.1) < EPSILON);
	cr_expect(fabs(c.z - 0.1) < EPSILON);
}