/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 19:01:42 by axbal             #+#    #+#             */
/*   Updated: 2018/03/30 16:32:33 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	raycast(t_data *data)
{
	int		x;
	int		y;
	float	ray;
	int		r_x;
	int		r_y;
	float	v_x;
	float	v_y;
	float	dist;
	int		roof;
	int		floor;

	x = 0;
	while (x < WIN_W)
	{
		dist = 0;
		ray = (PLAYER->fov / 2) + ((float)x / (float)WIN_W) * PLAYER->fov;
		v_x = sin(ray);
		v_y = cos(ray);
		while (dist < 30)
		{
			dist += 0.1;
			r_x = (int)(PLAYER->pos_x + v_x * dist);
			r_y = (int)(PLAYER->pos_y + v_y * dist);
			if (r_x < 0 || r_x > MAP->size_x || r_y < 0 || r_y >= MAP->size_y)
			{
				dist = 30;
				break ;
			}
			else
			{
				if (MAP->map[r_y][r_x] == '#')
					break ;
			}
		}
		roof = (float)(WIN_H / 2) - WIN_H / ((float)dist);
		floor = WIN_H - roof;
		y = 0;
		while (y < WIN_H)
		{
			if (y < roof)
				mlx_pixel_put(MLX, WIN, x, y, 0x000000);
			else if (y >= roof && y <= floor)
				mlx_pixel_put(MLX, WIN, x, y, 0xFFFFFF);
			else
				mlx_pixel_put(MLX, WIN, x, y, 0x000000);
			y++;
		}
		x++;
	}
}

int		main(int argc, char **argv)
{
	t_data	*data;

	argc = 0;
	argv = NULL;
	data = init_data();
	mlx_hook(WIN, 17, 1L << 17, close_window, NULL);
	raycast(data);
	mlx_loop(MLX);
	return (0);
}
