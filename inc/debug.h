/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 16:14:58 by rpinheir          #+#    #+#             */
/*   Updated: 2026/11/17 13:36:35 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H
# include "struct.h"

void	print_data(t_game *game);
void	draw_plane(t_game *game, t_ray *ray, int x);
void	print_crosshair(t_game *game);
#endif
