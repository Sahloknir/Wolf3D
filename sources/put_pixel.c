/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 14:46:42 by axbal             #+#    #+#             */
/*   Updated: 2018/04/09 13:20:24 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	put_pixel_to_image(t_dot d, t_data *data, char *image, t_color c)
{
	if (d.x >= 0 && d.x <= WIN_W && d.y >= 0 && d.y < WIN_H)
	{
		image[(int)((d.x * BPP) + (d.y * S_L) + 0)] = c.b;
		image[(int)((d.x * BPP) + (d.y * S_L) + 1)] = c.g;
		image[(int)((d.x * BPP) + (d.y * S_L) + 2)] = c.r;
		image[(int)((d.x * BPP) + (d.y * S_L) + 3)] = c.alpha;
	}
}
