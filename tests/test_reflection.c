#include <criterion.h>
#include "../miniRT.h"


Test(reflection, reflect1)
{
	t_tuple		v;
	t_tuple		n;
	t_tuple		r;

	v = create_vector(1, -1, 0);
	n = create_vector(0, 1, 0);
	r = reflect(v, n);
	cr_expect(r.x - 1 < EPSILON);
	cr_expect(r.y - 1 < EPSILON);
	cr_expect(r.z - 0 < EPSILON);
}

Test(reflection, reflect2)
{
	t_tuple		v;
	t_tuple		n;
	t_tuple		r;

	v = create_vector(1, -1, 0);
	n = create_vector(sqrt(2)/2, sqrt(2)/2, 0);
	r = reflect(v, n);
	cr_expect(r.x - 1 < EPSILON);
	cr_expect(r.y - 0 < EPSILON);
	cr_expect(r.z - 0 < EPSILON);
}

Test(reflection, reflection1)
{
	t_tuple	intensity;
	t_tuple	position;
	t_light	light;

	intensity = create_color(255, 255, 255);
	position = create_point(0, 0, 0);
	light = point_light(position, intensity);
	cr_expect(light.position.x == position.x);
	cr_expect(light.position.y == position.y);
	cr_expect(light.position.z == position.z);
	cr_expect(light.intensity.x == intensity.x);
	cr_expect(light.intensity.y == intensity.y);
	cr_expect(light.intensity.z == intensity.z);
}

Test(reflection, material1)
{
	t_obj		*s;
	t_material	m;

	s = void_obj();
	m = init_material();
	m.ambient = 1;
	s->material = m;
	cr_expect(s->material.ambient == m.ambient);
	cr_expect(s->material.diffuse == m.diffuse);
	cr_expect(s->material.specular == m.specular);
}