/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dh_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:49:30 by pat               #+#    #+#             */
/*   Updated: 2023/01/25 15:35:06 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"
#include "dhook.h"
#include "../draw/draw.h"

void dh_rotation_left(t_data *data, t_engine *engine)
{
		(void)data;
		engine->pa -= 0.05;
		if (engine->pa < 0)
			engine->pa += 2 * M_PI;
		engine->pdx = cos(engine->pa) * 5;
		engine->pdy = sin(engine->pa) * 5;
}

void dh_rotation_right(t_data *data, t_engine *engine)
{
		(void)data;
		engine->pa += 0.05;
		if (engine->pa > 2 * M_PI)
			engine->pa -= 2 * M_PI;
		engine->pdx = cos(engine->pa) * 5;
		engine->pdy = sin(engine->pa) * 5;
}

void dh_rotation_minimap_left(t_data *data, t_engine *engine)
{
		(void)data;
		engine->pa -= 0.05;
		if (engine->pa < 0)
			engine->pa += 2 * M_PI;
		engine->pdx = cos(engine->pa) * 5;
		engine->pdy = sin(engine->pa) * 5;
}

void dh_rotation_minimap_right(t_data *data, t_engine *engine)
{
		(void)data;
		engine->pa += 0.05;
		if (engine->pa > 2 * M_PI)
			engine->pa -= 2 * M_PI;
		engine->pdx = cos(engine->pa) * 5;
		engine->pdy = sin(engine->pa) * 5;
}