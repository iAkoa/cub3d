/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_path.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:31:30 by pat               #+#    #+#             */
/*   Updated: 2023/01/06 23:29:52 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"
#include "parsing.h"
#include "../error/error.h"


static void p_check_path(t_data *data, char *line, int checkpoint)
{
	if (checkpoint == 0)
	{
		data->parsing.north_path =  line;
		printf("data->parsing.north_path = %s\n", data->parsing.north_path);
		// if (access(data->parsing.north_path, F_OK) == -1)
			// error(data, "BAD PATH 1!");
	}
	if (checkpoint == 1)
	{
		data->parsing.south_path =  line;
		printf("data->parsing.south_path = %s\n", data->parsing.south_path);
		// if (access(data->parsing.south_path, F_OK) == -1)
			// error(data, "BAD PATH 2!");
	}
	if (checkpoint == 2)
	{
		data->parsing.west_path =  line;
		printf("data->parsing.west_path = %s\n", data->parsing.west_path);
		// if (access(data->parsing.west_path, F_OK) == -1)
			// error(data, "BAD PATH 3!");
	}
	if (checkpoint == 3)
	{
		data->parsing.east_path =  line;
		printf("data->parsing.east_path = %s\n", data->parsing.east_path);
		// if (access(data->parsing.east_path, F_OK) == -1)
			// error(data, "BAD PATH 4!");
	}
}

/*verifie NO WE SO EA*/
static int p_strcmp(t_data *data, char *line, char *cmp)
{
	int	i;

	i = 0;
	if (!line || !cmp)
		error(data, "BAD PATH !");
	while (line[i] || cmp[i])
	{
		if (line[i] != cmp[i])
			error(data, "BAD PATH !");
		i++;
	}
	return (1);
} 

void	p_path(t_data *data, char *line, int i)
{
	char **line_split;
	
	line = gc_strtrim(&data->track, line, "\n");
	line_split = gc_split(&data->track, line, ' ');
	if (ft_strlen_split(line_split) != 2)
		error(data, "BAD PATH !");
	if (i == 0 && p_strcmp(data, line_split[0], "NO"))
		p_check_path(data, line_split[1], 0);
	if (i == 1 && p_strcmp(data, line_split[0], "SO"))
		p_check_path(data, line_split[1], 1);
	if (i == 2 && p_strcmp(data, line_split[0], "WE"))
		p_check_path(data, line_split[1], 2);
	if (i == 3 && p_strcmp(data, line_split[0], "EA"))
		p_check_path(data, line_split[1], 3);
}