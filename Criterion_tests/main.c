
#include "project.h"

int	main(void)
{
	// t_data	data;
	t_tuple	a = create_vector(4, 0, 3);
	// t_tuple	b = create_vector(4, -4.2, 3);
	double c;

	c = magn_tuple(a);
	printf("C is : %f\n", c);
	return (0);
}