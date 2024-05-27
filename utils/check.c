/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 22:19:42 by jubaldo           #+#    #+#             */
/*   Updated: 2024/05/27 17:57:49 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_within_bounds(t_cub3d *game, double x, double y)
{
	return (x >= 0 && x < game->map_width && y >= 0 && y < game->map_height);
}

int	is_space(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r'
		|| c == '\v' || c == '\f')
		return (c);
	return (0);
}

int	is_map_line(char *line)
{
	if (line == NULL)
		return (0);
	while (*line)
	{
		if (*line != '0' && *line != '1' && *line != 'N' && *line != 'S' && \
				*line != 'E' && *line != 'W' && !is_space((unsigned char)*line))
			return (0);
		line++;
	}
	return (1);
}
