#include <criterion.h>
#include "../project.h"

Test(rays, rays1)
{
	//Arrange
	t_tuple	origin = create_point(2, 3, 4);
	t_tuple	direction = create_vector(1, 0, 0);
	t_ray	ray;
	t_tuple	pos;
	//Act
	ray = create_ray(origin, direction);
	pos = position(ray, 0);
	//Assert
	cr_expect(pos.x == 2);
	cr_expect(pos.y == 3);
	cr_expect(pos.z == 4);

	pos = position(ray, 1);
	cr_expect(pos.x == 3);
	cr_expect(pos.y == 3);
	cr_expect(pos.z == 4);

	pos = position(ray, -1);
	cr_expect(pos.x == 1);
	cr_expect(pos.y == 3);
	cr_expect(pos.z == 4);

	pos = position(ray, 2.5);
	cr_expect(pos.x == 4.5);
	cr_expect(pos.y == 3);
	cr_expect(pos.z == 4);
}