/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 19:00:10 by axbal             #+#    #+#             */
/*   Updated: 2018/03/29 17:41:33 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLD3D_H
# define WOLD3D_H

# include <stdlib.h>
# include <stdio.h>
# include "../libft/includes/libft.h"
# include "../mlx/mlx.h"

# define MLX data->mlx
# define WIN data->win
# define WIN_W data->win_w
# define WIN_H data->win_h
# define PLAYER data->player
# define MAP data->map

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
	t_player		*player;
	t_map			*map;
}					t_data;

void				ft_error(int error);
int					close_window(void);
t_data				*init_data(void);
char				**get_map(void);

#endif
