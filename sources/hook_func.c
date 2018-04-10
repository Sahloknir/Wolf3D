/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 10:25:23 by axbal             #+#    #+#             */
/*   Updated: 2018/04/10 11:15:10 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		key_press(int key, t_data *data)
{
//	ft_putstr("press");
	if (key == 13 || key == 1)
		move(key, data);
	if (key == 0 || key == 2)
		turn(key, data);
	if (key == 257)
		SPEED = 0.5;
	return (key);
}

int		key_release(int key, t_data *data)
{
//	ft_putstr("release");
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
