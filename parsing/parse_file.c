/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjoves <brjoves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:15:48 by jubaldo           #+#    #+#             */
/*   Updated: 2024/05/27 23:44:21 by brjoves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void parse_file(t_cub3d *game, const char *filename) {
    int fd;
    char *line;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        error_exit(game, "Error: Error opening file");

    while (get_next_line(fd, &line) > 0) {
        if (line[0] == 'N' && line[1] == 'O')
            parse_textures(game, line);
        else if (line[0] == 'S' && line[1] == 'O')
            parse_textures(game, line);
        else if (line[0] == 'W' && line[1] == 'E')
            parse_textures(game, line);
        else if (line[0] == 'E' && line[1] == 'A')
            parse_textures(game, line);
        else if (line[0] == 'F')
            parse_color(&game->floor_color, line);
        else if (line[0] == 'C')
            parse_color(&game->ceiling_color, line);
        else
            parse_map(game, line);
        free(line);
    }
    close(fd);

    // Set the player's initial position based on the map
    for (int y = 0; y < game->map_height; y++) {
        for (int x = 0; x < game->map_width; x++) {
            if (game->map[y][x] == 'N') {
                game->player.pos_x = x + 0.5;
                game->player.pos_y = y + 0.5;
                game->player.dir_x = -1;
                game->player.dir_y = 0;
                game->player.plane_x = 0;
                game->player.plane_y = 0.66;
                game->map[y][x] = '0'; // Replace player start position with empty space
            }
        }
    }
}
