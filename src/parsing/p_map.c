/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 17:40:26 by pat               #+#    #+#             */
/*   Updated: 2023/02/08 15:42:33 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "parsing.h"

void	p_startspawn(t_data *data, t_map *map)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (!map[++i].stop)
	{
		if (map[i].z != EMPTY && map[i].z != FLOOR && map[i].z != WALL)
		{
			data->parsing.start_spawn = i;
			data->minimap.posx = map[i].x;
			data->minimap.posy = map[i].y;
			data->minimap.ref_posx
				= data->minimap.posx * data->minimap.size_of_bloc;
			data->minimap.ref_posy
				= data->minimap.posy * data->minimap.size_of_bloc;
			p_set_angle(data, map, i);
			count++;
		}
	}
	if (count > 1)
		e_error(data, "U CAN'T SPAWN EVERYWHERE !");
	if (count == 1)
		return ;
	e_error(data, "NO SPAWN !");
}

static t_map	*p_get_map_malloc(t_data *data, t_map *map, char *line)
{
	while (line)
	{
		if (line[0] == '\n' && ft_strlen(line) == 1)
			break ;
		if (line)
		{
			line = gc_strtrim(&data->track, line, "\n");
			data->parsing.y_max += 1;
			if (ft_strlen(line) > (size_t)data->parsing.x_max)
				data->parsing.x_max = ft_strlen(line);
		}
		line = gc_get_next_line(&data->track, data->parsing.fd);
	}
	data->parsing.size_mal = data->parsing.y_max * data->parsing.x_max;
	map = gc_calloc(sizeof(t_map), data->parsing.size_mal + 1, &data->track);
	map[data->parsing.size_mal].stop = 1;
	data->mapchar = gc_calloc(sizeof(char),
			data->parsing.size_mal + 1, &data->track);
	data->mapchar[data->parsing.size_mal] = 0;
	return (map);
}

static void	p_fill_map(t_data *data, t_map *map, char *line, int x)
{
	if (!line[x])
		map->z = EMPTY;
	else if (line[x] == ' ')
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
		map->z = WEST;
	else if (line[x] == 'S')
		map->z = SOUTH;
	else
		e_error(data, gc_strjoin(&data->track, line, " IS INCORRECT LINE!"));
}

static t_map	*add_line_map(t_data *data, t_map *map, char *line, int y)
{
	int		x;
	int		i;

	i = 0;
	x = 0;
	while (i < data->parsing.x_max && i * y < data->parsing.size_mal)
	{
		p_fill_map(data, map, line, x);
		map->x = x;
		map->y = y;
		map->stop = 0;
		map->color = 0x00FFFFF;
		if (line[x])
			x++;
		i ++;
		data->parsing.test += 1;
		map++;
	}
	return (map);
}

char	*p_parsing_map(t_data *data, char *line)
{
	double	y;
	t_map	*tmp;

	y = -1;
	data->map = p_get_map_malloc(data, data->map, line);
	close(data->parsing.fd);
	data->parsing.fd = open(data->parsing.file, O_RDONLY);
	while (++y < data->parsing.count)
		line = gc_get_next_line(&data->track, data->parsing.fd);
	tmp = data->map;
	y = 0;
	while (y < data->parsing.y_max)
	{
		if (line[0] == '\n' && ft_strlen(line) == 1)
			break ;
		line = gc_strtrim(&data->track, line, "\n");
		data->map = add_line_map(data, data->map, line, y);
		line = gc_get_next_line(&data->track, data->parsing.fd);
		y++;
	}
	data->map = tmp;
	return (line);
}
