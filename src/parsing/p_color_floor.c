/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_color_floor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:36:28 by pat               #+#    #+#             */
/*   Updated: 2023/02/03 17:03:36 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "parsing.h"
#include "../error/error.h"

void	p_color_floor_blue(t_data *data, char *color)
{
	data->parsing.floor_blue = atoi(color);
	if (data->parsing.floor_blue < 0 || data->parsing.floor_blue > 255)
		error(data, "BAD F BLUE COLOR (DEFINE UNTIL 0 TO 255)");
}

void	p_color_floor_green(t_data *data, char *color)
{
	data->parsing.floor_green = atoi(color);
	if (data->parsing.floor_green < 0 || data->parsing.floor_green > 255)
		error(data, "BAD F GREEN COLOR (DEFINE UNTIL 0 TO 255)");
}

void	p_color_floor_red(t_data *data, char *color)
{
	data->parsing.floor_red = atoi(color);
	if (data->parsing.floor_red < 0 || data->parsing.floor_red > 255)
		error(data, "BAD F RED COLOR (DEFINE UNTIL 0 TO 255)");
}
