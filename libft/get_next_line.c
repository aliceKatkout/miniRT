/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:01:48 by avedrenn          #+#    #+#             */
/*   Updated: 2023/01/17 17:15:57 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free(char	*res, char	*tmp)
{
	if (res)
		free(res);
	if (tmp)
		free(tmp);
	return (NULL);
}

void	set_buf(char buf[BUFFER_SIZE])
{
	long int	i;
	char		*index;

	i = 0;
	index = ft_strchr(buf, 10);
	if (index)
	{
		while (index && index[i + 1])
		{
			buf[i] = index[i + 1];
			i ++;
		}
	}
	else
		i = ft_strlen(buf);
	while (i < BUFFER_SIZE)
	{
		buf[i] = 0;
		i ++;
	}
}

char	*read_line(char buf[BUFFER_SIZE], char *res, int fd)
{
	long int	ret;
	char		*tmp;

	tmp = malloc (BUFFER_SIZE + 1);
	res = ft_strjoin_free(res, buf);
	if (!tmp || !res)
		return (ft_free(res, tmp));
	ret = 1;
	tmp[BUFFER_SIZE] = 0;
	set_buf(buf);
	while (!ft_strchr(res, 10) && ret > 0)
	{
		ft_bzero(tmp, BUFFER_SIZE);
		ret = read(fd, tmp, BUFFER_SIZE);
		res = ft_strjoin_free(res, tmp);
		if (!res)
			return (ft_free(res, tmp));
		ft_strcpy(buf, tmp, ret);
		set_buf(buf);
	}
	if (ret < 0)
		return (ft_free(res, tmp));
	else
		free(tmp);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	buf[100][BUFFER_SIZE + 1] = {{0}, {0}};
	char		*res;

	if (BUFFER_SIZE < 1 || BUFFER_SIZE + 1 > SIZE_MAX)
		return (NULL);
	if (fd < 0 || fd > 99)
		return (NULL);
	res = malloc (BUFFER_SIZE + 1);
	if (!res)
		return (NULL);
	res[0] = 0;
	buf[fd][BUFFER_SIZE] = 0;
	res = read_line(buf[fd], res, fd);
	if (ft_strlen(res) == 0)
	{
		free(res);
		return (NULL);
	}
	return (res);
}

/* int main ()
{
	int	fd;
	//int	fd2;
	char * str;
	str = NULL;
	fd = open("test.txt", O_RDONLY);
	//fd2 = open("test2.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("--> %s\n",str);
	free(str);
	str = get_next_line(fd);
	printf("--> %s\n",str);
	free(str);
	str = get_next_line(fd);
	printf("--> %s\n",str);
	free(str);
} */
