/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 13:56:21 by axbal             #+#    #+#             */
/*   Updated: 2018/04/03 11:36:29 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	turn(int mode, t_data *data)
{
	if (mode == 0)
		PLAYER->angle += 0.08;
	else
		PLAYER->angle -= 0.08;
	raycast(data);
	refresh_expose(data);
}

void	move(int mode, t_data *data)
{
	if (mode == 0)
	{
		PLAYER->pos_x += cos(PLAYER->angle) * SPEED;
		PLAYER->pos_y += sin(PLAYER->angle) * SPEED;
	}
	else
	{
		PLAYER->pos_x -= cos(PLAYER->angle) * SPEED;
		PLAYER->pos_y -= sin(PLAYER->angle) * SPEED;
	}
	raycast(data);
	refresh_expose(data);
}

int		key_press(int key, t_data *data)
{
	if (key == 257)
		SPEED = 0.5;
	return (key);
}

int		key_release(int key, t_data *data)
{
	if (key == 257)
		SPEED = 0.1;
	return (key);
}

int		track_mouse(int x, int y, t_data *data)
{
	if (x > M_X)
		turn(0, data);
	else if (x < M_X)
		turn(1, data);
	M_X = x;
	return (y);
}

int		key_redirect(int key, t_data *data)
{
	if (key == 2)
		turn(0, data);
	else if (key == 0)
		turn(1, data);
	else if (key == 13)
		move(0, data);
	else if (key == 1)
		move(1, data);
	ft_putnbr(key);
	return (key);
}
