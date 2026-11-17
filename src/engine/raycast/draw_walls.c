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
	int		tex_num;
	double	wall_x;

	tex_num = game->map[ray->map_x][ray->map_y] - 1;
	if (ray->side == 0)
		wall_x = game->player.pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = game->player.pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x = floor(wall_x);
}

// side 0 == EAST | WEST
// side 1 == NORTH | SOUTH
// side 0 + raydir_x > 0 = WEST
// side 1 + ray_dir_x < 0 =  SOUTH

void	draw_walls(t_game *game, t_ray *ray, int x)
{
	int	y;
	int	color;

	y = 0;
	ray->draw_start = HEIGHT / 2 - ray->line_height / 2;
	ray->draw_end = HEIGHT / 2 + ray->line_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->draw_start == HEIGHT)
		ray->draw_start = HEIGHT - 1;
	color = 0x0ff00ff; // get_pixel(&game->w_est, x, y);
	if (ray->side == 1)
		color = 0x0dea943;
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		put_pixel(x, y, color, game);
		y++;
	}
}

/*
static void	render_texture(t_game *game, t_img *img, int posx, int posy)
{
	int				x;
	int				y;
	unsigned int	color;

	if (posx < 0 || posx >= WIDTH || posy < 0 || posy >= HEIGHT)
		return ;
	y = 0;
	while (y < img->heigth)
	{
		x = 0;
		while (x < img->width)
		{
			color = get_pixel(img, x, y);
			if (color != 0xff000000)
				put_pixel(posx + x, posy + y, color, game);
			x++;
		}
		y++;
	}
}
*/
