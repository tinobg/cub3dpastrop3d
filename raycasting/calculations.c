/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:37:14 by jubaldo           #+#    #+#             */
/*   Updated: 2024/05/28 00:27:57 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void calc_perp_wall_dist(t_cub3d *game, t_ray *ray) {
    if (ray->side == 0)
        ray->perp_wall_dist = (ray->map_x - game->player.pos_x + (1 - ray->step_x) / 2) / ray->ray_dir_x;
    else
        ray->perp_wall_dist = (ray->map_y - game->player.pos_y + (1 - ray->step_y) / 2) / ray->ray_dir_y;
}

void calc_line_height(t_cub3d *game, t_ray *ray) {
    ray->line_height = (int)(game->win_height / ray->perp_wall_dist);
    ray->draw_start = -ray->line_height / 2 + game->win_height / 2;
    if (ray->draw_start < 0)
        ray->draw_start = 0;
    ray->draw_end = ray->line_height / 2 + game->win_height / 2;
    if (ray->draw_end >= game->win_height)
        ray->draw_end = game->win_height - 1;
}
