/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_engine.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:16:52 by pat               #+#    #+#             */
/*   Updated: 2023/02/08 15:50:28 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "engine.h"
#include "../draw/draw.h"
#include "../init/init.h"

void	e_draw_walls(t_data *data, t_engine *engine, double ra, double j)
{
	double	ca;

	ca = engine->player_angle - ra;
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

void	e_raycasting(t_data *data, t_engine *engine)
{
	int		r;

	r = -1;
	engine->ra = 0.0;
	engine->ra = e_set_ra_before_loop(engine->ra, engine->player_angle);
	while (r++ < 1919)
	{
		engine->v_check = 0;
		init_ray_var(data);
		engine->atan = -1 / tanf(engine->ra);
		engine->ntan = -tanf(engine->ra);
		e_horizontal_line_check(data, engine, engine->ra, engine->atan);
		e_vertical_line_check(data, engine, engine->ra, engine->ntan);
		if (e_check_ray(engine) == 0)
			e_size_h_rayon(engine, engine->ray_h.rx, engine->ray_h.ry,
				engine->ra);
		else
			e_size_v_rayon(engine, engine->ray_v.rx, engine->ray_v.ry,
				engine->ra);
		e_draw_walls(data, engine, engine->ra, r);
		engine->ra = e_set_ra_end_of_loop(engine->ra);
	}
}
