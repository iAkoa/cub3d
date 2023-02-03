/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_convert_map_1d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:10:49 by pat               #+#    #+#             */
/*   Updated: 2023/02/03 17:03:36 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "parsing.h"
#include "../error/error.h"

static void	p_fill_map_2d(t_map *map1d, t_map **map2d)
{
	int	i;
	int	x;
	int	y;

	y = 0;
	i = 0;
	while (!map1d[i].stop)
	{
		x = 0;
		while (!map1d[i].stop && map1d[i].y == y)
		{
			map2d[y][x].z = map1d[i].z;
			map2d[y][x].x = x;
			x++;
			i++;
		}
		y++;
	}
}

void	p_convert_map_1d(t_data *data, t_map *map1d)
{
	int	i;
	int	tmp_y;

	i = 0;
	tmp_y = 0;
	data->map2d = gc_calloc(sizeof(t_map *),
			data->parsing.y_max + 1, &data->track);
	data->map2d[0] = gc_calloc(sizeof(t_map),
			data->parsing.x_max + 1, &data->track);
	data->map2d[0][data->parsing.x_max].stop = 1;
	while (!map1d[i].stop)
	{
		if (tmp_y != map1d[i].y)
		{
			data->map2d[(int)map1d[i].y] = gc_calloc(sizeof(t_map),
					data->parsing.x_max + 1, &data->track);
			data->map2d[(int)map1d[i].y][data->parsing.x_max].stop = 1;
		}
		tmp_y = map1d[i].y;
		i++;
	}
	p_fill_map_2d(map1d, data->map2d);
}
