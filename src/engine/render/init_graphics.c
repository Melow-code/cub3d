/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 22:41:29 by chguerre          #+#    #+#             */
/*   Updated: 2026/11/14 19:30:51 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

static int	init_img(t_img *img, void *mlx_ptr, char *path)
{
	if (fill_path_img(img, path) == 1)
		return (1);
	img->img_ptr = mlx_xpm_file_to_image(mlx_ptr, img->path,
			&img->width, &img->heigth);
	if (img->img_ptr == NULL)
	{
		ft_putstr_fd("Error\nFailed loading texture in path -> ", 2);
		ft_putendl_fd(path, 2);
		return (1);
	}
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bpp,
			&img->size_line, &img->endian);
	if (!img->addr)
	{
		ft_putstr_fd("Error\nFailed loading img->addr", 2);
		ft_putendl_fd(path, 2);
		return (1);
	}
	return (0);
}

int	load_textures(t_game *game)
{
	if (init_img(&game->w_north, game->mlx_ptr, game->w_north.path))
		return (1);
	if (init_img(&game->w_south, game->mlx_ptr, game->w_south.path))
		return (1);
	if (init_img(&game->w_est, game->mlx_ptr, game->w_est.path))
		return (1);
	if (init_img(&game->w_west, game->mlx_ptr, game->w_west.path))
		return (1);
	return (0);
}
