/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjoves <brjoves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 18:04:56 by jubaldo           #+#    #+#             */
/*   Updated: 2024/05/27 23:44:29 by brjoves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void parse_map(t_cub3d *game, char *line) {
    static char **map_lines = NULL;
    static int map_height = 0;

    // Allocate memory for new line
    char **new_map_lines = malloc(sizeof(char *) * (map_height + 1));
    if (!new_map_lines)
        error_exit(game, "Error: Memory allocation failed");
    
    // Copy existing lines to new array
    for (int i = 0; i < map_height; i++) {
        new_map_lines[i] = map_lines[i];
    }

    // Add new line to the array
    new_map_lines[map_height] = ft_strdup(line);
    if (!new_map_lines[map_height])
        error_exit(game, "Error: Memory allocation failed");

    // Free old map array if necessary
    if (map_lines)
        free(map_lines);
    
    map_lines = new_map_lines;
    map_height++;

    game->map = map_lines;
    game->map_height = map_height;
    game->map_width = strlen(line); // Assumes all lines have the same length
}
