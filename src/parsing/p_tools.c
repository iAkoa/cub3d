/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_tools.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 05:34:49 by pat               #+#    #+#             */
/*   Updated: 2023/02/08 14:38:01 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "parsing.h"
#include "../error/error.h"

void	p_set_angle(t_data *data, t_map *map, int i)
{
	if (map[i].z == EAST)
		data->minimap.player_angle = 0;
	else if (map[i].z == NORTH)
		data->minimap.player_angle = 3 * M_PI_2;
	else if (map[i].z == WEST)
		data->minimap.player_angle = M_PI;
	else if (map[i].z == SOUTH)
		data->minimap.player_angle = M_PI_2;
}

int	ft_strlen_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*p_gnl_secure(t_data *data, char *line, char *str)
{
	line = gc_get_next_line(&data->track, data->parsing.fd);
	if (line == NULL)
		error(data, str);
	data->parsing.count++;
	return (line);
}

char	*p_gnl_jnl_secure(t_data *data, char *line, char *str)
{
	line = gc_get_next_line(&data->track, data->parsing.fd);
	if (line == NULL)
		error(data, str);
	data->parsing.count++;
	if (line[0] == '\n' && ft_strlen(line) == 1)
		line = p_gnl_jnl_secure(data, line, str);
	return (line);
}

char	*jump_new_line(t_data *data, char *line)
{
	if (line)
		line = gc_get_next_line(&data->track, data->parsing.fd);
	while (line && line[0] == '\n' && ft_strlen(line) == 1)
		line = gc_get_next_line(&data->track, data->parsing.fd);
	return (line);
}
