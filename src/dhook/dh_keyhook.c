/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dh_keyhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:37:54 by rmattheo          #+#    #+#             */
/*   Updated: 2023/02/03 18:36:23 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
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

void	dh_translation(t_data *data)
{
	if (data->tab_keycode[0] == 1)
		dh_moove_left(data, &data->engine);
	if (data->tab_keycode[3] == 1)
		dh_moove_right(data, &data->engine);
	if (data->tab_keycode[1] == 1)
		dh_moove_forward(data, &data->engine);
	if (data->tab_keycode[2] == 1)
		dh_moove_backward(data, &data->engine);
}

void	dh_rotation(t_data *data)
{
	if (data->tab_keycode[5] == 1)
	{
		dh_rotation_left(data, &data->engine);
		dh_rotation_minimap_left(data, &data->minimap);
	}
	if (data->tab_keycode[6] == 1)
	{
		dh_rotation_right(data, &data->engine);
		dh_rotation_minimap_right(data, &data->minimap);
	}
}

int	dh_keyrelease(int keycode, t_data *data)
{
	if (keycode == A)
		data->tab_keycode[0] = 0;
	if (keycode == W)
		data->tab_keycode[1] = 0;
	if (keycode == S)
		data->tab_keycode[2] = 0;
	if (keycode == D)
		data->tab_keycode[3] = 0;
	if (keycode == ESC)
		data->tab_keycode[4] = 0;
	if (keycode == LEFT_ARROW)
		data->tab_keycode[5] = 0;
	if (keycode == RIGHT_ARROW)
		data->tab_keycode[6] = 0;
	return (0);
}

int	dh_keyhook(int keycode, t_data *data)
{
	if (keycode == A)
		data->tab_keycode[0] = 1;
	if (keycode == W)
		data->tab_keycode[1] = 1;
	if (keycode == S)
		data->tab_keycode[2] = 1;
	if (keycode == D)
		data->tab_keycode[3] = 1;
	if (keycode == ESC)
		data->tab_keycode[4] = 1;
	if (keycode == LEFT_ARROW)
		data->tab_keycode[5] = 1;
	if (keycode == RIGHT_ARROW)
		data->tab_keycode[6] = 1;
	return (0);
}
