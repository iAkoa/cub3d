/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_minimap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 03:27:34 by pat               #+#    #+#             */
/*   Updated: 2023/01/11 08:01:58 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"
#include "draw.h"

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
		if(!ft_my_mlx_pixel_put_tuning(data, x1, y1, 0x0000FF))
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



static void d_position(t_data *data, t_draw draw, int x, int y)
{
	int x_display;
	int y_display;
	
	x_display = 0;
	y_display = 0;

	if (x > draw.size_of_bloc * 0.35 && x <= draw.size_of_bloc / 1.65 && y > draw.size_of_bloc * 0.35 && y <= draw.size_of_bloc / 1.65)
	{
		x_display = data->dhook.moove_spawn_x + x + draw.x_screen;
		y_display = data->dhook.moove_spawn_y + y + draw.y_screen;
		printf("draw.x_screen = %i\n", draw.x_screen);
		ft_my_mlx_pixel_put(data, x_display, y_display, 0x0000FF00);
		if (x == draw.size_of_bloc / 2 && y == draw.size_of_bloc / 2)
		{
			data->draw.x_spawn_display = data->dhook.moove_spawn_x  + x + draw.x_screen;
			data->draw.y_spawn_display = data->dhook.moove_spawn_y  + y + draw.y_screen;
		}
	}
}

static void d_bloc_minimap(t_data *data, t_draw draw, t_map **map)
{
	int x;
	int	y;

	y = 0;
	while (y < draw.size_of_bloc && draw.y_screen < draw.y_max_minimap)
	{
		x = 0;
		printf("draw.x_screen = %i\n", draw.x_screen);
			printf("draw.y_screen = %i\n", draw.y_screen);
		// 	printf("draw.size_of_bloc = %i\n", draw.size_of_bloc);
		while (x < draw.size_of_bloc && draw.x_screen < draw.x_max_minimap)
		{
			if (x == 0 || y == 0)
				ft_my_mlx_pixel_put(data, x + draw.x_screen, y + draw.y_screen, 0x00000000);
			else if (map[draw.y][draw.x].z == WALL)
				ft_my_mlx_pixel_put(data, x + draw.x_screen, y + draw.y_screen, 0x00F000FF);
			else if (map[draw.y][draw.x].z != WALL && map[draw.y][draw.x].z != EMPTY)
				ft_my_mlx_pixel_put(data,x + draw.x_screen, y + draw.y_screen, 0x00FFFFFF);
			if (map[draw.y][draw.x].z != WALL && map[draw.y][draw.x].z != EMPTY && map[draw.y][draw.x].z != FLOOR)
				d_position(data, draw, x, y);
			x++;
		}
		y++;
	}
}
void	d_minimap(t_data *data, t_draw draw, t_map **map)
{
	draw.y = 0;
	while (draw.y < data->parsing.y_max)
	{
		draw.x = 0;
		draw.x_screen = 0;
		while (draw.x < map[draw.y][draw.x].x_max)
		{
			d_bloc_minimap(data, draw, map);
			draw.x_screen += draw.size_of_bloc;
			draw.x++;
		}
		draw.y_screen += draw.size_of_bloc;
		draw.y++;
	}
	drawLine(data, data->draw.x_spawn_display, data->draw.y_spawn_display,
		data->draw.x_spawn_display + 900 * (cos(draw.teta)), data->draw.y_spawn_display + 1300 * (sin(draw.teta)));
	// d_view(data, data->draw.x_spawn_display, data->draw.y_spawn_display , 20);
}
