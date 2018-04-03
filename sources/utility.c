/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:43:29 by axbal             #+#    #+#             */
/*   Updated: 2018/04/01 13:42:55 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		close_window(void)
{
	exit(0);
	return (0);
}

void	ft_error(int error)
{
	if (error == 1)
		ft_putstr("error : could not allocate memory.\n");
	exit(1);
}

void	refresh_expose(t_data *data)
{
	mlx_clear_window(MLX, WIN);
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
}
