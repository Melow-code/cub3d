/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_win.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ch <chguerre@42lausanne.ch>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 15:00:51 by ch                #+#    #+#             */
/*   Updated: 2026/11/12 15:00:57 by ch               ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_WIN_H
# define MLX_WIN_H

# define HEIGHT 1080
# define WIDTH 1920
# define MINI_OFFSET_X 100
# define MINI_OFFSET_Y 400

int		fill_path_img(t_img *img, char *path);
int		run_win_mlx(t_game *game);
int		game_loop(t_game *game);
void	create_canvas(t_game *game);
// CLEANING FUNTIONS:
void	clear_images(t_game *game);
void	clear_paths(t_game *game);
int		safe_exit(t_game *game, int code);
void	generate_minimap(t_game *game);
#endif // H_WIN
