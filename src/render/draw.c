/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 20:42:52 by chguerre          #+#    #+#             */
/*   Updated: 2026/11/16 17:23:15 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	put_pixel(int x, int y, int color, t_game *game)
{
	char	*ptr_px;
	t_img	*img;

	img = &game->screen;
	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	ptr_px = (char *)img->addr + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *)ptr_px = color;
}

void	draw_background(t_game *game)
{
	int	color;
	int	w;
	int	h;
	int	*rgb;

	rgb = game->c_color;
	color = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
	h = 0;
	while (h < (HEIGHT))
	{
		w = -1;
		if (h > (HEIGHT / 2))
		{
			rgb = game->f_color;
			color = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
		}
		while (++w < (WIDTH))
			put_pixel(w, h, color, game);
		h++;
	}
}

unsigned int	get_pixel(t_img *img, int x, int y)
{
	char	*src;

	src = (char *)img->addr + (y * img->size_line + x * (img->bpp / 8));
	return (*(unsigned int *)src);
}
