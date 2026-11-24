/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ch <chguerre@42lausanne.ch>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 17:26:06 by ch                #+#    #+#             */
/*   Updated: 2026/11/24 16:28:54 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	close_window(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	exit(safe_exit(game, 0));
	return (0);
}

void	init_graphics(t_game *game)
{
	game->screen.img_ptr = mlx_new_image(game->mlx_ptr, WIDTH, HEIGHT);
	if (!game->screen.img_ptr)
		exit(safe_exit(game, 1));
	game->screen.addr = mlx_get_data_addr(game->screen.img_ptr,
			&game->screen.bpp, &game->screen.size_line, &game->screen.endian);
	if (load_textures(game) != 0)
		exit(safe_exit(game, 42));
}

int	game_loop(t_game *game)
{
	double	current_time;

	current_time = get_time_in_seconds();
	game->delta_time = current_time - game->last_time;
	game->last_time = current_time;
	if (game->delta_time > 0.1)
		game->delta_time = 0.1;
	update_movement(game);
	handle_rotation(&game->player, game);
	create_canvas(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->screen.img_ptr, 0, 0);
	return (0);
}

int	run_win_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (0);
	game->last_time = 0;
	game->win_ptr = mlx_new_window(game->mlx_ptr, WIDTH, HEIGHT, "Cub 3D - 42");
	init_graphics(game);
	mlx_hook(game->win_ptr, 2, 1L << 0, (void *)handle_keypressed, game);
	mlx_hook(game->win_ptr, 3, 1L << 1, (void *)handle_keyrelease, game);
	mlx_mouse_hide(game->mlx_ptr, game->win_ptr);
	if (BONUS)
		mlx_hook(game->win_ptr, MotionNotify, PointerMotionMask,
			(void *)mouse_handler, game);
	mlx_hook(game->win_ptr, 17, 9, (void *)close_window, game);
	mlx_loop_hook(game->mlx_ptr, (void *)game_loop, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}
