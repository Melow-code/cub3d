/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 18:03:08 by rpinheir          #+#    #+#             */
/*   Updated: 2026/11/14 19:25:36 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

void			put_pixel(int x, int y, int color, t_game *game);
unsigned int	get_pixel(t_img *img, int x, int y);
int				load_textures(t_game *game);
#endif
