/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 19:00:10 by axbal             #+#    #+#             */
/*   Updated: 2018/04/11 18:20:12 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLD3D_H
# define WOLD3D_H

# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include "../libft/includes/libft.h"
# include "../mlx/mlx.h"

# define STEP 0.001
# define MLX data->mlx
# define WIN data->win
# define WIN_W data->win_w
# define WIN_H data->win_h
# define PLAYER data->player
# define MAP data->map
# define COLORS data->colors
# define TEX data->texture
# define IMG data->img_ptr
# define IMG_STR data->img_str
# define BPP data->bpp
# define S_L data->s_l
# define ENDIAN data->endian
# define SPEED data->speed
# define M_X data->mouse_x
# define SIDE data->side

typedef struct		s_dot
{
	float			x;
	float			y;
}					t_dot;

typedef struct		s_color
{
	char			r;
	char			g;
	char			b;
	char			alpha;
}					t_color;

typedef struct		s_texture
{
	float			x;
	float			y;
	int				img_w;
	int				img_h;
	void			*texture;
	char			*tex_data;
	int				bpp;
	int				s_l;
	int				endian;
}					t_texture;

typedef struct		s_player
{
	float			pos_x;
	float			pos_y;
	float			angle;
	float			fov;
}					t_player;

typedef struct		s_map
{
	int				size_x;
	int				size_y;
	char			**map;
}					t_map;

typedef struct		s_data
{
	void			*mlx;
	void			*win;
	int				win_w;
	int				win_h;
	void			*img_ptr;
	char			*img_str;
	int				bpp;
	int				s_l;
	int				endian;
	float			speed;
	int				mouse_x;
	int				side;
	t_player		*player;
	t_map			*map;
	t_color			*colors;
	t_texture		**texture;
}					t_data;

void				ft_error(int error);
int					close_window(void);
t_data				*init_data(void);
char				**get_map(void);
void				put_pixel_to_image(t_dot d, t_data *dt, char *i, t_color c);
void				refresh_expose(t_data *data);
void				raycast(t_data *data);
int					key_redirect(int key, t_data *data);
void				turn(int key, t_data *data);
void				move(int key, t_data *data);
t_color				new_color(int r, int g, int b, int alpha);
int					key_press(int key, t_data *data);
int					key_release(int key, t_data *data);
int					track_mouse(int x, int y, t_data *data);
t_color				get_pixel_from_texture(t_data *data);
t_texture			*new_texture(t_data *data, char *path);

#endif
