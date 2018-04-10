/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:19:24 by axbal             #+#    #+#             */
/*   Updated: 2018/04/10 11:54:30 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_color		get_pixel_from_texture(t_data *data)
{
	t_color		c;
	char		t;

	t = TEX->tex_data[((int)TEX->x * TEX->bpp) + ((int)TEX->y * TEX->s_l) + 0];
	c.b = t;
	t = TEX->tex_data[((int)TEX->x * TEX->bpp) + ((int)TEX->y * TEX->s_l) + 1];
	c.g = t;
	t = TEX->tex_data[((int)TEX->x * TEX->bpp) + ((int)TEX->y * TEX->s_l) + 2];
	c.r = t;
	t = TEX->tex_data[((int)TEX->x * TEX->bpp) + ((int)TEX->y * TEX->s_l) + 3];
	c.alpha = t;
	if (TEX->y >= 255)
	{
		TEX->y = 0;
	}
	return (c);
}
