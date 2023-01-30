/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:48:43 by pat               #+#    #+#             */
/*   Updated: 2023/01/30 17:00:31 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"
#include "parsing.h"
#include "../error/error.h"


void	p_set_texture_struct(t_engine *engine, t_data *data)
{
	engine->img_n.data = mlx_xpm_file_to_image(data->window.mlx_ptr,
			data->parsing.north_path, &engine->img_n.width, &engine->img_n.height);
	engine->img_s.data = mlx_xpm_file_to_image(data->window.mlx_ptr,
			data->parsing.south_path, &engine->img_s.width, &engine->img_s.height);
	engine->img_w.data = mlx_xpm_file_to_image(data->window.mlx_ptr,
			data->parsing.west_path, &engine->img_w.width, &engine->img_w.height);
	engine->img_e.data = mlx_xpm_file_to_image(data->window.mlx_ptr,
			data->parsing.east_path, &engine->img_e.width, &engine->img_e.height);
}

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
			data->minimap.posX = map[i].x;
			data->minimap.posY = map[i].y;
			data->minimap.ref_posX = data->minimap.posX * data->minimap.size_of_bloc;
			data->minimap.ref_posY = data->minimap.posY * data->minimap.size_of_bloc;
			if (map[i].z == EAST)
				data->minimap.player_angle = 0;
			else if (map[i].z == NORTH)
				data->minimap.player_angle = 3 * M_PI_2;
			else if (map[i].z == WEST)
				data->minimap.player_angle = M_PI;
			else if (map[i].z == SOUTH)
					data->minimap.player_angle = M_PI_2;
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
	if (line_split[0][0] != 'C' && ft_strlen(line_split[0]) != 1)
		error(data, "C COLOR NOT CORRECT !");
	color_split = gc_split(&data->track, line_split[1], ',');
	if (ft_strlen_split(color_split) != 3)
		error(data, "C COLOR NOT CORRECT !");
	p_color_sky_red(data, color_split[0]);
	p_color_sky_green(data, color_split[1]);
	p_color_sky_blue(data, color_split[2]);
	data->parsing.s_color = (ft_atoi(color_split[0]) << 16) + (ft_atoi(color_split[1]) << 8)
		+ ft_atoi(color_split[2]);
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
	if (line_split[0][0] != 'F' && ft_strlen(line_split[0]) != 1)
		error(data, "F COLOR NOT CORRECT !");	
	color_split = gc_split(&data->track, line_split[1], ',');
	if (ft_strlen_split(color_split) != 3)
		error(data, "F COLOR NOT CORRECT !");
	p_color_floor_red(data, color_split[0]);
	p_color_floor_green(data, color_split[1]);
	p_color_floor_blue(data, color_split[2]);
	data->parsing.f_color = (ft_atoi(color_split[0]) << 16) + (ft_atoi(color_split[1]) << 8)
		+ ft_atoi(color_split[2]);
}

static int p_check_id(t_data * data, char *line)
{
	char **line_split;
	line_split = gc_split(&data->track, line, ' ');
	if (ft_strlen_split(line_split) != 2)
		error(data, ".CUB INCORRECT !");
	if (line_split[0][0] == 'F')
		p_parsing_color_floor(data, line); // gerer la virgule de trop
	else if (line_split[0][0] == 'C')
		p_parsing_color_sky(data, line);
	else if (p_strcmp(line_split[0], "NO") || p_strcmp(line_split[0], "SO")  || p_strcmp(line_split[0], "EA") || p_strcmp(line_split[0], "WE"))
		p_path(data, line);
	else
		return (0);
	return (1);
}
/*parsing file*/
int	p_parsing(t_data *data, char *file)
{
	int		i;
	char	*line;

	i = -1;
	
	data->parsing.file = file;
	data->parsing.fd = open(file, O_RDONLY, 777);
	while (++i != 6)
	{
		line = p_gnl_jnl_secure(data, line, ".CUB INCORRECT!");
		printf("line = %s\n", line);
		if (!p_check_id(data, line))
			error(data, "TEXTURE OU INFORMATION OU HEADER INCORRECTS !");
	}
	line = p_gnl_jnl_secure(data, line, ".CUB INCORRECT!");
	line = p_parsing_map(data, line);
	printf("line sorti de parsing = %s\n", line);
	line = jump_new_line(data, line);
	if (line && (line[0] != '\n' || ft_strlen(line) != 1))
		error(data, ".CUB INCORRECT\n");
	p_check_map(data, data->map);
	p_startspawn(data, data->map);
	p_convert_map_1d(data, data->map);
	// printf("i spawn start = %i\n", data->parsing.start_spawn); 
	// close(data->parsing.fd);
	return (1);
}