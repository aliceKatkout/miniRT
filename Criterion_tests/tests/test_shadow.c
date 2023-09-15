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

Test(shadow, shade_hit_inshadow)
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
	w.objs->content = (void *)obj1;
	w.objs->next->content = (void *)obj2;
	r = create_ray(create_point(0, 0, 5), create_vector(0, 0, 1));
	xs = intersect_world(w, r);
	comp = prepare_comp(xs.tab_xs[0], r);
	c = shade_hit(w, comp);
	cr_expect(fabs(c.x - 0.1) < EPSILON);
	cr_expect(fabs(c.y - 0.1) < EPSILON);
	cr_expect(fabs(c.z - 0.1) < EPSILON);
}

Test(shadow, over_point)
{
	t_obj	*obj1;
	t_ray	r;
	t_xs	xs;
	t_comp	comp;

	r = create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
	obj1 = void_obj();
	obj1->transform = translation(0, 0, 1);
	xs = intersect(obj1, r);
	comp = prepare_comp(xs, r);
	cr_expect(comp.over_point.z < -EPSILON/2);
	cr_expect(comp.point.z > comp.over_point.z);
}