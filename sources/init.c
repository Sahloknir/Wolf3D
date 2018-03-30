/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 17:39:07 by axbal             #+#    #+#             */
/*   Updated: 2018/03/29 17:41:02 by axbal            ###   ########.fr       */
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
	player->fov = 1.0472;
	return (player);
}

t_map		*init_map(void)
{
	t_map	*map;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		ft_error(1);
	map->size_x = 5;
	map->size_y = 5;
	map->map = get_map();
	return (map);
}

t_data		*init_data(void)
{
	t_data	*data;

	if (!(data = (t_data *)malloc(sizeof(t_data))))
		ft_error(1);
	data->player = init_player();
	data->map = init_map();
	WIN_W = 960;
	WIN_H = 600;
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, WIN_W, WIN_H, "wolf3d");
	return (data);
}
