/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjoves <brjoves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:37:14 by jubaldo           #+#    #+#             */
/*   Updated: 2024/05/27 23:45:15 by brjoves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	calc_step_and_side_dist(t_cub3d *game, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->player.pos_x - ray->map_x) \
							* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - game->player.pos_x) \
							* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->player.pos_y - ray->map_y) \
							* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - game->player.pos_y) \
							* ray->delta_dist_y;
	}
}

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

void	calc_all(t_cub3d *game, t_ray *ray)
{
	calc_perp_wall_dist(game, ray);
	calc_line_height(game, ray);
}
