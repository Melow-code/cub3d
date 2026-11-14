/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ch <chguerre@42lausanne.ch>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 17:24:29 by ch                #+#    #+#             */
/*   Updated: 2026/11/12 17:24:59 by ch               ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

unsigned int	select_color(char c, char orientation)
{
	if (c == '1')
		return (0xFFFFFF);
	else if (c == '0' || c == orientation)
		return (0x1E293B);
	return (0);
}

void	draw_square_tile(t_game *game, double pos_x, double pos_y, int scale, unsigned int color )
{
	int	x;
	int	y;
	int	pixel_x;
	int	pixel_y;

	y = 0;
	while (y < scale - 1)
	{
		x = 0;
		while (x < scale -1)
		{
			pixel_x = pos_x + x;
			pixel_y = pos_y + y;

			if (pixel_x >= 0 && pixel_x < WIDTH
				&& pixel_y >= 0 && pixel_y < HEIGHT)
				put_pixel(pixel_x, pixel_y, color, game);
			x++;
		}
		y++;
	}
}

double	*posicion_minimapa(t_game *game, double mini_pos[2])
{
	mini_pos[0] = (double)MINI_OFFSET_X + (game->player.pos_x * (double)TILE_SIZE);
	mini_pos[1] = (double)MINI_OFFSET_Y + (game->player.pos_y * (double)TILE_SIZE);
	return (mini_pos);
}

void generate_minimap(t_game *game, int map_width, int map_height)
{
	int				mx;
	int				my;
	int				pos_x;
	int				pos_y;
	double 			mini_pos[2];
	unsigned int	color;
	t_line			line;

	ft_bzero(&line, sizeof(line));
	my = 0;
	while (my <= map_height - 1)
	{
		mx = 0;
		while (mx <= map_width - 1)
		{
			color = select_color(game->map[my][mx], game->player.orientation);
			pos_x = MINI_OFFSET_X + (mx * TILE_SIZE);
			pos_y = MINI_OFFSET_Y + (my * TILE_SIZE);
			draw_square_tile(game, pos_x, pos_y, TILE_SIZE, color);
			mx++;
		}
		my++;
	}
	posicion_minimapa(game, mini_pos);
	draw_minimap_player(game, mini_pos[0], mini_pos[1]);
	mini_dir_player(game, &line);
}
