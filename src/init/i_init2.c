/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_init2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:18:35 by pat               #+#    #+#             */
/*   Updated: 2023/02/03 17:03:36 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "init.h"

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

void	init_dhook(t_data *data)
{
	data->dhook.moove_spawn_x = 0;
	data->dhook.moove_spawn_y = 0;
}

void	init_collision(t_data *data)
{
	data->engine.collision.ym_pos = 0;
	data->engine.collision.xm_pos = 0;
	data->engine.collision.yo_add = 0;
	data->engine.collision.xo_add = 0;
	data->engine.collision.yo_sub = 0;
	data->engine.collision.xo_sub = 0;
	data->engine.collision.xo_right = 0;
	data->engine.collision.yo_right = 0;
	data->engine.collision.xo_left = 0;
	data->engine.collision.yo_left = 0;
	data->engine.collision.xo = 0;
	data->engine.collision.yo = 0;
}
