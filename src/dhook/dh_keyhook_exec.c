/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dh_keyhook_exec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 03:44:17 by pat               #+#    #+#             */
/*   Updated: 2023/01/11 05:47:10 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"
#include "dhook.h"
#include "../draw/draw.h"

void	ft_keyhook1(t_data *data, t_window win, t_map *map, int keycode)
{
	(void)map;
	(void)data;

	printf("keycode  %i\n", keycode);
	if (keycode == ESC)
	{
		mlx_destroy_image(win.mlx_ptr, win.img);
		mlx_destroy_window(win.mlx_ptr, win.win_ptr);
		gc_free_all(&data->track);
		exit(0);
	}
	if (keycode == UP_ARROW)
	{
		data->draw.x_spawn_display++;
		ft_keyhook_process(win);
		d_minimap(data, data->draw, data->map2d);
	}
	if (keycode == DOWN_ARROW)
	{
		// ->map = ft_translation(w->map, 1);
		ft_keyhook_process(win);
		// ft_draw(data, map);
	}
	if (keycode == LEFT_ARROW)
	{
		// w->map = ft_translation(w->map, 4);
		ft_keyhook_process(win);
		// ft_draw(data, map);
	}
}

void	ft_keyhook2(t_data *data, t_window win, t_map *map, int keycode)
{
	(void)map;
	(void)data;


	if (keycode == RIGHT_ARROW)
	{
		// w->map = ft_translation(w->map, 3);
		ft_keyhook_process(win);
		// ft_draw(data, map);
	}
	if (keycode == MORE || keycode == T)
	{
		// w->map = ft_zoom(w->map, 1, w);
		ft_keyhook_process(win);
		// ft_draw(data, map);
	}
	if (keycode == LESS || keycode == R)
	{
		// w->map = ft_zoom(w->map, -1, w);
		ft_keyhook_process(win);
		// ft_draw(data, map);
	}
}

void	ft_keyhook3(t_data *data, t_window win, t_map *map, int keycode)
{
	(void)map;
	(void)data;


	if (keycode == ONE_NUM_PAD || keycode == Q)
	{
		// w->map = ft_rotation(w->map, 1);
		ft_keyhook_process(win);
		// ft_draw(data, map);
	}
	if (keycode == TWO_NUM_PAD || keycode == W)
	{
		// w->map = ft_rotation(w->map, 2);
		ft_keyhook_process(win);
		// ft_draw(data, map);
	}
	if (keycode == THREE_NUM_PAD || keycode == E)
	{
		// w->map = ft_rotation(w->map, 3);
		ft_keyhook_process(win);
		// ft_draw(data, map);
	}
	if (keycode == SIX_NUM_PAD || keycode == A)
	{
		// w->map = ft_rotation(w->map, -3);
		ft_keyhook_process(win);
		// ft_draw(data, map);
	}
}

void	ft_keyhook4(t_data *data, t_window win, t_map *map, int keycode)
{
	(void)map;
	(void)data;


	if (keycode == FIVE_NUM_PAD || keycode == S)
	{
		// w->map = ft_rotation(w->map, -2);
		ft_keyhook_process(win);
		// ft_draw(data, map);
	}
	if (keycode == FOUR_NUM_PAD || keycode == D)
	{
		// w->map = ft_rotation(w->map, -1);
		ft_keyhook_process(win);
		// ft_draw(data, map);
	}
}

void	ft_keyhook5(t_data *data, t_window win, t_map *map, int keycode)
{
	(void)map;
	(void)data;


	if (keycode == X)
	{
		ft_keyhook_process(win);
		// ft_draw(data, map);
	}
}
