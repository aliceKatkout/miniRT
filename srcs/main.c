/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:38:25 by avedrenn          #+#    #+#             */
/*   Updated: 2023/08/14 17:23:54 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"


int	main(int argc, char **argv)
{
	t_scene scene;

	if (argc != 2)
	{
		printf("One argument expected. \n");
		return (1);
	}

	init_scene(&scene);
	parse_scene(argv[1], &scene);
	ft_free_parse(&scene, NULL);
	return (0);
}