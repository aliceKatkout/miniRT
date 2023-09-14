#include <criterion.h>
#include "../project.h"

Test(shadow, is_shadowed1)
{
	t_world	w = default_world();
	t_tuple	p = create_point(0, 10, 0);
	
	cr_expect(is_shadowed(w, p) == 0);
}

Test(shadow, is_shadowed2)
{
	t_world	w = default_world();
	t_tuple	p = create_point(10, -10, 0);
	
	printf("is_shadowed(w, p): %d\n", is_shadowed(w, p));
	cr_expect(is_shadowed(w, p) == 1);
}

Test(shadow, is_shadowed3)
{
	t_world	w = default_world();
	t_tuple	p = create_point(-20, 20, -20);

	cr_expect(is_shadowed(w, p) == 0);
}

Test(shadow, is_shadowed4)
{
	t_world	w = default_world();
	t_tuple	p = create_point(-2, 2, -2);

	cr_expect(is_shadowed(w, p) == 0);
}
