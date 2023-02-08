/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 08:34:44 by pat               #+#    #+#             */
/*   Updated: 2023/02/03 17:29:15 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "init.h"

void	init_data(t_data *data, t_track *track, t_map *map)
{
	int	i;

	i = -1;
	data->track = track;
	data->map = map;
	while (++i < 7)
		data->tab_keycode[i] = 0;
}

void	init_window(t_data *data)
{
	data->window.mlx_ptr = mlx_init();
	data->window.win_ptr = mlx_new_window(data->window.mlx_ptr,
			1920, 1080, "cub3d");
	data->window.img = mlx_new_image(data->window.mlx_ptr, 1920, 1080);
	data->window.addr = mlx_get_data_addr(data->window.img,
			&(data->window.bits_per_pixel), &(data->window.line_length),
			&(data->window.endian));
}

void	init_minimap_engine(t_data *data)
{
	data->minimap.y = 0;
	data->minimap.x = 0;
	data->minimap.posy = 0;
	data->minimap.posx = 0;
	data->minimap.dirx = -1;
	data->minimap.diry = 0;
	data->minimap.planex = 0;
	data->minimap.planey = 0.66;
	data->minimap.y_max_minimap = 40 * 8;
	data->minimap.x_max_minimap = 40 * 10;
	data->minimap.x_display = 0;
	data->minimap.y_display = 0;
	data->minimap.size_of_bloc = 32;
	data->minimap.moove_mapx = 0;
	data->minimap.moove_mapy = 0;
	data->minimap.hit_top = 0;
	data->minimap.hit_right = 0;
	data->minimap.hit_left = 0;
	data->minimap.hit_bottom = 0;
	data->minimap.size_check = 0;
}

void	init_engine(t_data *data)
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
	data->engine.player_angle = data->minimap.player_angle;
	data->engine.pdx = cos(data->engine.player_angle) * 5;
	data->engine.pdy = sin(data->engine.player_angle) * 5;
	data->engine.posx = (data->minimap.posx * 32) + 16;
	data->engine.posy = (data->minimap.posy * 32) + 16;
}

void	init_parsing(t_data *data)
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
	data->parsing.checker = 0;
}
