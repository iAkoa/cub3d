/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_raycasting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pata->draw.player_anglet <pata->draw.player_anglet@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:40:52 by pat               #+#    #+#             */
/*   Updated: 2023/01/19 17:49:19 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"
#include "engine.h"
#include "../draw/draw.h"
#include "../init/init.h"


void	e_draw_walls(t_data *data, t_engine *engine, float ra, float j)
{
	float	ca;
	ca = engine->pa - ra;
	if (ca < 0)
		ca += 2 * M_PI;
	if (ca > 2 * M_PI)
		ca -= 2 * M_PI;
	engine->dist = engine->dist * cos(ca);
	engine->lineh = ((25 * 1920) / engine->dist);
	engine->lineo = (960 - engine->lineh / 2);
	d_3d(data, engine, j);
	return ;
}


void	e_raycasting(t_data * data, t_engine *engine)
{
	int		r;
	float	j;

	r = 0;
	j = 0;
	engine->ra = 0.0;
	engine->ra = e_set_ra_before_loop(engine->ra, engine->pa);
	data->engine.test = 0x00FFFFFF;
	while (r < 1920)
	{
		// printf("test\n");
		engine->v_check = 0;
		init_ray_var(data);
		engine->atan = -1 / tanf(engine->ra);
		engine->ntan = -tanf(engine->ra);
		e_horizontal_line_check(data, engine, engine->ra, engine->atan);
		e_vertical_line_check(data, engine, engine->ra, engine->ntan);
		if (e_check_ray(engine) == 0)
			e_size_h_rayon(engine, engine->ray_h.rx, engine->ray_h.ry, engine->ra);
		else
			e_size_v_rayon(engine, engine->ray_v.rx, engine->ray_v.ry, engine->ra);
		e_draw_walls(data, engine, engine->ra, j);
		j += 1;
		engine->ra = e_set_ra_end_of_loop(engine->ra);
		r++;
	}
}