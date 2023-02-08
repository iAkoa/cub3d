/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_horizontal_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 03:22:25 by pat               #+#    #+#             */
/*   Updated: 2023/02/08 15:57:57 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "engine.h"
#include "../draw/draw.h"
#include "../init/init.h"

static void	e_horizontal_mx_my_check(t_data *data, t_engine *engine)
{
	if (engine->ray_h.my < 0)
		engine->ray_h.my *= -1;
	if (engine->ray_h.mx < 0)
		engine->ray_h.mx *= -1;
	if (engine->ray_h.my >= data->parsing.y_max)
		engine->ray_h.my = data->parsing.y_max - 1;
}

static void	e_set_ray_h_case_1(t_engine *engine, double atan)
{
	engine->ray_h.ry = (((int)engine->posy >> 5) << 5) - 0.0001;
	engine->ray_h.rx = (engine->posy - engine->ray_h.ry) * atan + engine->posx;
	engine->ray_h.yo = -32;
	engine->ray_h.xo = (-engine->ray_h.yo * atan);
	return ;
}

static void	e_set_ray_h_case_2(t_engine *engine, double atan)
{
	engine->ray_h.ry = (((int)engine->posy >> 5) << 5) + 32;
	engine->ray_h.rx = (engine->posy - engine->ray_h.ry) * atan + engine->posx;
	engine->ray_h.yo = 32;
	engine->ray_h.xo = (-engine->ray_h.yo * atan);
	return ;
}

static void	e_set_ray_h_case_3(t_engine *engine)
{
	engine->ray_h.rx = engine->posx;
	engine->ray_h.ry = engine->posy;
	engine->ray_h.dof = engine->dof_limit;
	return ;
}

void	e_horizontal_line_check(t_data *data, t_engine *engine,
			double ra, double atan)
{
	if (ra > M_PI)
		e_set_ray_h_case_1(engine, atan);
	if (ra < M_PI)
		e_set_ray_h_case_2(engine, atan);
	if (ra == 0 || ra == M_PI)
		e_set_ray_h_case_3(engine);
	while (engine->ray_h.dof < engine->dof_limit)
	{
		e_horizontal_mx_my_check(data, engine);
		engine->ray_h.mx = ((int)(engine->ray_h.rx) >> 5);
		engine->ray_h.my = ((int)(engine->ray_h.ry) >> 5);
		engine->ray_h.mp = engine->ray_h.my
			* data->parsing.x_max + engine->ray_h.mx;
		if (engine->ray_h.mp > 0 && (engine->ray_h.mp
				< (data->parsing.x_max * data->parsing.y_max) - 1)
			&& data->map[engine->ray_h.mp].z == WALL)
			engine->ray_h.dof = engine->dof_limit;
		else
		{
			engine->ray_h.rx += engine->ray_h.xo;
			engine->ray_h.ry += engine->ray_h.yo;
			engine->ray_h.dof += 1;
		}
	}
}
