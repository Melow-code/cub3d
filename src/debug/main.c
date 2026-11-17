/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 16:11:25 by rpinheir          #+#    #+#             */
/*   Updated: 2026/11/13 16:21:37 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	draw_plane(t_game *game, t_ray *ray, int x)
{
	int	color;
	int	y;
	int	_x;

	y = 0;
	_x = 0;
	color = 0x0000011;
	put_pixel(x, ray->draw_start, color, game);
	put_pixel(x, ray->draw_end, color, game);
}

void	print_crosshair(t_game *game)
{
	int	cross_x;
	int	color;
	int	y;

	y = HEIGHT / 2 - 15;
	color = 0x0000011;
	cross_x = WIDTH / 2 - 15;
	while (cross_x < WIDTH / 2 + 15)
	{
		put_pixel(cross_x, HEIGHT / 2, color, game);
		cross_x++;
	}
	while (y < HEIGHT / 2 + 15)
	{
		put_pixel(WIDTH / 2, y, color, game);
		y++;
	}
}

void	print_data(t_game *game)
{
	int	x;

	x = -1;
	ft_putendl_fd("=== CONFIG ===", 2);
	while (game->config[++x] != NULL)
	{
		ft_putstr_fd("|> ", 2);
		ft_putendl_fd(game->config[x], 2);
	}
	x = -1;
	ft_putendl_fd("\n=== MAP ===", 2);
	while (game->map[++x] != NULL)
	{
		ft_putnbr_fd(x, 2);
		ft_putstr_fd("|> ", 2);
		ft_putendl_fd(game->map[x], 2);
	}
	printf("PLAYER DATA:\n");
	printf("pos_x: %f\npos_y: %f\n", game->player.pos_x, game->player.pos_y);
	printf("dir_x: %f\ndir_y: %f\n", game->player.dir_x, game->player.dir_y);
	printf("plane_x: %f\nplane_y: %f\n", game->player.plane_x,
		game->player.plane_y);
	printf("Orientacion: %c\n", game->player.orientation);
}
