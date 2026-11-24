/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_win.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ch <chguerre@42lausanne.ch>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 15:00:51 by ch                #+#    #+#             */
/*   Updated: 2026/11/24 15:41:01 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_WIN_H
# define MLX_WIN_H

#include "struct.h"
# define HEIGHT 1080
# define WIDTH 1920
# define MINI_OFFSET_X 0
# define MINI_OFFSET_Y 0
# define DIST_EDGE_WRAP 20

void	draw_background(t_game *game);
int		fill_path_img(t_img *img, char *path);
int		run_win_mlx(t_game *game);
int		game_loop(t_game *game);
void	create_canvas(t_game *game);
// CLEANING FUNTIONS:
void	clear_images(t_game *game);
void	clear_paths(t_game *game);
int		safe_exit(t_game *game, int code);
void	generate_minimap(t_game *game);
double	get_time_in_seconds(void);
int		mouse_handler(int x, int y, t_game *game);
#endif // H_WIN
