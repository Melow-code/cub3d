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

void	draw_square_tile(t_game *game, t_minimap *m, double pos_x, double pos_y, unsigned int color )
{
	int			x;
	int			y;
	int			pixel_x;
	int			pixel_y;

	y = 0;
	while (y < m->tile_size- 1)
	{
		x = 0;
		while (x < m->tile_size - 1)
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

double	*posicion_minimapa(t_game *game, t_minimap *m, double mini_pos[2])
{
	mini_pos[0] = (double)MINI_OFFSET_X + (game->player.pos_x * (double)m->tile_size);
	mini_pos[1] = (double)MINI_OFFSET_Y + (game->player.pos_y * (double)m->tile_size);
	return (mini_pos);
}
void	draw_map(t_game *game, t_minimap *m, int map_width, int map_height)
{
	int	mx;
	int	my;
	int	pos_x;
	int	pos_y;
	int	color;

	my = 0;
	while (my <= map_height - 1)
	{
		mx = 0;
		while (mx <= map_width - 1)
		{
			color = select_color(game->map[my][mx], game->player.orientation);
			pos_x = MINI_OFFSET_X + (mx * m->tile_size);
			pos_y = MINI_OFFSET_Y + (my * m->tile_size);
			draw_square_tile(game, m, pos_x, pos_y, color);
			mx++;
		}
		my++;
	}
}
int	calculate_tile(int map_width, int map_height)
{
	if (((WIDTH/4)/map_width) < ((HEIGHT/4)/map_height))
			return ((WIDTH/4)/map_width);
	else
		return ((HEIGHT/4)/map_height);
}

void calculate_size(t_game *game, t_minimap *m)
{
	int	w;
	int	w_max;
	int	h;
	
	h = 0;
	w_max = 0;
	while(game->map[h])
	{
		w = ft_strlen(game->map[h]);
		if(w > w_max)
			w_max = w;
		h++;
	}
	m->height = h;
	m->width = w;
}
void	generate_minimap(t_game *game)
{

	double 			mini_pos[2];
	t_line			line;
	t_minimap		mini_map;
	
	ft_bzero(&line, sizeof(line));
	ft_bzero(&mini_map, sizeof(mini_map));
	calculate_size(game, &mini_map);;
	mini_map.tile_size = calculate_tile(mini_map.width, mini_map.height);
	draw_map(game, &mini_map, mini_map.width, mini_map.height);
	posicion_minimapa(game, &mini_map, mini_pos);
	draw_minimap_player(game, mini_pos[0], mini_pos[1]);
	mini_dir_player(game, &line, &mini_map);
}
