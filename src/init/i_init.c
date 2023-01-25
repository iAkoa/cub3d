/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 08:34:44 by pat               #+#    #+#             */
/*   Updated: 2023/01/25 08:32:20 by pat              ###   ########lyon.fr   */
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
	data->window.win_ptr = mlx_new_window(data->window.mlx_ptr, 1920,  1080, "cube3d");
	data->window.img = mlx_new_image(data->window.mlx_ptr, 1920, 1080);
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
	data->draw.y_max_minimap = 40 * 8;
	data->draw.x_max_minimap = 40 * 10;
	data->draw.x_display = 0;
	data->draw.y_display = 0;
	data->draw.size_of_bloc =  40;
	data->draw.moove_mapX = 0;
	data->draw.moove_mapY = 0;
	data->draw.hit_top = 0;
	data->draw.hit_right = 0;
	data->draw.hit_left = 0;
	data->draw.hit_bottom = 0;
	data->draw.size_check = 0;
	
}

void init_engine(t_data *data)
{
	if (data->parsing.x_max > data->parsing.y_max)
		data->engine.dof_limit = data->parsing.x_max;
	else
		data->engine.dof_limit = data->parsing.y_max;
	data->engine.posx = 0;
	data->engine.posy = 0;
	data->engine.hit_wall = 0;
	data->engine.p2 = M_PI / 2;
	data->engine.p3 = 3 * M_PI / 2;
	data->engine.pdx = cos(data->engine.pa * 5);
	data->engine.pdy = sin(data->engine.pa * 5) - (M_PI / 6);
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

void	init_ray_var(t_data *data)
{
	
	data->engine.ray_v.mx = 0;
	data->engine.ray_v.my = 0;
	data->engine.ray_v.mp = 0;
	data->engine.ray_v.rx = 0;
	data->engine.ray_v.ry = 0;
	data->engine.ray_v.xo = 0;
	data->engine.ray_v.yo = 0;
	data->engine.ray_v.dof = 0;
	data->engine.ray_h.mx = 0;
	data->engine.ray_h.my = 0;
	data->engine.ray_h.mp = 0;
	data->engine.ray_h.rx = 0;
	data->engine.ray_h.ry = 0;
	data->engine.ray_h.xo = 0;
	data->engine.ray_h.yo = 0;
	data->engine.ray_h.dof = 0;
	data->engine.atan = 0;
	data->engine.ntan = 0;
}

void init_dhook(t_data *data)
{
	data->dhook.moove_spawn_x = 0;
	data->dhook.moove_spawn_y = 0;
}