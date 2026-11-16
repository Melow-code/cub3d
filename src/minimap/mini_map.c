/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ch <chguerre@42lausanne.ch>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 17:24:29 by ch                #+#    #+#             */
/*   Updated: 2026/11/16 19:53:39 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	draw_square_tile(t_game *game, t_minimap *m, double pos_x, double pos_y)
{
	int			x;
	int			y;
	int			pixel_x;
	int			pixel_y;

	y = 0;
	while (y < m->tile_size - 1)
	{
		x = 0;
		while (x < m->tile_size - 1)
		{
			pixel_x = pos_x + x;
			pixel_y = pos_y + y;
			if (pixel_x >= 0 && pixel_x < WIDTH
				&& pixel_y >= 0 && pixel_y < HEIGHT)
				put_pixel(pixel_x, pixel_y, m->color_tile, game);
			x++;
		}
		y++;
	}
}

double	*posicion_minimapa(t_game *game, t_minimap *m, double mini_pos[2])
{
	mini_pos[0] = (double)MINI_OFFSET_X + (game->player.pos_x
			* (double)m->tile_size);
	mini_pos[1] = (double)MINI_OFFSET_Y + (game->player.pos_y
			* (double)m->tile_size);
	return (mini_pos);
}

void	draw_map(t_game *game, t_minimap *m, int map_width, int map_height)
{
	int	mx;
	int	my;
	int	pos_x;
	int	pos_y;

	my = 0;
	while (my <= map_height - 1)
	{
		mx = 0;
		while (mx < map_width && game->map[my][mx])
		{
			m->color_tile = select_color(game->map[my][mx],
					game->player.orientation);
			pos_x = MINI_OFFSET_X + (mx * m->tile_size);
			pos_y = MINI_OFFSET_Y + (my * m->tile_size);
			draw_square_tile(game, m, pos_x, pos_y);
			mx++;
		}
		my++;
	}
}

void	generate_minimap(t_game *game)
{
	double			mini_pos[2];
	t_line			line;
	t_minimap		mini_map;

	ft_bzero(&line, sizeof(line));
	ft_bzero(&mini_map, sizeof(mini_map));
	calculate_size(game, &mini_map);
	mini_map.tile_size = calculate_tile(mini_map.width, mini_map.height);
	draw_map(game, &mini_map, mini_map.width, mini_map.height);
	posicion_minimapa(game, &mini_map, mini_pos);
	draw_minimap_player(game, mini_pos[0], mini_pos[1]);
	mini_dir_player(game, &line, &mini_map);
}
