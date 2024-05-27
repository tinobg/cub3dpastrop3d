/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 04:00:46 by jubaldo           #+#    #+#             */
/*   Updated: 2024/05/18 17:19:52 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*recurs(int depth, int *ret, int fd)
{
	char	buff[1];
	char	*line;
	int		files;

	files = read(fd, buff, 1);
	if (files == 0)
		buff[0] = 0;
	if (buff[0] == '\n' || buff[0] == 0)
	{
		line = malloc(sizeof(char) * depth + 1);
		if (!line)
			return (NULL);
		line[depth] = 0;
		*ret = 1;
		if (buff[0] == 0)
			*ret = 0;
		return (line);
	}
	else
	{
		line = recurs(depth + 1, ret, fd);
		line[depth] = buff[0];
	}
	return (line);
}

int	get_next_line(int fd, char **line)
{
	int	ret;

	ret = 1;
	*line = recurs(0, &ret, fd);
	return (ret);
}
