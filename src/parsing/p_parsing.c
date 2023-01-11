/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:48:43 by pat               #+#    #+#             */
/*   Updated: 2023/01/11 05:30:37 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"
#include "parsing.h"
#include "../error/error.h"

/*parsing floor color*/
static void	p_startspawn(t_data *data, t_map *map)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (!map[i].stop)
	{
		if (map[i].z != EMPTY && map[i].z != FLOOR && map[i].z != WALL)
		{
			data->parsing.start_spawn = i;
			data->draw.x_spawn = map[i].x;
			data->draw.y_spawn = map[i].y;
		if (map[i].z == EAST)
			data->draw.teta = 0;
		else if (map[i].z == NORTH)
			data->draw.teta = 3 * M_PI_2;
		else if (map[i].z == WEAST)
			data->draw.teta = M_PI;
		else if (map[i].z == SOUTH)
				data->draw.teta = M_PI_2;
		count++;
		}
		i++;
	}
	if (count > 1)
		error(data, "U CAN'T SPAWN EVERYWHERE !");
	if (count == 1)
		return ;
	error(data, "NO SPAWN !");
}

static void	p_parsing_color_sky(t_data *data, char *line)
{
	char **line_split;
	char **color_split;
	line = gc_strtrim(&data->track, line, "\n");
	line_split = gc_split(&data->track, line, ' ');
	if (ft_strlen_split(line_split) != 2)
		error(data, "C COLOR NOT CORRECT !");
	color_split = gc_split(&data->track, line_split[1], ',');
	if (ft_strlen_split(color_split) != 3)
		error(data, "C COLOR NOT CORRECT !");
	p_color_sky_red(data, color_split[0]);
	p_color_sky_green(data, color_split[1]);
	p_color_sky_blue(data, color_split[2]);
}

/*parsing floor color*/
static void	p_parsing_color_floor(t_data *data, char *line)
{
	char **line_split;
	char **color_split;
	line = gc_strtrim(&data->track, line, "\n");
	line_split = gc_split(&data->track, line, ' ');
	if (ft_strlen_split(line_split) != 2)
		error(data, "F COLOR NOT CORRECT !");
	color_split = gc_split(&data->track, line_split[1], ',');
	if (ft_strlen_split(color_split) != 3)
		error(data, "F COLOR NOT CORRECT !");
	p_color_floor_red(data, color_split[0]);
	p_color_floor_green(data, color_split[1]);
	p_color_floor_blue(data, color_split[2]);
}

/*parsing file*/
int	p_parsing(t_data *data, char *file)
{
	int		i;
	char	*line;

	i = -1;
	data->parsing.file = file;
	data->parsing.fd = open(file, O_RDONLY, 777);
	while (++i != 4)
	{
		line = p_gnl_jnl_secure(data, line, "PATH EMPTY !");
		p_path(data, line, i);
	}
	line = p_gnl_jnl_secure(data, line, "F COLOR EMPTY !");
	p_parsing_color_floor(data, line);
	line = p_gnl_jnl_secure(data, line, "C COLOR EMPTY !");
	p_parsing_color_sky(data, line);
	line = p_gnl_jnl_secure(data, line, "MAP EMPTY !");
	line = parsing_map(data, line);
	line = jump_new_line(data, line);
	if (line)
		error(data, "MAP INCCORECT !");
	// p_check_map(data, data->map);
	p_startspawn(data, data->map);
	p_convert_map_1d(data, data->map);
	printf("i spawn start = %i\n", data->parsing.start_spawn);
	close(data->parsing.fd);
	return (1);
}