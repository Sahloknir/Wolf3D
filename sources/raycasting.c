/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 14:12:16 by axbal             #+#    #+#             */
/*   Updated: 2018/04/09 16:08:10 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

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
	int		wall;
	float	yratio;
	t_dot	d;
	t_color	c;

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
		floor = WIN_H - roof;
		wall = floor - roof;
		yratio = (float)TEX->img_h / wall;
		y = 0;
		TEX->y = 0;
		if (roof < 0)
			TEX->y = (-roof) * yratio;
		d.x = x;
		while (y < WIN_H)
		{
			d.y = y;
			if (y < roof)
				put_pixel_to_image(d, data, IMG_STR, COLORS[0]);
			else if (y >= roof && y <= floor)
			{
				c = get_pixel_from_texture(data);
				put_pixel_to_image(d, data, IMG_STR, c);
				TEX->y += yratio;
			}
			else
				put_pixel_to_image(d, data, IMG_STR, COLORS[2]);
			y++;
		}
		x++;
	}
}
