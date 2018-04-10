/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:19:24 by axbal             #+#    #+#             */
/*   Updated: 2018/04/10 10:01:59 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_color		get_pixel_from_texture(t_data *data)
{
	t_color		c;
	char		a;
	char		r;
	char		g;
	char		b;


	if (TEX->y >= 255)
	{
		TEX->y = 0;
		if (TEX->x >= 255)
		{
			TEX->x = 0;
		}
		else
			TEX->x++;
	}
	b = TEX->tex_data[((int)TEX->x * TEX->bpp) + ((int)TEX->y * TEX->s_l) + 0];
	g = TEX->tex_data[((int)TEX->x * TEX->bpp) + ((int)TEX->y * TEX->s_l) + 1];
	r = TEX->tex_data[((int)TEX->x * TEX->bpp) + ((int)TEX->y * TEX->s_l) + 2];
	a = TEX->tex_data[((int)TEX->x * TEX->bpp) + ((int)TEX->y * TEX->s_l) + 3];
	c.b = b;
	c.g = g;
	c.r = r;
	c.alpha = a;
	return (c);
}
