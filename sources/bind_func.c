/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 13:56:21 by axbal             #+#    #+#             */
/*   Updated: 2018/04/01 15:13:47 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	turn(int mode, t_data *data)
{
	if (mode == 0)
		PLAYER->angle += 0.1;
	else
		PLAYER->angle -= 0.1;
	raycast(data);
	refresh_expose(data);
}

void	move(int mode, t_data *data)
{
	if (mode == 0)
	{
		PLAYER->pos_x += cos(PLAYER->angle);
		PLAYER->pos_y += sin(PLAYER->angle);
	}
	else
	{
		PLAYER->pos_x -= cos(PLAYER->angle);
		PLAYER->pos_y -= sin(PLAYER->angle);
	}
	raycast(data);
	refresh_expose(data);
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
