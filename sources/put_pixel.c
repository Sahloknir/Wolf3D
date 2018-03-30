/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 14:46:42 by axbal             #+#    #+#             */
/*   Updated: 2018/03/30 14:55:19 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	put_pixel_to_image(t_dot d, t_data *data, char *image, t_color c)
{
	if (d.x >= 0 && d.x <= WIN_W && d.y >= 0 && d.y < WIN_H)
	{
		image[(int)((d.x * BPP) + (d.y * S_L) + 0)] = (char)c.b;
		image[(int)((d.x * BPP) + (d.y * S_L) + 1)] = (char)c.g;
		image[(int)((d.x * BPP) + (d.y * S_L) + 2)] = (char)c.r;
		image[(int)((d.x * BPP) + (d.y * S_L) + 3)] = (char)c.alpha;
	}
}
