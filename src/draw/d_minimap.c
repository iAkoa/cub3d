/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_minimap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 03:27:34 by pat               #+#    #+#             */
/*   Updated: 2023/01/23 13:23:44 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"
#include "draw.h"

void	ft_my_pixel_clear(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < 1300)
	{
		y = 0;
		while (y < 900)
		{
			ft_my_mlx_pixel_put(data, x, y, 0);
			y++;
		}
		x++;
	}
}


void drawLine(t_data *data, int x1, int y1, int x2, int y2) 
{
	int dx, dy, sx, sy, err, e2;
	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	sx = x1 < x2 ? 1 : -1;
	sy = y1 < y2 ? 1 : -1;
	err = dx > dy ? dx : -dy;
	err /= 2;
	while (1) 
	{
		if(!ft_my_mlx_pixel_put_view(data, x1, y1,  PLAYER_COLOR))
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
	}
}

// void drawview(t_data *data, int x1, int y1, int x2, int y2) 
// {
	
// }


static void d_position(t_data *data, int posX, int posY)
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
			ft_my_mlx_pixel_put_player(data, posX_display, posY_display,  PLAYER_COLOR);
			posY_display++;
		}
		posX_display++;
	}
	// while (x > draw.size_of_bloc * 0.35 && x <= draw.size_of_bloc / 1.65 && y > draw.size_of_bloc * 0.35 && y <= draw.size_of_bloc / 1.65)
}

static void d_bloc_minimap(t_data *data, t_draw draw, t_map **map)
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
	while (y < draw.size_of_bloc && draw.y_display < draw.y_max_minimap)
	{
		x = 0;
		// 	printf("draw.size_of_bloc = %i\n", draw.size_of_bloc);
		y_display = y + draw.y_display;
		while (x < draw.size_of_bloc && draw.x_display < draw.x_max_minimap)
		{
			x_display = x + draw.x_display;
			if (((x == 0 || y ==  0 || x == 1 || y == 1|| x == draw.size_of_bloc - 1 || y == draw.size_of_bloc - 1 || x == draw.size_of_bloc || y == draw.size_of_bloc))&& map[draw.y][draw.x].z == WALL)
				ft_my_mlx_pixel_put_minimap(data, x + draw.x_display, y + draw.y_display, GRID_WALL_COLOR);
			else if ((x == 0 || y ==  0 || x == 1 || y == 1|| x == draw.size_of_bloc - 1 || y == draw.size_of_bloc - 1 || x == draw.size_of_bloc || y == draw.size_of_bloc))
				ft_my_mlx_pixel_put_minimap(data, x + draw.x_display, y + draw.y_display, GRID_COLOR);
			else if (map[draw.y][draw.x].z == WALL)
				ft_my_mlx_pixel_put_minimap(data, x + draw.x_display, y + draw.y_display, WALL_COLOR);
			else if (map[draw.y][draw.x].z != WALL && map[draw.y][draw.x].z != EMPTY)
				ft_my_mlx_pixel_put_minimap(data,x + draw.x_display, y + draw.y_display, FLOOR_COLOR);
			if (map[draw.y][draw.x].z != WALL && map[draw.y][draw.x].z != EMPTY && map[draw.y][draw.x].z != FLOOR)
				if (x == draw.size_of_bloc / 2 && y == draw.size_of_bloc / 2)
				{
					
					data->draw.posX_display = data->dhook.moove_spawn_x + x + draw.x_display - data->draw.moove_mapX;
					data->draw.posY_display = data->dhook.moove_spawn_y + y + draw.y_display - data->draw.moove_mapY;
				}
			x++;
		}
		y++; 
	}
}
void	d_minimap(t_data *data, t_draw draw, t_map **map)
{
	draw.y = 0;
	data->draw.hit_bottom = 0;
	data->draw.hit_top = 0;
	data->draw.hit_left = 0;
	data->draw.hit_right= 0;

	// printf("player pos X =  %i\n", data->draw.posX_display);
	// printf("player pos Y =  %i\n", data->draw.posY_display);
	
	draw.y_display = data->draw.moove_mapY;
	while (draw.y < data->parsing.y_max)
	{
		draw.x = 0;
		draw.x_display = data->draw.moove_mapX;
		while (draw.x < map[draw.y][draw.x].x_max)
		{
			d_bloc_minimap(data, draw, map);
			draw.x_display += draw.size_of_bloc;
			draw.x++;
		}
		draw.y_display += draw.size_of_bloc;
		draw.y++;
		data->draw.size_check = 0;
	}
	d_position(data, data->draw.posX_display, data->draw.posY_display);
	drawLine(data, data->draw.posX_display, data->draw.posY_display,
		data->draw.posX_display + 900 * (cos(draw.player_angle)), data->draw.posY_display + 1300 * (sin(draw.player_angle)));
	// d_view(data, data->draw.posX_display, data->draw.posY_display , 20);
}
