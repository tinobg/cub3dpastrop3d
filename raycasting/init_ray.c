/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjoves <brjoves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:31:04 by jubaldo           #+#    #+#             */
/*   Updated: 2024/05/27 23:46:08 by brjoves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void init_ray(t_cub3d *game, t_ray *ray, int x) {
    ray->camera_x = 2 * x / (double)game->win_width - 1;
    ray->ray_dir_x = game->player.dir_x + game->player.plane_x * ray->camera_x;
    ray->ray_dir_y = game->player.dir_y + game->player.plane_y * ray->camera_x;
    ray->map_x = (int)game->player.pos_x;
    ray->map_y = (int)game->player.pos_y;
    ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
    ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
    ray->hit = 0;

    if (ray->ray_dir_x < 0) {
        ray->step_x = -1;
        ray->side_dist_x = (game->player.pos_x - ray->map_x) * ray->delta_dist_x;
    } else {
        ray->step_x = 1;
        ray->side_dist_x = (ray->map_x + 1.0 - game->player.pos_x) * ray->delta_dist_x;
    }
    if (ray->ray_dir_y < 0) {
        ray->step_y = -1;
        ray->side_dist_y = (game->player.pos_y - ray->map_y) * ray->delta_dist_y;
    } else {
        ray->step_y = 1;
        ray->side_dist_y = (ray->map_y + 1.0 - game->player.pos_y) * ray->delta_dist_y;
    }
}
