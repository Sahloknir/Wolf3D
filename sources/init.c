/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 17:39:07 by axbal             #+#    #+#             */
/*   Updated: 2018/04/01 15:08:20 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_player	*init_player(void)
{
	t_player	*player;

	if (!(player = (t_player *)malloc(sizeof(t_player))))
		ft_error(1);
	player->pos_x = 1;
	player->pos_y = 1;
	player->angle = 0;
	player->fov = 1.0472 / 2;
	return (player);
}

t_map		*init_map(void)
{
	t_map	*map;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		ft_error(1);
	map->size_x = 10;
	map->size_y = 10;
	map->map = get_map();
	return (map);
}

t_color		*init_colors(void)
{
	t_color	*colors;

	if (!(colors = (t_color *)malloc(sizeof(t_color) * 2)))
		return (NULL);
	colors[0].r = 0;
	colors[0].g = 0;
	colors[0].b = 0;
	colors[0].alpha = 0;
	colors[1].r = 255;
	colors[1].g = 255;
	colors[1].b = 255;
	colors[1].alpha = 0;
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
	WIN_W = 960;
	WIN_H = 600;
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, WIN_W, WIN_H, "wolf3d");
	IMG = mlx_new_image(MLX, WIN_W, WIN_H);
	IMG_STR = mlx_get_data_addr(IMG, &BPP, &S_L, &ENDIAN);
	BPP /= 8;
	return (data);
}
