/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forms_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:06:37 by avedrenn          #+#    #+#             */
/*   Updated: 2023/08/10 15:09:41 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../miniRT.h"

char **get_params_from_line(char *line, int wanted_nb)
{
	char 	**params;
	int 	params_nb;

	params = ft_split(line, 32);
	if (!params)
		return (NULL);
	params_nb = ft_arrlen((void **) params);
	if (params_nb != wanted_nb)
	{
		ft_putstr_fdi("Error \nInvalid number of parameters for creating a form.\n", 2);
		ft_free_arr((void **) params);
		return (NULL);
	}
	return (params);
}