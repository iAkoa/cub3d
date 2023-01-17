/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 08:34:44 by pat               #+#    #+#             */
/*   Updated: 2023/01/17 17:51:18 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/cube3d.h"
#include "init.h"

void init_data(t_data *data, t_track *track, t_map *map)
{

	data->track = track;
	data->map = map;
}

void init_window(t_data *data)
{
	data->window.mlx_ptr = mlx_init();
	data->window.win_ptr = mlx_new_window(data->window.mlx_ptr, 1300,  900, "cube3d");
	data->window.img = mlx_new_image(data->window.mlx_ptr, 1300, 900);
	data->window.addr = mlx_get_data_addr(data->window.img, &data->window.bits_per_pixel,
			&data->window.line_length, &data->window.endian);
}

void init_draw(t_data *data)
{
	data->draw.y = 0;
	data->draw.x = 0;
	data->draw.posY = 0;
	data->draw.posX = 0;
	data->draw.dirX = -1;
	data->draw.dirY = 0;
	data->draw.planeX = 0;
	data->draw.planeY = 0.66;
	data->draw.y_max_minimap = 0.3 * 900;
	data->draw.x_max_minimap = 0.3 * 1200;
	data->draw.x_display = 0;
	data->draw.y_display = 0;
	data->draw.size_of_bloc =  0.1 * data->draw.y_max_minimap;
	data->draw.moove_mapX = 0;
	data->draw.moove_mapY = 0;
	data->draw.hit_top = 0;
	data->draw.hit_right = 0;
	data->draw.hit_left = 0;
	data->draw.hit_bottom = 0;
	
}

void init_parsing(t_data *data)
{
	data->parsing.size_mal = 0;
	data->parsing.y_max = 0;
	data->parsing.x_max = 0;
	data->parsing.count = 0;
	data->parsing.floor_blue = -1;
	data->parsing.floor_green = -1;
	data->parsing.floor_red = -1;
	data->parsing.sky_blue = -1;
	data->parsing.sky_green = -1;
	data->parsing.sky_red = -1;
	data->parsing.count = 0;
}

void init_dhook(t_data *data)
{
	data->dhook.moove_spawn_x = 0;
	data->dhook.moove_spawn_y = 0;
}