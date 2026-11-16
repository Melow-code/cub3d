/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 21:37:22 by chguerre          #+#    #+#             */
/*   Updated: 2026/11/14 21:47:05 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

unsigned int	select_color(char c, char orientation)
{
	if (c == '1')
		return (0xFFFFFF);
	else if (c == '0' || c == orientation)
		return (0x1E293B);
	return (0);
}

int	calculate_tile(int map_width, int map_height)
{
	if (((WIDTH / 4) / map_width) < ((HEIGHT / 4) / map_height))
		return ((WIDTH / 4) / map_width);
	else
		return ((HEIGHT / 4) / map_height);
}

void	calculate_size(t_game *game, t_minimap *m)
{
	int	w;
	int	w_max;
	int	h;

	h = 0;
	w_max = 0;
	while (game->map[h])
	{
		w = ft_strlen(game->map[h]);
		if (w > w_max)
			w_max = w;
		h++;
	}
	m->height = h;
	m->width = w;
}
