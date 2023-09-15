#include <criterion.h>
#include "../project.h"

Test(camera, construct_camera)
{
	t_cam	c;

	c = create_camera(160, 120, (M_PI / 2));
	cr_expect(c.hsize == 160);
	cr_expect(c.vsize == 120);
	cr_expect(fabs(c.fov - M_PI / 2) < EPSILON);
	cr_expect(matrix_cmp_4(c.transform, identity_matrix()) == 0);
	(void)c;
}

Test(camera, pixel_size)
{
	t_cam	c;

	c = create_camera(200, 125, M_PI / 2);
	cr_expect(fabs(c.pixel_size - 0.01) < EPSILON);
	c = create_camera(125, 200, M_PI / 2);
	cr_expect(fabs(c.pixel_size - 0.01) < EPSILON);
}

Test(camera, ray_pixel_center)
{
	t_cam	c;
	t_ray	r;

	c = create_camera(201, 101, M_PI / 2);
	r = ray_for_pixel(c, 100, 50);
	cr_expect(r.origin.x == 0);
	cr_expect(r.origin.y == 0);
	cr_expect(r.origin.z == 0);
	cr_expect(fabs(r.direction.x - 0) < EPSILON);
	cr_expect(fabs(r.direction.y - 0) < EPSILON);
	cr_expect(fabs(r.direction.z - -1) < EPSILON);
}

Test(camera, ray_pixel_corner)
{
	t_cam	c;
	t_ray	r;

	c = create_camera(201, 101, M_PI / 2);
	r = ray_for_pixel(c, 0, 0);
	cr_expect(r.origin.x == 0);
	cr_expect(r.origin.y == 0);
	cr_expect(r.origin.z == 0);
	cr_expect(fabs(r.direction.x - 0.66519) < EPSILON);
	cr_expect(fabs(r.direction.y - 0.33259) < EPSILON);
	cr_expect(fabs(r.direction.z - -0.66851) < EPSILON);
}

Test(camera, ray_pixel_transformed)
{
	t_cam	c;
	t_ray	r;

	c = create_camera(201, 101, M_PI / 2);
	c.transform = matrix_mult_4(rotation_y(M_PI / 4),translation(0, -2, 5));
	r = ray_for_pixel(c, 100, 50);
	cr_expect(r.origin.x == 0);
	cr_expect(r.origin.y == 2);
	cr_expect(r.origin.z == -5);
	cr_expect(fabs(r.direction.x - sqrt(2) / 2) < EPSILON);
	cr_expect(fabs(r.direction.y - 0) < EPSILON);
	cr_expect(fabs(r.direction.z - -sqrt(2) / 2) < EPSILON);
}
/*
Test(camera, render_cam1)
{
	t_world	w;
	t_cam	c;
	t_tuple	from;
	t_tuple	to;
	t_tuple	up;
	t_world	image;

	w = default_world();
	c = create_camera(11, 11, M_PI / 2);
	from = create_point(0, 0, -5);
	to = create_point(0, 0, 0);
	up = create_vector(0, 1, 0);
	c.transform = view_transform(from, to, up);
	image = render_cam(c, w);
	cr_expect(pixel_at(image, 5, 5)
		== color(0.38066, 0.47583, 0.2855))

//	pixel_at(c, 2, 3) -> renvoie la couleur
//	au pixel donne (2, 3) dans le canvas 'c'
//	write_pixel(c, 2, 3, red) -> img_pixel_put?
}*/