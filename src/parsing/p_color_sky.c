/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_color_sky.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:36:28 by pat               #+#    #+#             */
/*   Updated: 2023/02/03 17:03:36 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "parsing.h"

void	p_color_sky_blue(t_data *data, char *color)
{
	data->parsing.sky_blue = ft_atoi(color);
	if (data->parsing.sky_blue < 0 || data->parsing.sky_blue > 255)
		e_error(data, "BAD C BLUE COLOR (DEFINE UNTIL 0 TO 255)");
}

void	p_color_sky_green(t_data *data, char *color)
{
	data->parsing.sky_green = ft_atoi(color);
	if (data->parsing.sky_green < 0 || data->parsing.sky_green > 255)
		e_error(data, "BAD C GREEN COLOR (DEFINE UNTIL 0 TO 255)");
}

void	p_color_sky_red(t_data *data, char *color)
{
	data->parsing.sky_red = ft_atoi(color);
	if (data->parsing.sky_red < 0 || data->parsing.sky_red > 255)
		e_error(data, "BAD C RED COLOR (DEFINE UNTIL 0 TO 255)");
}
