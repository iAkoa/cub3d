/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 17:40:26 by pat               #+#    #+#             */
/*   Updated: 2023/01/11 05:19:18 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"
#include "parsing.h"
#include "../error/error.h"


static t_map	*p_get_map_malloc(t_data *data, t_map *map, char *line)
{
	
	while (line || data->parsing.y_max == 0)
	{
		if (line)
		{
			line = gc_strtrim(&data->track, line, "\n");
			data->parsing.y_max += 1;
			data->parsing.size_mal += ft_strlen(line);
		}
		line = gc_get_next_line(&data->track, data->parsing.fd);
	}
	close(data->parsing.fd);
	map = gc_calloc(sizeof(t_map), data->parsing.size_mal + 1, &data->track);
	map[data->parsing.size_mal].stop = 1;
	// printf("x_max = %i\n", data->x_max);
	// printf("y_max = %i\n", data->y_max);
	// printf("x_max * y_max = %i\n", data->x_max * data->y_max);
	return (map);
}

static t_map	*add_line_map(t_data *data, t_map *map, char *line, int y)
{
	int		x;
	int		x_max;
	t_map	*tmp;

	tmp = map;
	x = 0;
	while (line[x])
	{

		if (line[x] == ' ')
			map->z = EMPTY;
		else if (line[x] == '0')
			map->z = FLOOR;
		else if (line[x] == '1')
			map->z = WALL;
		else if (line[x] == 'E')
			map->z = EAST;
		else if (line[x] == 'N')
			map->z = NORTH;
		else if (line[x] == 'W')
			map->z = WEAST;
		else if (line[x] == 'S')
			map->z = SOUTH;
		else
			error(data, gc_strjoin(&data->track, line, " IS INCORRECT LINE!"));
		map->x = x;
		map->y = y;
		map->stop = 0;
		map->color = 0x00FFFFF;
		x += 1;
		// printf("pointeur map boucle while : %p\n", map);
		map++;
	}
	x_max = (double)x;
	x = 0;
	while (x <= x_max)
	{
		tmp[x].x_max = x_max;
		x++;
	}
	return (map);
}

char	*parsing_map(t_data *data, char *line)
{
	double	y;
	t_map	*tmp;

	y = -1;
	data->map = p_get_map_malloc(data, data->map, line);
	data->parsing.fd = open(data->parsing.file, O_RDONLY, 777);
	while(++y < data->parsing.count)
		line = gc_get_next_line(&data->track, data->parsing.fd);
	// printf("pointeur map  : %p\n", map);
	tmp = data->map;
	y = 0;
	while (line)
	{
		if (line[0] == '\n' && ft_strlen(line) == 1)
			break;
		line = gc_strtrim(&data->track, line, "\n");
		data->map = add_line_map(data, data->map, line, y);
		// printf("pointeur map  : %p\n", map);
		line = gc_get_next_line(&data->track, data->parsing.fd);
		y++;
	}
	data->map = tmp;
	return (line);
}