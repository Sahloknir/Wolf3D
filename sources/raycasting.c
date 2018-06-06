/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 14:12:16 by axbal             #+#    #+#             */
/*   Updated: 2018/06/06 17:20:52 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	get_texture_column(t_data *data, float dist, float v_x, float v_y)
{
	t_texture	*t;
	float	value;
	float	x;
	float	y;
	t = TEX[SIDE - 1];

	x = (PLAYER->pos_x + v_x * dist);
	y = (PLAYER->pos_y + v_y * dist);
	value = (SIDE % 2 == 0 ? y : x);
	value = value - floor(value);
	t->x = (value * t->img_w);
}

void	check_side(t_data *data, float dist, float x, float y)
{
	int		prev_x;
	int		prev_y;
	int		c_x;
	int		c_y;

	c_x = (int)(PLAYER->pos_x + (x * dist));
	c_y = (int)(PLAYER->pos_y + (y * dist));
	prev_x = (int)(PLAYER->pos_x + (x * (dist - STEP)));
	prev_y = (int)(PLAYER->pos_y + (y * (dist - STEP)));
	if (c_y != prev_y && c_x == prev_x)
		SIDE = (prev_y < c_y ? 1 : 3);
	else if (c_x != prev_x && c_y == prev_y)
		SIDE = (prev_x < c_x ? 2 : 4);
}

void	draw_floor(t_dot d, int floor_int, t_data *data, float dist, float v_x, float v_y)
{
	int		lines;
	int		gap;
	float	current;
	float	r_x;
	float	r_y;
	int		tx;
	int		ty;

	lines = WIN_H - floor_int;
	gap = dist / lines;
	current = dist - ((d.y - floor_int) * gap);
	r_x = (float)(PLAYER->pos_x + v_x * current);
	r_y = (float)(PLAYER->pos_y + v_y * current);
	tx = (r_x - floor(r_x)) * TEX[5]->img_w;
	ty = (r_y - floor(r_y)) * TEX[5]->img_h;
	put_pixel_to_image(d, data, IMG_STR, get_pixel_from_texture(data, 5));
}

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
	t_texture	*t;

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
			dist += STEP;
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
		check_side(data, dist, v_x, v_y);
		t = TEX[SIDE - 1];
		roof = (float)(WIN_H / 2) - WIN_H / ((float)dist) + PLAYER->angle;
		floor = WIN_H - roof;
		wall = floor - roof;
		yratio = (float)t->img_h / wall;
		y = 0;
		t->y = 0;
		if (roof < 0)
			t->y = (-roof) * yratio;
		d.x = x;
		get_texture_column(data, dist, v_x, v_y);
		while (y < WIN_H)
		{
			d.y = y;
			if (y < roof)
				put_pixel_to_image(d, data, IMG_STR, COLORS[0]);
			else if (y >= roof && y < floor && dist < 30)
			{
				c = get_pixel_from_texture(data, SIDE - 1);
				put_pixel_to_image(d, data, IMG_STR, c);
				t->y += yratio;
			}
			else if (y >= floor)
				draw_floor(d, floor, data, dist, v_x, v_y);
//				put_pixel_to_image(d, data, IMG_STR, COLORS[2]);
			else
				put_pixel_to_image(d, data, IMG_STR, COLORS[0]);
			y++;
		}
		t->x = 0;
		x++;
	}
}
