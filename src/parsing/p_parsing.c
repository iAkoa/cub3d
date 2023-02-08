/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:48:43 by pat               #+#    #+#             */
/*   Updated: 2023/02/03 19:25:02 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "parsing.h"
#include "../error/error.h"

static void	p_parsing_color_sky(t_data *data, char *line)
{
	char	**line_split;
	char	**color_split;

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
	data->parsing.s_color = (ft_atoi(color_split[0]) << 16)
		+ (ft_atoi(color_split[1]) << 8)
		+ ft_atoi(color_split[2]);
	data->parsing.checker += 1;
}

static void	p_parsing_color_floor(t_data *data, char *line)
{
	char	**line_split;
	char	**color_split;

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
	data->parsing.f_color = (ft_atoi(color_split[0]) << 16)
		+ (ft_atoi(color_split[1]) << 8)
		+ ft_atoi(color_split[2]);
	data->parsing.checker += 10;
}

static int	p_check_id(t_data *data, char *line)
{
	char	**line_split;

	line_split = gc_split(&data->track, line, ' ');
	if (ft_strlen_split(line_split) != 2)
		error(data, ".CUB INCORRECT !");
	if (line_split[0][0] == 'F')
		p_parsing_color_floor(data, line);
	else if (line_split[0][0] == 'C')
		p_parsing_color_sky(data, line);
	else if (p_strcmp(line_split[0], "NO")
		|| p_strcmp(line_split[0], "SO")
		|| p_strcmp(line_split[0], "EA")
		|| p_strcmp(line_split[0], "WE"))
		p_path(data, line);
	else
		return (0);
	return (1);
}

int	p_parsing(t_data *data, char *file)
{
	int		i;
	char	*line;

	i = -1;
	data->parsing.file = file;
	data->parsing.fd = open(file, O_RDONLY, 777);
	if (data->parsing.fd == -1)
		error(data, "MAUVAIS LE .CUB !");
	while (++i != 6)
	{
		line = p_gnl_jnl_secure(data, line, ".CUB INCORRECT!");
		if (!p_check_id(data, line))
			error(data, "TEXTURE OU INFORMATION OU HEADER INCORRECTS !");
	}
	printf("checker %i\n", data->parsing.checker);
	if (data->parsing.checker != 111111)
		error(data, "TEXTURE OU INFORMATION OU HEADER INCORRECTS !");
	line = p_gnl_jnl_secure(data, line, ".CUB INCORRECT!");
	line = p_parsing_map(data, line);
	line = jump_new_line(data, line);
	if (line && (line[0] != '\n' || ft_strlen(line) != 1))
		error(data, ".CUB INCORRECT\n");
	p_check_map(data, data->map);
	p_startspawn(data, data->map);
	p_convert_map_1d(data, data->map);
	return (1);
}
