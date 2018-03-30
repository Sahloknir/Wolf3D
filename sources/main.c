/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 19:01:42 by axbal             #+#    #+#             */
/*   Updated: 2018/03/29 19:20:16 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	raycast(t_data *data)
{
	
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
