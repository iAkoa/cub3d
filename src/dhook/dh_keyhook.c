/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dh_keyhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:37:54 by rmattheo          #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2022/12/13 17:10:26 by pat              ###   ########lyon.fr   */
=======
/*   Updated: 2023/01/30 17:26:10 by clora-ro         ###   ########lyon.fr   */
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"
#include "dhook.h"
#include "../draw/draw.h"

<<<<<<< Updated upstream
int	ft_keyhook(int keycode, t_data *data)
{
	ft_keyhook1(data, data->window, data->map, keycode);
	ft_keyhook2(data, data->window, data->map, keycode);
	ft_keyhook3(data, data->window, data->map, keycode);
	ft_keyhook4(data, data->window, data->map, keycode);
	ft_keyhook5(data, data->window, data->map, keycode);
=======
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

void	dh_translation(t_data *data, int keycode)
{
	if (keycode == A)
	{
		dh_moove_left(data, &data->engine);
		draw(data);
	}
	if (keycode == D)
	{
		dh_moove_right(data, &data->engine);
		draw(data);
	}
	if (keycode == W)
	{
		dh_moove_forward(data, &data->engine);
		draw(data);
	}
	if (keycode == S)
	{
		dh_moove_backward(data, &data->engine);
		draw(data);
	}
}

void	dh_rotation(t_data *data, int keycode)
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

void	dh_bonus(t_data *data, int keycode)
{
	(void)data;
	(void)keycode;
}

int	dh_keyhook(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(data->window.mlx_ptr, data->window.img);
		mlx_destroy_window(data->window.mlx_ptr, data->window.win_ptr);
		gc_free_all(&data->track);
		exit(0);
	}
	dh_translation(data, keycode);
	dh_rotation(data, keycode);
	dh_bonus(data, keycode);
>>>>>>> Stashed changes
	return (0);
}
