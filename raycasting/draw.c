/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjoves <brjoves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 20:20:05 by jubaldo           #+#    #+#             */
/*   Updated: 2024/05/27 23:45:29 by brjoves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	get_texture_index(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			return (0);
		else
			return (1);
	}
	else
	{
		if (ray->ray_dir_y > 0)
			return (2);
		else
			return (3);
	}
}

void	init_draw_params(t_draw_params *params, t_cub3d *game, \
							t_ray *ray, int line_height)
{
	double	wall_x;

	params->draw_start = get_draw_start(line_height, game->win_height);
	params->draw_end = get_draw_end(line_height, game->win_height);
	wall_x = get_wall_x(ray, &game->player);
	params->texture_x = get_texture_x(ray, wall_x);
	params->step = 1.0 * TEX_HEIGHT / line_height;
	params->texture_pos = (params->draw_start - game->win_height / 2 + \
							line_height / 2) * params->step;
}

void	draw_text_line(t_cub3d *game, int x, t_ray *ray, t_draw_params *params)
{
	int	y;
	int	texture_y;
	int	texture_index;
	int	color;

	y = params->draw_start;
	texture_index = get_texture_index(ray);
	while (y < params->draw_end)
	{
		texture_y = (int)params->texture_pos & (TEX_HEIGHT - 1);
		params->texture_pos += params->step;
		color = game->textures[texture_index].data[texture_y * \
					TEX_WIDTH + params->texture_x];
		if (ray->side == 1)
			color = (color >> 1) & 8355711;
		game->img_data[y * game->win_width + x] = color;
		y++;
	}
}

void draw_line(t_cub3d *game, int x, t_ray *ray) {
    int color;
    int y = ray->draw_start;
    int texture_index = (ray->side == 0) ? ((ray->ray_dir_x > 0) ? 0 : 1) : ((ray->ray_dir_y > 0) ? 2 : 3);
    double wall_x;
    int texture_x;
    double step;
    double texture_pos;
    int texture_y;

    if (ray->side == 0)
        wall_x = game->player.pos_y + ray->perp_wall_dist * ray->ray_dir_y;
    else
        wall_x = game->player.pos_x + ray->perp_wall_dist * ray->ray_dir_x;
    wall_x -= floor(wall_x);

    texture_x = (int)(wall_x * (double)TEX_WIDTH);
    if ((ray->side == 0 && ray->ray_dir_x > 0) || (ray->side == 1 && ray->ray_dir_y < 0))
        texture_x = TEX_WIDTH - texture_x - 1;

    step = 1.0 * TEX_HEIGHT / ray->line_height;
    texture_pos = (ray->draw_start - game->win_height / 2 + ray->line_height / 2) * step;

    while (y < ray->draw_end) {
        texture_y = (int)texture_pos & (TEX_HEIGHT - 1);
        texture_pos += step;
        color = game->textures[texture_index].data[TEX_HEIGHT * texture_y + texture_x];
        if (ray->side == 1)
            color = (color >> 1) & 8355711; // Make y-sides darker
        game->img_data[y * game->win_width + x] = color;
        y++;
    }
}

void	draw_floor_and_ceiling(t_cub3d *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->win_height / 2)
	{
		x = -1;
		while (++x < game->win_width)
			game->img_data[y * game->win_width + x] = \
			(game->ceiling_color.r << 16) | (game->ceiling_color.g << 8) \
				| game->ceiling_color.b;
	}
	y = game->win_height / 2 - 1;
	while (++y < game->win_height)
	{
		x = -1;
		while (++x < game->win_width)
			game->img_data[y * game->win_width + x] = \
			(game->floor_color.r << 16) | (game->floor_color.g << 8) \
				| game->floor_color.b;
	}
}
