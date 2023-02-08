/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_path.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:31:30 by pat               #+#    #+#             */
/*   Updated: 2023/02/03 19:24:27 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "parsing.h"

void	p_set_texture_struct(t_engine *engine, t_data *data)
{
	engine->img_n.data = mlx_xpm_file_to_image(data->window.mlx_ptr,
			data->parsing.north_path,
			&engine->img_n.width, &engine->img_n.height);
	engine->img_s.data = mlx_xpm_file_to_image(data->window.mlx_ptr,
			data->parsing.south_path,
			&engine->img_s.width, &engine->img_s.height);
	engine->img_w.data = mlx_xpm_file_to_image(data->window.mlx_ptr,
			data->parsing.west_path,
			&engine->img_w.width, &engine->img_w.height);
	engine->img_e.data = mlx_xpm_file_to_image(data->window.mlx_ptr,
			data->parsing.east_path,
			&engine->img_e.width, &engine->img_e.height);
	if (!engine->img_n.data || !engine->img_s.data
		|| !engine->img_w.data || !engine->img_e.data)
		e_error(data, "BAD PATH TEXTURE !");
}

static void	p_check_path_condition(t_data *data, char *line, int checkpoint)
{
	if (checkpoint == 2)
	{
		data->parsing.checker += 10000;
		data->parsing.west_path = line;
		if (open(data->parsing.west_path, O_RDONLY, 777) == -1)
			e_error(data, "BAD PATH 3!");
	}
	if (checkpoint == 3)
	{
		data->parsing.checker += 100000;
		data->parsing.east_path = line;
		if (open(data->parsing.east_path, O_RDONLY, 777) == -1)
			e_error(data, "BAD PATH 4!");
	}
}

static void	p_check_path(t_data *data, char *line, int checkpoint)
{
	if (checkpoint == 0)
	{
		data->parsing.checker += 100;
		data->parsing.north_path = line;
		if (open(data->parsing.north_path, O_RDONLY, 777) == -1)
			e_error(data, "BAD PATH 1!");
	}
	if (checkpoint == 1)
	{
		data->parsing.checker += 1000;
		data->parsing.south_path = line;
		if (open(data->parsing.south_path, O_RDONLY, 777) == -1)
			e_error(data, "BAD PATH 2!");
	}
	p_check_path_condition(data, line, checkpoint);
}

int	p_strcmp(char *line, char *cmp)
{
	int	i;

	i = 0;
	if (!line || !cmp)
		return (0);
	while (line[i] || cmp[i])
	{
		if (line[i] != cmp[i])
			return (0);
		i++;
	}
	return (1);
}

void	p_path(t_data *data, char *line)
{
	char	**line_split;

	line = gc_strtrim(&data->track, line, "\n");
	line_split = gc_split(&data->track, line, ' ');
	if (p_strcmp(line_split[0], "NO"))
		p_check_path(data, line_split[1], 0);
	if (p_strcmp(line_split[0], "SO"))
		p_check_path(data, line_split[1], 1);
	if (p_strcmp(line_split[0], "WE"))
		p_check_path(data, line_split[1], 2);
	if (p_strcmp(line_split[0], "EA"))
		p_check_path(data, line_split[1], 3);
}
