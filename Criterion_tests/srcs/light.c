#include "../project.h"

t_light	point_light(t_tuple l_position, t_tuple l_color)
{
	t_light	light;

	light.position = l_position;
	light.intensity = l_color;
	return (light);
}