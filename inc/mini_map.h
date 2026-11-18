/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 12:43:25 by chguerre          #+#    #+#             */
/*   Updated: 2026/11/17 22:53:42 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_MAP_H
# define MINI_MAP_H

unsigned int	select_color(char c, char orientation);
void			calculate_size(t_game *game, t_minimap *m);
int				size_tile(int map_width, int map_height);
#endif //MINI_MAP_H
