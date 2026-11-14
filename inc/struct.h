/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 17:23:35 by ch                #+#    #+#             */
/*   Updated: 2026/11/14 21:22:05 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_line
{
	double	x0;
	double	y0;
	double	x1;
	double	y1;
	double	dx;
	double	dy;
	double	inc_x;
	double	inc_y;
	double	curr_x;
	double	curr_y;
	int		step;
}			t_line;

typedef struct s_minimap
{
	double	offset_x;
	double	offset_y;
	int		height;
	int		width;
	int		tile_size;
}			t_minimap;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	char	orientation;
	double	rot_speed;
	double	move_speed;
	bool	key_w;
	bool	key_s;
	bool	key_a;
	bool	key_d;
	bool	key_rigth;
	bool	key_left;
}			t_player;

typedef struct s_img
{
	char		*path;
	void		*img_ptr;
	void		*addr;
	int			heigth;
	int			width;
	int			bpp;
	int			endian;
	int			size_line;
}				t_img;

typedef struct s_game
{
	int			map_fd;
	void		*mlx_ptr;
	void		*win_ptr;
	char		**config;
	char		**map;
	char		*path_to_map;
	int			cursorcreate_ca;
	int			c_color[3];
	int			f_color[3];
	t_player	player;

	t_img		screen;
	t_img		w_north;
	t_img		w_south;
	t_img		w_est;
	t_img		w_west;
}				t_game;
#endif
