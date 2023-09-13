#include <criterion.h>
#include "../project.h"

Test(intersections, prepare_comp1)
{
	t_ray		r;
	t_obj		*obj;
	t_xs		xs;
	t_comp		comp;

	r = create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
	obj = void_obj();
	xs = intersect(obj, r);
	comp = prepare_comp(xs, r);
	cr_expect(comp.t == xs.t);
	cr_expect(comp.obj == xs.obj);
	cr_expect(comp.point.x == 0);
	cr_expect(comp.point.y == 0);
	cr_expect(comp.point.z == -1);
	cr_expect(comp.eyev.x == 0);
	cr_expect(comp.eyev.y == 0);
	cr_expect(comp.eyev.z == -1);
	cr_expect(comp.normalv.x == 0);
	cr_expect(comp.normalv.y == 0);
	cr_expect(comp.normalv.z == -1);
}

Test(intersections, prepare_comp2)
{
	t_ray		r;
	t_obj		*obj;
	t_xs		xs;
	t_comp		comp;

	r = create_ray(create_point(0, 0, 0), create_vector(0, 0, 1));
	obj = void_obj();
	xs = intersect(obj, r);
	xs.t = 1;
	comp = prepare_comp(xs, r);
	cr_expect(comp.t == xs.t);
	cr_expect(comp.obj == xs.obj);
	cr_expect(comp.point.x == 0);
	cr_expect(comp.point.y == 0);
	cr_expect(comp.point.z == 1);
	cr_expect(comp.eyev.x == 0);
	cr_expect(comp.eyev.y == 0);
	cr_expect(comp.eyev.z == -1);
	cr_expect(comp.normalv.x == 0);
	cr_expect(comp.normalv.y == 0);
	cr_expect(comp.normalv.z == -1);
	cr_expect(comp.inside == 1);
}

Test(color_at, color_at1)
{
	t_world		w;
	t_ray		r;
	t_tuple		c;

	w = default_world();
	r = create_ray(create_point(0, 0, -5), create_vector(0, 1, 0));
	c = color_at(w, r);
	cr_expect(c.x == 0);
	cr_expect(c.y == 0);
	cr_expect(c.z == 0);
}

Test(color_at, color_at2)
{
	t_world		w;
	t_ray		r;
	t_tuple		c;

	w = default_world();
	r = create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
	c = color_at(w, r);
	cr_expect(fabs(c.x - 0.38066) < EPSILON);
	cr_expect(fabs(c.y - 0.47583) < EPSILON);
	cr_expect(fabs(c.z - 0.2855) < EPSILON);
}

Test(color_at, behind_the_ray)
{
	t_world		w;
	t_obj		*outer;
	t_obj		*inner;
	t_ray		r;
	t_tuple		c;

	w = default_world();
	outer = (t_obj *)w.objs->content;
	outer->material.ambient = 1;
	inner = (t_obj *)w.objs->next->content;
	inner->material.ambient = 1;
	r = create_ray(create_point(0, 0, 0.75), create_vector(0, 0, -1));
	c = color_at(w, r);
	cr_expect(c.x == inner->material.color.x);
	cr_expect(c.y == inner->material.color.y);
	cr_expect(c.z == inner->material.color.z);
}
