
#include "../project.h"

// t_projectile	ft_tick(t_env env, t_projectile proj)
// {
// 	t_projectile	ret;
// 	ret.position = add_tuples(proj.position, proj.velocity);
// 	ret.velocity = add_tuples(proj.velocity, env.gravity);
// 	ret.velocity = add_tuples(ret.velocity, env.wind);
// 	return (ret);
// }

int	main(void)
{
	t_data	data;

	// ft_bzero(&data, sizeof(data));
	// int		i;
	t_tuple	red;
	init_canvas(&data);
	// i = 0;
	// data.proj.position = create_point(4, 12, 3);
	// data.proj.velocity = create_vector(1, 1, 0);
	// data.env.gravity = create_vector(0, 5, 3);
	// data.env.wind = create_vector(-0.02, 10, 0);
	// printf("BEFORE, proj.x is : %f\n", data.proj.position.x);
	// printf("proj.y is : %f\n", data.proj.position.y);
	// printf("proj.z is : %f\n\n", data.proj.position.z);

	// data.canvas.w = 10;
	// data.canvas.h = 20;

	red = create_color(1, 0, 0);
	// write_pix_canvas(data.canvas, 2, 3, red);

	// while (data.proj.position.x >= 0)
	// {
	// 	data.proj = ft_tick(data.env, data.proj);
	// 	printf("AFTER %d, proj.x: %f\n", i, data.proj.position.x);
	// 	printf("y: %f\n", data.proj.position.y);
	// 	printf("z: %f\n\n", data.proj.position.z);
	// 	i++;
	// }
	printf("red : %f\n", red.x);
	return (0);
}