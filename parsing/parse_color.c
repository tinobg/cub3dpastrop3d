/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 18:01:11 by jubaldo           #+#    #+#             */
/*   Updated: 2024/05/27 18:05:41 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parse_color(t_color *color, char *line)
{
	char	**tokens;
	int		r;
	int		g;
	int		b;

	tokens = ft_split(line + 2, ',');
	r = ft_atoi(tokens[0]);
	g = ft_atoi(tokens[1]);
	b = ft_atoi(tokens[2]);
	if (!tokens[0] || !tokens[1] || !tokens[2])
	{
		free_tokens(tokens);
		error_exit(NULL, "Error: Invalid color format");
	}
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		free_tokens(tokens);
		error_exit(NULL, "Error: Invalid color values");
	}
	color->r = r;
	color->g = g;
	color->b = b;
	free_tokens(tokens);
}
