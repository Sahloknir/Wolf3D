/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 19:01:42 by axbal             #+#    #+#             */
/*   Updated: 2018/04/09 14:18:56 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main(int argc, char **argv)
{
	t_data	*data;

	argc = 0;
	argv = NULL;
	data = init_data();
	raycast(data);
	refresh_expose(data);
	mlx_put_image_to_window(MLX, WIN, TEX->texture, 0, 0);
	mlx_hook(WIN, 17, 1L << 17, close_window, NULL);
	mlx_hook(WIN, 2, 1L << 0, key_press, data);
	mlx_hook(WIN, 3, 1L << 1, key_release, data);
//	mlx_hook(WIN, 6, 1L << 6, track_mouse, data);
	mlx_key_hook(WIN, key_redirect, data);
	mlx_loop(MLX);
	return (0);
}
