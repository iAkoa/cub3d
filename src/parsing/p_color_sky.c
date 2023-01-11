/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_color_sky.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:36:28 by pat               #+#    #+#             */
/*   Updated: 2023/01/07 03:11:28 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/cube3d.h"
#include "parsing.h"
#include "../error/error.h"

void p_color_sky_blue(t_data *data, char *color)
{
	data->parsing.sky_blue = atoi(color);
	if (data->parsing.sky_blue < 0 || data->parsing.sky_blue > 255)
		error(data, "BAD C BLUE COLOR (DEFINE UNTIL 0 TO 255)");
	printf("data->parsing.sky_blue = %i\n", data->parsing.sky_blue);
}

void p_color_sky_green(t_data *data, char *color)
{
	data->parsing.sky_green = atoi(color);
	if (data->parsing.sky_green < 0 || data->parsing.sky_green > 255)
		error(data, "BAD C GREEN COLOR (DEFINE UNTIL 0 TO 255)");
	printf("data->parsing.sky_green = %i\n", data->parsing.sky_green);
}

void p_color_sky_red(t_data *data, char *color)
{
	data->parsing.sky_red = atoi(color);
	if (data->parsing.sky_red < 0 || data->parsing.sky_red > 255)
		error(data, "BAD C RED COLOR (DEFINE UNTIL 0 TO 255)");
	printf("data->parsing.sky_red = %i\n", data->parsing.sky_red);
}