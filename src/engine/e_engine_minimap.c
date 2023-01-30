/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_engine_minimap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:13:19 by pat               #+#    #+#             */
/*   Updated: 2023/01/30 19:33:09 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"
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
			d_my_mlx_pixel_put_player(data, posxdisplay,
				posydisplay, PLAYER_COLOR);
			posydisplay++;
		}
		posxdisplay++;
	}
}

static void	e_bloc_minimap(t_data *data, t_minimap minimap, t_map **map)
{
	int	x;
	int	y;
	int	x_display;
	int	y_display;

	y = 0;
	(void)x_display;
	(void)y_display;
	while (y < minimap.size_of_bloc
		&& minimap.y_display < minimap.y_max_minimap)
	{
		x = 0;
		y_display = y + minimap.y_display;
		while (x < minimap.size_of_bloc
			&& minimap.x_display < minimap.x_max_minimap)
		{
			x_display = x + minimap.x_display;
			if (((x == 0 || y == 0 || x == 1 || y == 1
						|| x == minimap.size_of_bloc - 1
						|| y == minimap.size_of_bloc - 1
						|| x == minimap.size_of_bloc
						|| y == minimap.size_of_bloc))
				&& map[minimap.y][minimap.x].z == WALL)
				d_my_mlx_pixel_put_minimap(data, x + minimap.x_display,
					y + minimap.y_display, GRID_WALL_COLOR);
			else if ((x == 0 || y == 0 || x == 1 || y == 1
						|| x == minimap.size_of_bloc - 1
						|| y == minimap.size_of_bloc - 1 || x == minimap.size_of_bloc
						|| y == minimap.size_of_bloc)
				&& map[minimap.y][minimap.x].z != EMPTY)
				d_my_mlx_pixel_put_minimap(data, x + minimap.x_display,
					y + minimap.y_display, GRID_COLOR);
			else if (map[minimap.y][minimap.x].z == WALL)
				d_my_mlx_pixel_put_minimap(data, x + minimap.x_display,
					y + minimap.y_display, WALL_COLOR);
			else if (map[minimap.y][minimap.x].z != WALL
				&& map[minimap.y][minimap.x].z != EMPTY)
				d_my_mlx_pixel_put_minimap(data,x + minimap.x_display,
					y + minimap.y_display, FLOOR_COLOR);
			if (map[minimap.y][minimap.x].z != WALL
				&& map[minimap.y][minimap.x].z != EMPTY
				&& map[minimap.y][minimap.x].z != FLOOR)
				if (x == minimap.size_of_bloc / 2
					&& y == minimap.size_of_bloc / 2)
				{
					
					data->minimap.posX_display = data->dhook.moove_spawn_x
							+ x + minimap.x_display - data->minimap.moove_mapX;
					data->minimap.posY_display = data->dhook.moove_spawn_y
							+ y + minimap.y_display - data->minimap.moove_mapY;
				}
			x++;
		}
		y++; 
	}
}

void	e_minimap(t_data *data, t_minimap minimap, t_map **map)
{
	minimap.y = 0;
	data->minimap.hit_bottom = 0;
	data->minimap.hit_top = 0;
	data->minimap.hit_left = 0;
	data->minimap.hit_right= 0;
	minimap.y_display = data->minimap.moove_mapY
		- ((minimap.posY * 32) - (minimap.size_of_bloc * 4));
	while (minimap.y < data->parsing.y_max)
	{
		minimap.x = 0;
		minimap.x_display = data->minimap.moove_mapX
				- ((minimap.posX * 32) - (minimap.size_of_bloc * 5));
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
	e_position(data, data->minimap.posX_display, data->minimap.posY_display);
}