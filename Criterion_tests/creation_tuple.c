#include "project.h"

t_tuple	create_point(double x, double y, double z)
{
	t_tuple a;
	
	a.x = x;
	a.y = y;
	a.z = z;
	a.w = 1.0;

	return (a);
}

t_tuple	create_vector(double x, double y, double z)
{
	t_tuple b;

	b.x = x;
	b.y = y;
	b.z = z;
	b.w = 0;
	return (b);
}

int	tuples_cmp(t_tuple a, t_tuple b)
{
	if (fabs(a.x - b.x) < EPSILON)
	{
		if (fabs(a.y - b.y) < EPSILON)
		{
			if (fabs(a.z - b.z) < EPSILON)
				return (1);
		}
	}
	return (0);
}

t_tuple	add_tuples(t_tuple a, t_tuple b)
{
	t_tuple	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
	c.w = a.w + b.w;
	return (c);
}

t_tuple	sub_tuples(t_tuple a, t_tuple b)
{
	t_tuple	c;

	c.x = a.x - b.x;
	c.y = a.y - b.y;
	c.z = a.z - b.z;
	c.w = a.w - b.w;
	return (c);
}