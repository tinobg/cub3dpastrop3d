/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:02:18 by jubaldo           #+#    #+#             */
/*   Updated: 2024/05/25 20:43:52 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_line_height(t_ray *ray, int win_height)
{
	return ((int)(win_height / ray->perp_wall_dist));
}

int	get_draw_start(int line_height, int win_height)
{
	int	draw_start;

	draw_start = -line_height / 2 + win_height / 2;
	if (draw_start < 0)
		draw_start = 0;
	return (draw_start);
}

int	get_draw_end(int line_height, int win_height)
{
	int	draw_end;

	draw_end = line_height / 2 + win_height / 2;
	if (draw_end >= win_height)
		draw_end = win_height - 1;
	return (draw_end);
}

double	get_wall_x(t_ray *ray, t_player *player)
{
	double	wall_x;

	if (ray->side == 0)
		wall_x = player->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = player->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	return (wall_x - floor(wall_x));
}

int	get_texture_x(t_ray *ray, double wall_x)
{
	int	texture_x;

	texture_x = (int)(wall_x * (double)TEX_WIDTH);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		texture_x = TEX_WIDTH - texture_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		texture_x = TEX_WIDTH - texture_x - 1;
	return (texture_x);
}
