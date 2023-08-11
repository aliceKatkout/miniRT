#include "../miniRT.h"

void	print_cam(t_cam *cam)
{
	printf("CAM (C):\n");
	printf("x_view: %f\n", cam->x_view);
	printf("y_view: %f\n", cam->y_view);
	printf("z_view: %f\n", cam->z_view);
	printf("x_vector: %f\n", cam->x_vector);
	printf("y_vector: %f\n", cam->y_vector);
	printf("z_vector: %f\n", cam->z_vector);
	printf("fov: %d\n", cam->fov);
}

void	print_amb(t_amb *amb)
{
	printf("AMBIENT(A):\n");
	printf("lighting: %f\n", amb->lighting);
	printf("r: %d\n", amb->r);
	printf("g: %d\n", amb->g);
	printf("b: %d\n", amb->b);
}

void	print_light(t_light *light)
{
	printf("LIGHT (L):\n");
	printf("x: %f\n", light->x);
	printf("y: %f\n", light->y);
	printf("z: %f\n", light->z);
	printf("brightness: %f\n", light->brightness);
}