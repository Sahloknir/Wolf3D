/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 10:12:19 by axbal             #+#    #+#             */
/*   Updated: 2018/04/09 13:18:19 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_color		new_color(int r, int g, int b, int alpha)
{
	t_color		c;

	c.r = (char)r;
	c.g = (char)g;
	c.b = (char)b;
	c.alpha = (char)alpha;
	return (c);
}
