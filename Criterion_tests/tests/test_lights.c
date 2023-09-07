#include <criterion.h>
#include "../project.h"

Test(light, normal1)
{
	t_sphere	s;
	t_tuple		n;
	t_tuple		vec;

	s = void_sphere();
	n = normal_at(s, create_point(1, 0, 0));
	vec = create_vector(1, 0, 0);
	cr_expect(n.x == vec.x);
	cr_expect(n.y == vec.y);
	cr_expect(n.z == vec.z);
	n = normal_at(s, create_point(0, 1, 0));
	vec = create_vector(0, 1, 0);
	cr_expect(n.x == vec.x);
	cr_expect(n.y == vec.y);
	cr_expect(n.z == vec.z);
	n = normal_at(s, create_point(0, 0, 1));
	vec = create_vector(0, 0, 1);
	cr_expect(n.x == vec.x);
	cr_expect(n.y == vec.y);
	cr_expect(n.z == vec.z);
	n = normal_at(s, create_point(sqrt(3)/3, sqrt(3)/3, sqrt(3)/3));
	vec = create_vector(sqrt(3)/3, sqrt(3)/3, sqrt(3)/3);
	cr_expect(n.x == vec.x);
	cr_expect(n.y == vec.y);
	cr_expect(n.z == vec.z);
}

Test(light, normalize)
{
	t_sphere	s;
	t_tuple		n;
	t_tuple		cmp;

	s = void_sphere();
	n = normal_at(s, create_point(sqrt(3)/3, sqrt(3)/3, sqrt(3)/3));
	cr_expect(n.x == sqrt(3)/3);
	cr_expect(n.y == sqrt(3)/3);
	cr_expect(n.z == sqrt(3)/3);
	cmp = normalize(n);
	cr_expect(fabs(n.x - cmp.x) < EPSILON);
	cr_expect(fabs(n.y - cmp.y) < EPSILON);
	cr_expect(fabs(n.z - cmp.z) < EPSILON);
}

Test(light, normal2)
{
	t_sphere	s;
	t_tuple		n;
	set_transform(&s, translation(0, 1, 0));
	n = normal_at(s, create_point(0, 1.70711, -0.70711));
	cr_expect(n.x - 0 < EPSILON);
	cr_expect(n.y - 0.70711 < EPSILON);
	cr_expect(n.z - -0.70711 < EPSILON);
}

Test(light, normal3)
{
	t_sphere	s;
	t_tuple		n;
	t_matrix_4	m;

	s = void_sphere();
	m = scaling(1, 0.5, 1);
	m = rotation_z(M_PI / 5);
	set_transform(&s, m);
	n = normal_at(s, create_point(0, sqrt(2)/2, (-sqrt(2))/2));
	cr_expect(n.x - 0 < EPSILON);
	cr_expect(n.y - 0.97014 < EPSILON);
	cr_expect(n.z - -0.24254 < EPSILON);
}

Test(light, lighting1)
{
	//page 86
	t_material	m = init_material();
	t_tuple position = create_point(0, 0, 0);
	t_light	light;
	t_tuple	result;
	t_tuple	eyev = create_vector(0, 0, -1);
	t_tuple	normalv = create_vector(0, 0, -1);
	light = point_light(create_point(0, 0, -10), create_color(1, 1, 1));
	result = lighting(m, light, position, eyev, normalv);
	cr_expect(result.x == 1.9);
	cr_expect(result.y == 1.9);
	cr_expect(result.z == 1.9);
}

Test(light, lighting2)
{
	//page 86
	t_material	m = init_material();
	t_tuple position = create_point(0, 0, 0);
	t_light	light;
	t_tuple	result;
	t_tuple	eyev = create_vector(0, sqrt(2)/2, -sqrt(2)/2);
	t_tuple	normalv = create_vector(0, 0, -1);
	light = point_light(create_point(0, 0, -10), create_color(1, 1, 1));
	result = lighting(m, light, position, eyev, normalv);
	cr_expect(result.x == 1.0);
	cr_expect(result.y == 1.0);
	cr_expect(result.z == 1.0);
}

Test(light, lighting3)
{
	//page 87
	t_material	m = init_material();
	t_tuple position = create_point(0, 0, 0);
	t_light	light;
	t_tuple	result;
	t_tuple	eyev = create_vector(0, 0, -1);
	t_tuple	normalv = create_vector(0, 0, -1);
	light = point_light(create_point(0, 10, -10), create_color(1, 1, 1));
	result = lighting(m, light, position, eyev, normalv);
	cr_expect(fabs(result.x - 0.7364) < EPSILON);
	cr_expect(fabs(result.y - 0.7364) < EPSILON);
	cr_expect(fabs(result.z - 0.7364) < EPSILON);
}

Test(light, lighting4)
{
	//page 87
	t_material	m = init_material();
	t_tuple position = create_point(0, 0, 0);
	t_light	light;
	t_tuple	result;
	t_tuple	eyev = create_vector(0, -sqrt(2)/2, -sqrt(2)/2);
	t_tuple	normalv = create_vector(0, 0, -1);
	light = point_light(create_point(0, 10, -10), create_color(1, 1, 1));
	result = lighting(m, light, position, eyev, normalv);
	cr_expect(fabs(result.x - 1.6364) < EPSILON);
	cr_expect(fabs(result.y - 1.6364) < EPSILON);
	cr_expect(fabs(result.z - 1.6364) < EPSILON);
}

Test(light, lighting5)
{
	//page 88
	t_material	m = init_material();
	t_tuple position = create_point(0, 0, 0);
	t_light	light;
	t_tuple	result;
	t_tuple	eyev = create_vector(0, 0, -1);
	t_tuple	normalv = create_vector(0, 0, -1);
	light = point_light(create_point(0, 0, 10), create_color(1, 1, 1));
	result = lighting(m, light, position, eyev, normalv);
	cr_expect(result.x == 0.1);
	cr_expect(result.y == 0.1);
	cr_expect(result.z == 0.1);
}
