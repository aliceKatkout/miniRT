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

Test(View, view_transform0)
{
	t_tuple		from;
	t_tuple		to;
	t_tuple		up;
	t_matrix_4	t;

	from = create_point(0, 0, 0);
	to = create_point(0, 0, -1);
	up = create_vector(0, 1, 0);
	t = view_transform(from, to, up);
	cr_expect(matrix_cmp_4(t, identity_matrix()) == 0);
}

Test(View, view_transform1)
{
	t_tuple		from;
	t_tuple		to;
	t_tuple		up;
	t_matrix_4	t;

	from = create_point(0, 0, 0);
	to = create_point(0, 0, 1);
	up = create_vector(0, 1, 0);
	t = view_transform(from, to, up);
	cr_expect(matrix_cmp_4(t, scaling(-1, 1, -1)) == 0);
}

Test(View, view_transform2)
{
	t_tuple		from;
	t_tuple		to;
	t_tuple		up;
	t_matrix_4	t;

	from = create_point(0, 0, 8);
	to = create_point(0, 0, 0);
	up = create_vector(0, 1, 0);
	t = view_transform(from, to, up);
	cr_expect(matrix_cmp_4(t, translation(0, 0, -8)) == 0);
}

Test(View, view_transform5)
{
	t_tuple		from;
	t_tuple		to;
	t_tuple		up;
	t_matrix_4	t;
	double o[16] = {-0.50709, 0.50709, 0.67612, -2.36643,
			0.76772, 0.60609, 0.12122, -2.82843,
			-0.35857, 0.59761, -0.71714, 0.00000,
			0.00000, 0.00000, 0.00000, 1.00000};

	from = create_point(1, 3, 2);
	to = create_point(4, -2, 8);
	up = create_vector(1, 1, 0);
	t = view_transform(from, to, up);
	cr_expect(matrix_cmp_4(t, create_matrix_4(o)) == 0);
}