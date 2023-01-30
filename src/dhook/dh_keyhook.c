/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dh_keyhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:37:54 by rmattheo          #+#    #+#             */
/*   Updated: 2023/01/30 11:55:17 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"
#include "dhook.h"
#include "../draw/draw.h"


void	set_xo_and_yo_for_side_walk(t_engine *engine)
{
	if (engine->pdx > 0 && engine->pdy > 0)
	{
		engine->collision.xo = 10;
		engine->collision.yo = -10;
	}
	if (engine->pdx < 0 && engine->pdy < 0)
	{
		engine->collision.xo = -10;
		engine->collision.yo = 10;
	}
	if (engine->pdx > 0 && engine->pdy < 0)
	{
		engine->collision.xo = 10;
		engine->collision.yo = 10;
	}
	if (engine->pdx < 0 && engine->pdy > 0)
	{
		engine->collision.xo = -10;
		engine->collision.yo = -10;
	}
}

void dh_translation(t_data *data,int keycode)
{
	if (keycode == A)
	{
		// dh_moove_minimap_left(data, &data->engine);
		dh_moove_left(data, &data->engine);
		draw(data);
	}
	if (keycode == D)
	{
		// dh_moove_minimap_right(data, &data->engine);
		dh_moove_right(data, &data->engine);
		draw(data);
	}
	if (keycode == W)
	{
		// dh_moove_minimap_forward(data, &data->engine);
		dh_moove_forward(data, &data->engine);
		draw(data);
	}
	if (keycode == S)
	{
		// dh_moove_minimap_backward(data, &data->engine);
		dh_moove_backward(data, &data->engine);
		draw(data);
	}
}

void dh_rotation(t_data *data,int keycode)
{
	if (keycode == LEFT_ARROW)
	{
		dh_rotation_left(data, &data->engine);
		dh_rotation_minimap_left(data, &data->minimap);
		draw(data);
	}
	if (keycode == RIGHT_ARROW)
	{
		dh_rotation_right(data, &data->engine);
		dh_rotation_minimap_right(data, &data->minimap);
		draw(data);
	}
}

void dh_bonus(t_data *data,int keycode)
{
	(void)data;
	(void)keycode;
}

int	dh_keyhook(int keycode, t_data *data)
{
	// printf("keycode = %i\n", keycode);
	if (keycode == ESC)
	{
		mlx_destroy_image(data->window.mlx_ptr, data->window.img);
		mlx_destroy_window(data->window.mlx_ptr, data->window.win_ptr);
		gc_free_all(&data->track);
		exit(0);
	}
	dh_translation(data, keycode);
	dh_rotation(data, keycode);
	// dh_translation_minimap(data, keycode);
	dh_bonus(data, keycode);
	return (0);
}
