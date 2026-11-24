/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 13:58:37 by rpinheir          #+#    #+#             */
/*   Updated: 2026/11/24 16:03:31 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	wrap_mouse_location(int x, int y, t_game *game)
{
	if (x > WIDTH - DIST_EDGE_WRAP)
	{
		x = DIST_EDGE_WRAP;
		mlx_mouse_move(game->mlx_ptr, game->win_ptr, x, y);
		game->mouse_x = x ;
		return (1);
	}
	if (x < DIST_EDGE_WRAP)
	{
		x = WIDTH - DIST_EDGE_WRAP;
		mlx_mouse_move(game->mlx_ptr, game->win_ptr, x, y);
		game->mouse_x = x;
		return (1);
	}
	return (0);\
}

static void	setup_rotation(double cos_rot, double sin_rot, t_game *game)
{
	double		old_dir_x;
	double		old_plane_x;

	old_dir_x = game->player.dir_x;
	game->player.dir_x = old_dir_x * cos_rot - game->player.dir_y * sin_rot;
	game->player.dir_y = old_dir_x * sin_rot + game->player.dir_y * cos_rot;
	old_plane_x = game->player.plane_x;
	game->player.plane_x = old_plane_x * cos_rot
		- game->player.plane_y * sin_rot;
	game->player.plane_y = old_plane_x * sin_rot
		+ game->player.plane_y * cos_rot;
}

int	mouse_handler(int x, int y, t_game *game)
{
	double			cos_rot;
	double			sin_rot;
	double			angle;

	if (wrap_mouse_location(x, y, game) != 0)
		return (0);
	if (x == game->mouse_x)
		return (0);
	angle = (x - game->mouse_x) * 0.002;
	cos_rot = cos(angle);
	sin_rot = sin(angle);
	game->mouse_x = x;
	setup_rotation(cos_rot, sin_rot, game);
	if (DEBUG)
		printf("dir: %f %f  plane: %f %f\n", game->player.dir_x,
			game->player.dir_y, game->player.plane_x, game->player.plane_y);
	return (0);
}
