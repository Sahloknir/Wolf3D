/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 17:39:07 by axbal             #+#    #+#             */
/*   Updated: 2018/06/06 16:50:35 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_texture	**init_texture(t_data *data)
{
	t_texture	**tex;

	if (!(tex = (t_texture **)malloc(sizeof(t_texture *) * 6)))
		return (NULL);
	tex[0] = new_texture(data, "textures/wall2.xpm");
	tex[1] = new_texture(data, "textures/wall.xpm");
	tex[2] = new_texture(data, "textures/wall3.xpm");
	tex[3] = new_texture(data, "textures/wall4.xpm");
	tex[4] = new_texture(data, "textures/barrel.xpm");
	tex[5] = new_texture(data, "textures/floor.xpm");
	return (tex);
}

t_player	*init_player(void)
{
	t_player	*player;

	if (!(player = (t_player *)malloc(sizeof(t_player))))
		ft_error(1);
	player->pos_x = 1;
	player->pos_y = 1;
	player->angle = 1;
	player->fov = 1.0472 / 2;
	return (player);
}

t_map		*init_map(void)
{
	t_map	*map;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		ft_error(1);
	map->size_x = 10;
	map->size_y = 37;
	map->map = get_map();
	return (map);
}

t_color		*init_colors(void)
{
	t_color	*colors;

	if (!(colors = (t_color *)malloc(sizeof(t_color) * 3)))
		return (NULL);
	colors[0] = new_color(122, 160, 196, 0);
	colors[1] = new_color(255, 255, 255, 0);
	colors[2] = new_color(79, 51, 27, 0);
	return (colors);
}

t_data		*init_data(void)
{
	t_data	*data;

	if (!(data = (t_data *)malloc(sizeof(t_data))))
		ft_error(1);
	data->player = init_player();
	data->map = init_map();
	data->colors = init_colors();
	WIN_W = 900;
	WIN_H = 600;
	SPEED = 0.1;
	M_X = 0;
	SIDE = 1;
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, WIN_W, WIN_H, "wolf3d");
	IMG = mlx_new_image(MLX, WIN_W, WIN_H);
	IMG_STR = mlx_get_data_addr(IMG, &BPP, &S_L, &ENDIAN);
	BPP /= 8;
	data->texture = init_texture(data);
	return (data);
}
