/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_vertical_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 03:22:25 by pat               #+#    #+#             */
/*   Updated: 2023/01/25 04:02:45 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"
#include "engine.h"
#include "../draw/draw.h"
#include "../init/init.h"


void	e_size_v_rayon(t_engine *engine, float rx, float ry, float ra)
{
	float	c;
	(void)ra;
	c = 0;
	c = sqrtf((powf(rx - engine->posx, 2) + powf(ry - engine->posy, 2)));
	engine->dist = c;
	engine->v_check = 1;
}

static void	e_vertical_mx_my_check(t_data *data, t_engine *engine)
{
	if (engine->ray_v.my < 0)
		engine->ray_v.my *= -1;
	if (engine->ray_v.mx < 0)
		engine->ray_v.mx *= -1;
	if (engine->ray_v.my >= data->draw.map_Ymax)
		engine->ray_v.my = data->draw.map_Ymax - 1;
}

static void	e_set_ray_v_case_1(t_engine *engine, float ntan)
{
	engine->ray_v.rx = (((int)engine->posx >> 5) * 32) - 0.0001;
	engine->ray_v.ry = (engine->posx - engine->ray_v.rx) * ntan + engine->posy;
	engine->ray_v.xo = -32;
	engine->ray_v.yo = (-engine->ray_v.xo * ntan);
	return ;
}

static void	e_set_ray_v_case_2(t_engine *engine, float ntan)
{
	engine->ray_v.rx = (((int)engine->posx >> 5) * 32) + 32;
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



void	e_vertical_line_check(t_data *data, t_engine *engine, float ra, float ntan)
{
	if ((ra > engine->p2) && (ra < engine->p3))
		e_set_ray_v_case_1(engine, ntan);
	if ((ra < engine->p2) || (ra > engine->p3))
		e_set_ray_v_case_2(engine, ntan);
	if (ra == 0 || ra == M_PI)
		e_set_ray_v_case_3(engine);
		(void)data;
	while (engine->ray_v.dof < engine->dof_limit)
	{
		engine->ray_v.mx = ((int)(engine->ray_v.rx) >> 5);
		engine->ray_v.my = ((int)(engine->ray_v.ry) >> 5);
		e_vertical_mx_my_check(data, &(data->engine));
		engine->ray_v.mp = engine->ray_v.my * data->draw.map_Xmax + engine->ray_v.mx;
		// dprintf(engine->fd, "data->map2d[engine->ray_h.my][0].x_max  = %i\n", data->draw.map_Xmax);
		if (engine->ray_h.mp > 0 && (engine->ray_v.mp < (data->draw.map_Xmax  * data->draw.map_Ymax)) && data->map[engine->ray_v.mp].z == WALL)
		{
			// printf("cub->data.width * cub->data.map_data.map_size = %i\n", data->draw.map_Xmax * data->draw.map_Ymax);
			engine->ray_v.dof = engine->dof_limit;
		}
		else
		{
			engine->ray_v.rx += engine->ray_v.xo;
			engine->ray_v.ry += engine->ray_v.yo;
			engine->ray_v.dof += 1;
		}
	}
}