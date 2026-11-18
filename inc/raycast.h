/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 19:46:51 by rpinheir          #+#    #+#             */
/*   Updated: 2026/11/18 18:18:56 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H
# include "struct.h"

void	cast_rays(t_game *game);
void	draw_walls(t_game *game, t_ray *ray, int x);
void	dda(t_game *game, t_ray *ray);

#endif
