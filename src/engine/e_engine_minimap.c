/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_engine_minimap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:13:19 by pat               #+#    #+#             */
/*   Updated: 2023/01/30 13:51:12 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"
#include "engine.h"
#include "../draw/draw.h"
#include "../init/init.h"


void e_bresenham(t_data *data, int x1, int y1, int x2, int y2)
{
	int dx, dy, sx, sy, err, e2;
	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	sx = x1 < x2 ? 1 : -1;
	sy = y1 < y2 ? 1 : -1;
	err = dx > dy ? dx : -dy;
	err /= 2;
	int i;
	
	i = 0;
	while (1) 
	{
		if(!d_my_mlx_pixel_put_view(data, x1, y1,  PLAYER_COLOR))
			break;
		if (x1 == x2 && y1 == y2)
			break;
		e2 = err;
		if (e2 > -dx) {
			err -= dy;
			x1 += sx;
		}
		if (e2 < dy) {
			err += dx;
			y1 += sy;
		}
		i++;
	}
}

static void e_position(t_data *data, int posX, int posY)
{
	int posX_display;
	int posY_display;

	posX_display = posX - 5;
	posY_display = posY - 5;
	while (posX_display < posX + 5)
	{
		posY_display = posY - 5;
		while (posY_display < posY + 5)
		{
			d_my_mlx_pixel_put_player(data, posX_display, posY_display,  PLAYER_COLOR);
			posY_display++;
		}
		posX_display++;
	}
	// while (x > draw.size_of_bloc * 0.35 && x <= draw.size_of_bloc / 1.65 && y > draw.size_of_bloc * 0.35 && y <= draw.size_of_bloc / 1.65)
}

static void e_bloc_minimap(t_data *data, t_minimap minimap, t_map **map)
{
	int x;
	int	y;
	int x_display;
	int y_display;
	
	
	y = 0;
	(void)x_display;
	(void)y_display;
	// printf("draw.x = %d\n", draw.x);
	// printf("draw.y = %d\n", draw.y);
	// printf("draw.sizeofbloc = %d\n", draw.size_of_bloc);
	// printf("minimap = %i\n", minimap.x_display);
	while (y < minimap.size_of_bloc && minimap.y_display < minimap.y_max_minimap)
	{
		x = 0;
		// 	printf("minimap.size_of_bloc = %i\n", minimap.size_of_bloc);
		y_display = y + minimap.y_display;
		while (x < minimap.size_of_bloc && minimap.x_display < minimap.x_max_minimap)
		{
			x_display = x + minimap.x_display;
			if (((x == 0 || y ==  0 || x == 1 || y == 1|| x == minimap.size_of_bloc - 1 || y == minimap.size_of_bloc - 1 || x == minimap.size_of_bloc || y == minimap.size_of_bloc))&& map[minimap.y][minimap.x].z == WALL)
				d_my_mlx_pixel_put_minimap(data, x + minimap.x_display, y + minimap.y_display, GRID_WALL_COLOR);
			else if ((x == 0 || y ==  0 || x == 1 || y == 1|| x == minimap.size_of_bloc - 1 || y == minimap.size_of_bloc - 1 || x == minimap.size_of_bloc || y == minimap.size_of_bloc) && map[minimap.y][minimap.x].z != EMPTY)
				d_my_mlx_pixel_put_minimap(data, x + minimap.x_display, y + minimap.y_display, GRID_COLOR);
			else if (map[minimap.y][minimap.x].z == WALL)
				d_my_mlx_pixel_put_minimap(data, x + minimap.x_display, y + minimap.y_display, WALL_COLOR);
			else if (map[minimap.y][minimap.x].z != WALL && map[minimap.y][minimap.x].z != EMPTY)
				d_my_mlx_pixel_put_minimap(data,x + minimap.x_display, y + minimap.y_display, FLOOR_COLOR);
			if (map[minimap.y][minimap.x].z != WALL && map[minimap.y][minimap.x].z != EMPTY && map[minimap.y][minimap.x].z != FLOOR)
				if (x == minimap.size_of_bloc / 2 && y == minimap.size_of_bloc / 2)
				{
					
					data->minimap.posX_display = data->dhook.moove_spawn_x + x + minimap.x_display - data->minimap.moove_mapX;
					data->minimap.posY_display = data->dhook.moove_spawn_y + y + minimap.y_display - data->minimap.moove_mapY;
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

	// printf("player pos X =  %i\n", data->minimap.posX_display);
	// printf("player pos Y =  %i\n", data->minimap.posY_display);
	minimap.y_display = data->minimap.moove_mapY - ((minimap.posY * 32) - (minimap.size_of_bloc * 4));
	while (minimap.y < data->parsing.y_max)
	{
		minimap.x = 0;
		minimap.x_display = data->minimap.moove_mapX - ((minimap.posX * 32) - (minimap.size_of_bloc * 5));
		// printf("map[minimap.y][minimap.x].x_max = %f\n", map[minimap.y][minimap.x].x_max);
		while (minimap.x < data->parsing.x_max)
		{
			e_bloc_minimap(data, minimap, map);
			// printf("minimap.x = %i et minimap.y = %i\n", minimap.x, minimap.y);
			minimap.x_display += minimap.size_of_bloc;
			minimap.x++;
		}
		minimap.y_display += minimap.size_of_bloc;
		minimap.y++;
		data->minimap.size_check = 0;
	}
	e_position(data, data->minimap.posX_display, data->minimap.posY_display);
	e_bresenham(data, data->minimap.posX_display, data->minimap.posY_display,
		data->minimap.posX_display + 30 * (cos(minimap.player_angle)), data->minimap.posY_display + 30 * (sin(minimap.player_angle)));
	// d_view(data, data->draw.posX_display, data->draw.posY_display , 20);
}