/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 17:40:16 by axbal             #+#    #+#             */
/*   Updated: 2018/03/29 17:41:11 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

char		**get_map(void)
{
	char	**map;

	if (!(map = (char **)malloc(sizeof(char *) * 5)))
		ft_error(1);
	map[0] = "#####";
	map[1] = "#...#";
	map[2] = "#...#";
	map[3] = "#...#";
	map[4] = "#####";
	return (map);
}