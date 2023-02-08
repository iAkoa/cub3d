/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_engine_minimap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:13:19 by pat               #+#    #+#             */
/*   Updated: 2023/02/03 19:35:05 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "engine.h"
#include "../draw/draw.h"
#include "../init/init.h"

static void	e_position(t_data *data, int posx, int posy)
{
	int	posxdisplay;
	int	posydisplay;

	posxdisplay = posx - 5;
	posydisplay = posy - 5;
	while (posxdisplay < posx + 5)
	{
		posydisplay = posy - 5;
		while (posydisplay < posy + 5)
		{
			d_my_mlx_pixel_put_player(data, posxdisplay, posydisplay,
				PLAYER_COLOR);
			posydisplay++;
		}
		posxdisplay++;
	}
}

void	e_bloc_minimap_condition(t_data *data, t_minimap minimap, int x, int y)
{
	if (((x == 0 || y == 0 || x == 1 || y == 1
				|| x == minimap.size_of_bloc - 1
				|| y == minimap.size_of_bloc - 1
				|| x == minimap.size_of_bloc
				|| y == minimap.size_of_bloc))
		&& data->map2d[minimap.y][minimap.x].z == WALL)
		d_my_mlx_pixel_put_minimap(data, x + minimap.x_display,
			y + minimap.y_display, GRID_WALL_COLOR);
	else if ((x == 0 || y == 0 || x == 1 || y == 1
			|| x == minimap.size_of_bloc - 1
			|| y == minimap.size_of_bloc - 1
			|| x == minimap.size_of_bloc
			|| y == minimap.size_of_bloc)
		&& data->map2d[minimap.y][minimap.x].z != EMPTY)
		d_my_mlx_pixel_put_minimap(data, x + minimap.x_display,
			y + minimap.y_display, GRID_COLOR);
	else if (data->map2d[minimap.y][minimap.x].z == WALL)
		d_my_mlx_pixel_put_minimap(data, x + minimap.x_display,
			y + minimap.y_display, WALL_COLOR);
	else if (data->map2d[minimap.y][minimap.x].z != WALL
		&& data->map2d[minimap.y][minimap.x].z != EMPTY)
		d_my_mlx_pixel_put_minimap(data, x + minimap.x_display,
			y + minimap.y_display, FLOOR_COLOR);
}

static void	e_bloc_minimap(t_data *data, t_minimap minimap, t_map **map)
{
	int	x;
	int	y;

	y = -1;
	while (++y < minimap.size_of_bloc)
	{
		x = -1;
		while (++x < minimap.size_of_bloc)
		{
			e_bloc_minimap_condition(data, minimap, x, y);
			if (map[minimap.y][minimap.x].z != WALL
				&& map[minimap.y][minimap.x].z
				!= EMPTY && map[minimap.y][minimap.x].z != FLOOR)
			{
				if (x == minimap.size_of_bloc / 2
					&& y == (minimap.size_of_bloc / 2))
				{
					data->minimap.posx_display = x + minimap.x_display
						- data->minimap.moove_mapx;
					data->minimap.posy_display = y + minimap.y_display
						- data->minimap.moove_mapy;
				}
			}
		}
	}
}

void	e_minimap(t_data *data, t_minimap minimap, t_map **map)
{
	minimap.y = 0;
	data->minimap.hit_bottom = 0;
	data->minimap.hit_top = 0;
	data->minimap.hit_left = 0;
	data->minimap.hit_right = 0;
	minimap.y_display = data->minimap.moove_mapy
		- ((minimap.posy * 32) - (minimap.size_of_bloc * 4));
	while (minimap.y < data->parsing.y_max)
	{
		minimap.x = 0;
		minimap.x_display = data->minimap.moove_mapx
			- ((minimap.posx * 32) - (minimap.size_of_bloc * 5));
		while (minimap.x < data->parsing.x_max)
		{
			e_bloc_minimap(data, minimap, map);
			minimap.x_display += minimap.size_of_bloc;
			minimap.x++;
		}
		minimap.y_display += minimap.size_of_bloc;
		minimap.y++;
		data->minimap.size_check = 0;
	}
	e_position(data, data->minimap.posx_display, data->minimap.posy_display);
}
