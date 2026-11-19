/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_minimap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 17:58:44 by chguerre          #+#    #+#             */
/*   Updated: 2026/11/18 19:36:33 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	get_ray_mini_hit(t_game *g, t_ray *m_ray, double *hit_x, double *hit_y)
{
	if (m_ray->side == 0)
	{
		*hit_x = m_ray->map_x + (m_ray->step_x < 0);
		*hit_y = g->player.pos_y + m_ray->perp_wall_dist * m_ray->ray_dir_y;
	}
	else
	{
		*hit_y = m_ray->map_y + (m_ray->step_y < 0);
		*hit_x = g->player.pos_x + m_ray->perp_wall_dist * m_ray->ray_dir_x;
	}
}

void	draw_minimap_pov(t_game *game, t_minimap *m)
{
	t_ray	r_mini;
	t_line	l;
	double	hit[2];
	int		x;

	l.x0 = MINI_OFFSET_X + game->player.pos_x * m->tile_size;
	l.y0 = MINI_OFFSET_Y + game->player.pos_y * m->tile_size;
	ft_bzero(&r_mini, sizeof(t_ray));
	x = 0;
	while (x < WIDTH)
	{
		r_mini.hit = 0;
		r_mini.camera_x = 2.0 * x / WIDTH - 1;
		r_mini.ray_dir_x = game->player.dir_x + game->player.plane_x
			* r_mini.camera_x;
		r_mini.ray_dir_y = game->player.dir_y + game->player.plane_y
			* r_mini.camera_x;
		dda(game, &r_mini);
		get_ray_mini_hit(game, &r_mini, &hit[0], &hit[1]);
		l.x1 = MINI_OFFSET_X + hit[0] * m->tile_size;
		l.y1 = MINI_OFFSET_Y + hit[1] * m->tile_size;
		draw_line(game, &l, 0xFFFF00);
		x += 16;
	}
}
