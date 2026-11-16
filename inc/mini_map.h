/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 12:43:25 by chguerre          #+#    #+#             */
/*   Updated: 2026/11/16 12:43:27 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_MAP_H
# define MINI_MAP_H

unsigned int	select_color(char c, char orientation);
void			calculate_size(t_game *game, t_minimap *m);
int				calculate_tile(int map_width, int map_height);
#endif //MINI_MAP_H