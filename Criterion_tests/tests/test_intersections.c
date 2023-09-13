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