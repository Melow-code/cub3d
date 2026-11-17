/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 17:13:23 by ch                #+#    #+#             */
/*   Updated: 2026/11/14 22:22:28 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_strstrk(char *s1, char *s2)
{
	while (s1)
	{
		if (ft_strchr(s2, *s1))
			return (*s1);
		s1++;
	}
	return (0);
}

void	update_movement(t_game *game)
{
	t_player	*p;

	p = &game->player;
	move_player(p, game->map);
}

static int	set_player_plane(t_player *player, const int dir)
{
	if (dir == ON)
		return (player->plane_x = 0.99, player->plane_y = 0.0, 1);
	if (dir == OS)
		return (player->plane_x = -0.99, player->plane_y = 0.0, 1);
	if (dir == OE)
		return (player->plane_x = 0.0, player->plane_y = 0.99, 1);
	if (dir == OW)
		return (player->plane_x = 0.0, player->plane_y = -0.99, 1);
	return (0);
}

static int	set_player_dir(t_player *player, const int dir)
{
	if (dir == ON)
		return (player->dir_x = 0.0, player->dir_y = -1.0, 1);
	if (dir == OS)
		return (player->dir_x = 0.0, player->dir_y = 1.0, 1);
	if (dir == OE)
		return (player->dir_x = 1.0, player->dir_y = 0.0, 1);
	if (dir == OW)
		return (player->dir_x = -1.0, player->dir_y = 0.0, 1);
	return (0);
}

int	load_player_dt(t_game *game)
{
	set_player_dir(&game->player, game->player.orientation);
	set_player_plane(&game->player, game->player.orientation);
	game->player.move_speed = 0.05;
	game->player.rot_speed = 0.1;
	return (1);
}
