/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_tools.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 05:34:49 by pat               #+#    #+#             */
/*   Updated: 2023/01/09 13:35:27 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"
#include "parsing.h"
#include "../error/error.h"

int ft_strlen_split(char **str)
{
	int i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *p_gnl_secure(t_data *data, char *line, char *str)
{
	line = gc_get_next_line(&data->track, data->parsing.fd);
	if(line == NULL)
		error(data, str);
	data->parsing.count++;
	return (line);
}

char *p_gnl_jnl_secure(t_data *data, char *line, char *str)
{
	line = gc_get_next_line(&data->track, data->parsing.fd);
	if(line == NULL)
		error(data, str);
	data->parsing.count++;
	if (line[0] == '\n' && ft_strlen(line) == 1)
		line = p_gnl_jnl_secure(data, line, str);
	return (line);
}


char	*jump_new_line(t_data *data, char *line)
{
	while (line && line[0] == '\n' && ft_strlen(line) == 1)
		line = gc_get_next_line(&data->track, data->parsing.fd);
	return (line);
}