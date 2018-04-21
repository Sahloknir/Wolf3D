/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:19:24 by axbal             #+#    #+#             */
/*   Updated: 2018/04/13 16:29:42 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_texture	*new_texture(t_data *data, char *path)
{
	t_texture	*t;

	if (!(t = (t_texture *)malloc(sizeof(t_texture) * 1)))
		return (NULL);
	t->x = 0;
	t->y = 0;
	t->texture = mlx_xpm_file_to_image(MLX, path, &(t->img_w), &(t->img_h));
	t->tex_data = mlx_get_data_addr(t->texture, &(t->bpp), &(t->s_l),
	&(t->endian));
	t->bpp /= 8;
	return (t);
}

t_color		get_pixel_from_texture(t_data *data)
{
	t_color		c;
	char		t;
	t_texture	*tex;
	tex = TEX[SIDE - 1];

	t = tex->tex_data[((int)tex->x * tex->bpp) + ((int)tex->y * tex->s_l) + 0];
	c.b = t;
	t = tex->tex_data[((int)tex->x * tex->bpp) + ((int)tex->y * tex->s_l) + 1];
	c.g = t;
	t = tex->tex_data[((int)tex->x * tex->bpp) + ((int)tex->y * tex->s_l) + 2];
	c.r = t;
	t = tex->tex_data[((int)tex->x * tex->bpp) + ((int)tex->y * tex->s_l) + 3];
	c.alpha = t;
	return (c);
}
