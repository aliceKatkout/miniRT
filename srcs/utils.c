/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:12:44 by avedrenn          #+#    #+#             */
/*   Updated: 2023/08/08 22:29:40 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../miniRT.h"

void	ft_error(char *error)
{
	ft_putstr_fd("Error\n❌ ", 2);
	ft_putstr_fd(error, 2);
	exit(1);
}

int ft_arrlen(void **array)
{
	int	i;
	
	i = 0;
	if (!array)
		return (i);
	while (array[i])
		i ++;
	return (i);
}

void	ft_free_arr(void **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

