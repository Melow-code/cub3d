/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 17:13:23 by ch                #+#    #+#             */
/*   Updated: 2026/11/14 19:52:25 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

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

static int	set_player_plane(t_player *player, const int dir)
{
	if (dir == 'N')
		return (player->plane_x = 0.66, player->plane_y = 0.0, 1);
	if (dir == 'S')
		return (player->plane_x = -0.66, player->plane_y = 0.0, 1);
	if (dir == 'E')
		return (player->plane_x = 0.0, player->plane_y = 0.66, 1);
	if (dir == 'W')
		return (player->plane_x = 0.0, player->plane_y = -0.66, 1);
	return (0);
}

static int	set_player_dir(t_player *player, const int dir)
{
	if (dir == 'N')
		return (player->dir_x = 0.0, player->dir_y = -1.0, 1);
	if (dir == 'S')
		return (player->dir_x = 0.0, player->dir_y = 1.0, 1);
	if (dir == 'E')
		return (player->dir_x = 1.0, player->dir_y = 0.0, 1);
	if (dir == 'W')
		return (player->dir_x = -1.0, player->dir_y = 0.0, 1);
	return (0);
}

int	load_player_dt(t_game *game)
{
	int	orientation;

	orientation = game->player.orientation;
	set_player_dir(&game->player, orientation);
	set_player_plane(&game->player, orientation);
	game->player.move_speed = 0.05;
	game->player.rot_speed = 0.3;
	return (1);
}
