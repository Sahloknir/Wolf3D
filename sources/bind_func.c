/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 13:56:21 by axbal             #+#    #+#             */
/*   Updated: 2018/04/21 17:42:23 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	turn(int key, t_data *data)
{
	if (key == 2)
		PLAYER->angle += 0.02;
	else
		PLAYER->angle -= 0.02;
	reset_image(data);
	raycast(data);
	refresh_expose(data);
}

void	move(int key, t_data *data)
{
	if (key == 13)
	{
		if (MAP->map[(int)(PLAYER->pos_y + sin(PLAYER->angle) * SPEED)]
			[(int)(PLAYER->pos_x + cos(PLAYER->angle) * SPEED)] == '.')
		{
			PLAYER->pos_y += sin(PLAYER->angle) * SPEED;
			PLAYER->pos_x += cos(PLAYER->angle) * SPEED;
		}
	}
	else
	{
		if (MAP->map[(int)(PLAYER->pos_y - sin(PLAYER->angle) * SPEED)]
			[(int)(PLAYER->pos_x - cos(PLAYER->angle) * SPEED)] == '.')
		{
			PLAYER->pos_y -= sin(PLAYER->angle) * SPEED;
			PLAYER->pos_x -= cos(PLAYER->angle) * SPEED;
		}
	}
	reset_image(data);
	raycast(data);
	refresh_expose(data);
}

void	strafe(int key, t_data *data)
{
	if (key == 12)
	{
		PLAYER->pos_x -= cos(PLAYER->angle) * SPEED;
		PLAYER->pos_y -= tan(PLAYER->angle) * SPEED;
	}
	if (key == 14)
	{
		PLAYER->pos_x += cos(PLAYER->angle) * SPEED;
		PLAYER->pos_y += tan(PLAYER->angle) * SPEED;
	}
	reset_image(data);
	raycast(data);
	refresh_expose(data);
}

int		key_redirect(int key, t_data *data)
{
	int		a;

	a = WIN_W;
	if (key == 53)
		close_window();
	ft_putnbr(key);
	return (key);
}
