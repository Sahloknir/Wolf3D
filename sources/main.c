/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 19:01:42 by axbal             #+#    #+#             */
/*   Updated: 2018/04/03 11:52:33 by axbal            ###   ########.fr       */
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
	t_dot	d;
	int		c;

	x = 0;
	while (x < WIN_W)
	{
		dist = 0;
		ray = (PLAYER->angle - PLAYER->fov / 2)
		+ ((float)x / (float)WIN_W) * PLAYER->fov;
		v_x = cos(ray);
		v_y = sin(ray);
		while (dist < 30)
		{
			dist += 0.01;
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
		roof = (float)(WIN_H / 2) - WIN_H / ((float)dist) + PLAYER->angle;
		floor = WIN_H + PLAYER->angle - roof;
		y = 0;
		d.x = x;
		c = 255 / dist;
		while (y < WIN_H)
		{
			d.y = y;
			if (y < roof)
				put_pixel_to_image(d, data, IMG_STR, COLORS[0]);
			else if (y >= roof && y <= floor)
				put_pixel_to_image(d, data, IMG_STR, new_color(c, c, c, 0));
			else
				put_pixel_to_image(d, data, IMG_STR, COLORS[0]);
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
	raycast(data);
	refresh_expose(data);
	mlx_hook(WIN, 17, 1L << 17, close_window, NULL);
	mlx_hook(WIN, 2, 1L << 0, key_press, data);
	mlx_hook(WIN, 3, 1L << 1, key_release, data);
	mlx_hook(WIN, 6, 1L << 6, track_mouse, data);
	mlx_key_hook(WIN, key_redirect, data);
	mlx_loop(MLX);
	return (0);
}
