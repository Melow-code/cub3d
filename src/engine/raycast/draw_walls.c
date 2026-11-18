/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 13:13:45 by rpinheir          #+#    #+#             */
/*   Updated: 2026/11/17 13:36:04 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	choose_wall(t_game *game, t_ray *ray)
{
	double	wall_x;

	if (ray->side == 0)
		wall_x = game->player.pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = game->player.pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	if (ray->side == 0 && ray->ray_dir_x < 0)
		ray->texture = &game->w_est;
	else if (ray->side == 0 && ray->ray_dir_x > 0)
		ray->texture = &game->w_west;
	else if (ray->side == 1 && ray->ray_dir_y > 0)
		ray->texture = &game->w_north;
	else
		ray->texture = &game->w_south;
	ray->tex_x = (int)(wall_x * ray->texture->width);
	if ((ray->side == 0 && ray->ray_dir_x > 0) || (ray->side == 1
			&& ray->ray_dir_y < 0))
		ray->tex_x = ray->texture->width - ray->tex_x - 1;
	ray->tex_step = (double)ray->texture->heigth / ray->line_height;
	ray->tex_pos = (ray->draw_start - HEIGHT / 2 + ray->line_height / 2)
		* ray->tex_step;
}

void	draw_walls(t_game *game, t_ray *ray, int x)
{
	int	y;
	int	color;

	y = 0;
	ray->draw_start = HEIGHT / 2 - ray->line_height / 2;
	ray->draw_end = HEIGHT / 2 + ray->line_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
	y = ray->draw_start;
	choose_wall(game, ray);
	while (y <= ray->draw_end)
	{
		ray->tex_y = (int)ray->tex_pos;
		color = get_pixel(ray->texture, ray->tex_x, ray->tex_y);
		if (ray->tex_y > ray->texture->heigth)
			ray->tex_y = ray->texture->heigth;
		ray->tex_pos += ray->tex_step;
		put_pixel(x, y, color, game);
		y++;
	}
}
