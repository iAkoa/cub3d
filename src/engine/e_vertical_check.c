/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_vertical_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 03:22:25 by pat               #+#    #+#             */
/*   Updated: 2023/02/08 15:58:36 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "engine.h"
#include "../draw/draw.h"
#include "../init/init.h"

static void	e_vertical_mx_my_check(t_data *data, t_engine *engine)
{
	if (engine->ray_v.my < 0)
		engine->ray_v.my *= -1;
	if (engine->ray_v.mx < 0)
		engine->ray_v.mx *= -1;
	if (engine->ray_v.my >= data->parsing.y_max)
		engine->ray_v.my = data->parsing.y_max - 1;
}

static void	e_set_ray_v_case_1(t_engine *engine, double ntan)
{
	engine->ray_v.rx = (((int)((engine->posx)) >> 5) << 5) - 0.001;
	engine->ray_v.ry = (engine->posx - engine->ray_v.rx) * ntan + engine->posy;
	engine->ray_v.xo = -32;
	engine->ray_v.yo = (-engine->ray_v.xo * ntan);
	return ;
}

static void	e_set_ray_v_case_2(t_engine *engine, double ntan)
{
	engine->ray_v.rx = ((((int)(engine->posx)) >> 5) << 5) + 32;
	engine->ray_v.ry = (engine->posx - engine->ray_v.rx) * ntan + engine->posy;
	engine->ray_v.xo = 32;
	engine->ray_v.yo = (-engine->ray_v.xo * ntan);
	return ;
}

static void	e_set_ray_v_case_3(t_engine *engine)
{
	engine->ray_v.rx = engine->posx;
	engine->ray_v.ry = engine->posy;
	engine->ray_v.dof = engine->dof_limit;
	return ;
}

void	e_vertical_line_check(t_data *data, t_engine *engine,
		double ra, double ntan)
{
	if ((ra > engine->p2) && (ra < engine->p3))
		e_set_ray_v_case_1(engine, ntan);
	if ((ra < engine->p2) || (ra > engine->p3))
		e_set_ray_v_case_2(engine, ntan);
	if (ra == 0 || ra == M_PI)
		e_set_ray_v_case_3(engine);
	while (engine->ray_v.dof < engine->dof_limit)
	{
		engine->ray_v.mx = ((int)(engine->ray_v.rx) >> 5);
		engine->ray_v.my = ((int)(engine->ray_v.ry) >> 5);
		e_vertical_mx_my_check(data, &(data->engine));
		engine->ray_v.mp = engine->ray_v.my * data->parsing.x_max
			+ engine->ray_v.mx;
		if (engine->ray_v.mp > 0 && (engine->ray_v.mp
				< (data->parsing.x_max * data->parsing.y_max) - 1)
			&& data->map[engine->ray_v.mp].z == WALL)
			engine->ray_v.dof = engine->dof_limit;
		else
		{
			engine->ray_v.rx += engine->ray_v.xo;
			engine->ray_v.ry += engine->ray_v.yo;
			engine->ray_v.dof += 1;
		}
	}
}
