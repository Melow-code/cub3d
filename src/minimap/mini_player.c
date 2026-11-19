/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 17:27:26 by chguerre          #+#    #+#             */
/*   Updated: 2026/11/18 19:37:01 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	paint_line(t_game *game, t_line *line, int color)
{
	int	i;

	i = 0;
	while (i <= line->step)
	{
		put_pixel((int)round(line->curr_x),
			(int)round(line->curr_y), color, game);
		line->curr_x += line->inc_x;
		line->curr_y += line->inc_y;
		i++;
	}
}

void	draw_line(t_game *game, t_line *line, int color)
{
	line->dx = line->x1 - line->x0;
	line->dy = line->y1 - line->y0;
	if (abs((int)line->dx) > abs((int)line->dy))
		line->step = abs((int)line->dx);
	else
		line->step = abs((int)line->dy);
	if (line->step == 0)
	{
		put_pixel(line->x0, line->x0, 0xFFFF00, game);
		return ;
	}
	line->inc_x = line->dx / (float)line->step;
	line->inc_y = line->dy / (float)line->step;
	line->curr_x = line->x0;
	line->curr_y = line->y0;
	paint_line(game, line, color);
}

void	mini_dir_player(t_game *game, t_line *line, t_minimap *m)
{
	t_player	*player;

	player = &game->player;
	line->x0 = (double)MINI_OFFSET_X + (player->pos_x * (double)m->tile_size);
	line->y0 = (double)MINI_OFFSET_Y + (player->pos_y * (double)m->tile_size);
	line->x1 = line->x0 + player->dir_x * (m->tile_size * 1.1);
	line->y1 = line->y0 + player->dir_y * (m->tile_size * 1.1);
	draw_line(game, line, 0xFFFF00);
}

void	draw_minimap_player(t_game *game, int px, int py, t_minimap *m)
{
	float	size;
	int		x;
	int		y;

	size = m->tile_size * 0.7;
	y = -size / 2;
	while (y < size / 2)
	{
		x = -size / 2;
		while (x < size / 2)
		{
			put_pixel(px + x, py + y, 0x00FF0000, game);
			x++;
		}
		y++;
	}
}
