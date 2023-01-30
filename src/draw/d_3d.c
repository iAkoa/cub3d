/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_3d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 03:29:04 by pat               #+#    #+#             */
/*   Updated: 2023/01/30 19:47:41 by clora-ro         ###   ########lyon.fr   */
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
						e_get_value(engine, &(data->engine.img_n),
							(int)j, (int)i));
				if (engine->ray_h.ry < engine->posy)
					d_my_mlx_pixel_put(data, (int)j, (int)i,
						e_get_value(engine, &(data->engine.img_s),
							(int)j, (int)i));
			}
		}
		i++;
	}
	return (i);
}

float	d_ceil(t_data *data, t_engine *engine, float j, float i)
{
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
	float	i;

	i = 0;
	i = d_ceil(data, engine, j, i);
	i = d_wall(data, engine, j, i);
	i = d_floor(data, j, i);
}
