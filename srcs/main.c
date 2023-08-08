/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:38:25 by avedrenn          #+#    #+#             */
/*   Updated: 2023/08/08 16:57:02 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"


int	main(int argc, char **argv)
{
	t_scene scene;

	if (argc != 2)
	{
		printf("Invalid number of argument. \n");
		return (1);
	}
	init_scene(&scene);
	parse_scene(argv[1], &scene);
	printf("Hello World!\n");
	return (0);
}