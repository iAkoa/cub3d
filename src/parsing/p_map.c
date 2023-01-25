/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 17:40:26 by pat               #+#    #+#             */
/*   Updated: 2023/01/25 06:04:25 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"
#include "parsing.h"
#include "../error/error.h"


static t_map	*p_get_map_malloc(t_data *data, t_map *map, char *line)
{
	
	while (line)
	{
		// printf("lione = %s\n", line);
		if (line[0] == '\n' && ft_strlen(line) == 1)
			break;
		if (line)
		{
			line = gc_strtrim(&data->track, line, "\n");
			data->parsing.y_max += 1;
			if (ft_strlen(line) > (size_t)data->parsing.x_max)
				data->parsing.x_max = ft_strlen(line);
		}
		line = gc_get_next_line(&data->track, data->parsing.fd);
	}
	close(data->parsing.fd);
	data->parsing.size_mal = data->parsing.y_max * data->parsing.x_max;
	// printf("data->parsing.y_max * data->parsing.x_max = %i\n" , data->parsing.y_max * data->parsing.x_max);
	map = gc_calloc(sizeof(t_map), data->parsing.size_mal + 1, &data->track);
	map[data->parsing.size_mal].stop = 1;
	data->mapchar = gc_calloc(sizeof(char), data->parsing.size_mal + 1, &data->track);
	data->mapchar[data->parsing.size_mal] = 0;
	// printf("x_max = %i\n", data->x_max);
	// printf("y_max = %i\n", data->y_max);
	// printf("x_max * y_max = %i\n", data->x_max * data->y_max);
	return (map);
}

int add_line_mapchar(t_data *data, char *map, char *line, int y, int i)
{
	int		x;
	int count;
	
	x = 0;
	count = 0;
	// printf(">>>>>>>>>>>> y = %i\n", y);
	while (count < data->parsing.x_max && count * y  < data->parsing.size_mal)
	{
		// printf("line = %s\n", line);
		// printf("line = %s\n", line);
		// printf("line[x] = %c\n", line[x]);
		// printf("x = %i\n", x);
		// printf("y = %i\n", y);
		// printf("i = %i\n", i);
		// printf("data->parsing.x_max = %i\n", data->parsing.x_max);
		// printf("data->parsing.y_max = %i\n", data->parsing.y_max);
		if (!line[x])
			map[i] = ' ';
		else if (line[x] == ' ')
			map[i] = line[x];
		else if (line[x] == '0')
			map[i] = line[x];
		else if (line[x] == '1')
			map[i] = line[x];
		else if (line[x] == 'E')
			map[i] = line[x];
		else if (line[x] == 'N')
			map[i] = line[x];
		else if (line[x] == 'W')
			map[i] = line[x];
		else if (line[x] == 'S')
			map[i] = line[x];
		else
			error(data, gc_strjoin(&data->track, line, " IS INCORRECT LINE!"));
		if (line[x])
			x++;
		count++;
		i ++;
		// printf("pointeur map[i] boucle while : %p\n", map);
		data->parsing.test += 1;
		// printf("y * x = %i\n", y * x );
		// printf("test = %i\n", data->parsing.test);
	}
	if (x > data->draw.map_Xmax)
		data->draw.map_Xmax = x;
	data->draw.map_Ymax++;
	return (i);
}


static t_map	*add_line_map(t_data *data, t_map *map, char *line, int y)
{
	int		x;
	int		i;
	
	i = 0;
	x = 0;
	// printf(">>>>>>>>>>>> y = %i\n", y);
	while (i < data->parsing.x_max &&  i * y < data->parsing.size_mal)
	{
		// printf("line = %s\n", line);
		// printf("line[x] = %c\n", line[x]);
		// printf("x = %i\n", x);
		// printf("y = %i\n", y);
		// printf("i = %i\n", i);
		// printf("data->parsing.x_max = %i\n", data->parsing.x_max);
		// printf("data->parsing.y_max = %i\n", data->parsing.y_max);
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
			error(data, gc_strjoin(&data->track, line, " IS INCORRECT LINE!"));
		map->x = x;
		map->y = y;
		map->stop = 0;
		map->color = 0x00FFFFF;
		if (line[x])
			x++;
		i ++;
		// printf("pointeur map boucle while : %p\n", map);
		data->parsing.test += 1;
		// printf("y * x = %i\n", y * x );
		// printf("test = %i\n", data->parsing.test);
		map++;
	}
	if (x > data->draw.map_Xmax)
		data->draw.map_Xmax = x;
	data->draw.map_Ymax++;
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
	int i = 0;
	while (y < data->parsing.y_max)
	{
		if (line[0] == '\n' && ft_strlen(line) == 1)
			break;
		line = gc_strtrim(&data->track, line, "\n");
		data->map = add_line_map(data, data->map, line, y);
		i = add_line_mapchar(data, data->mapchar, line, y, i);
		// printf("pointeur map  : %p\n", map);
		line = gc_get_next_line(&data->track, data->parsing.fd);
		y++;
	}

	data->map = tmp;
	return (line);
}