/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_3d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 03:29:04 by pat               #+#    #+#             */
/*   Updated: 2023/01/25 03:57:07 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"
#include "draw.h"
#include "../engine/engine.h"

float	d_floor(t_data *data, float j, float i)
{
	while (i < 1080)
	{
		if (j < 1919 && i < 1079 && j >= 0 && i >= 0)
			d_my_mlx_pixel_put(data, (int)j, (int)i, 0x0000FF00);
		i++;
	}
	return (i);
}

void	d_vertical_wall(t_data *data, t_engine *engine, float j, float i)
{

	if (engine->ray_v.rx < engine->posx)
		d_my_mlx_pixel_put(data, (int)j, (int)i,
			0x000000FF);
	if (engine->ray_v.rx > engine->posx)
		d_my_mlx_pixel_put(data, (int)j, (int)i,
			0x00FF0000);
}

float	d_wall(t_data *data, t_engine *engine, float j, float i)
{

	while (i < (540 + engine->lineh / 2))
	{
		if (j < 1919 && i < 1079 && j >= 0 && i >= 0)
		{
			if (engine->v_check == 1)
				d_vertical_wall(data, engine, j, i);
			else
			{
				if (engine->ray_h.ry > engine->posy)
					d_my_mlx_pixel_put(data, (int)j, (int)i,
						0x00FFFF00);
				if (engine->ray_h.ry < engine->posy)
					d_my_mlx_pixel_put(data, (int)j, (int)i,
						0x00FF00FF);
			}
		}
		i++;
	}
	return (i);
}

float	d_ceil(t_data *data, t_engine *engine, float j, float i)
{
			// printf("data->parsing.s_color = %f\n", 540 - engine->lineh / 2);
	while (i < (540 - engine->lineh / 2))
	{
		if (j < 1919 && i < 1079 && j >= 0 && i >= 0)
		{
			d_my_mlx_pixel_put(data, (int)j,
				(int)i, 0x000000FF);
		}
		i++;
	}
	return (i);
}

void	d_3d(t_data *data, t_engine *engine, float j)
{
	float i = 0;

	i = 0;
	i = d_ceil(data, engine, j, i);
	i = d_wall(data, engine, j, i);
	i = d_floor(data, j, i);
}