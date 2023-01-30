/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dh_translation_minimap.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:32:07 by pat               #+#    #+#             */
/*   Updated: 2023/01/26 09:33:10 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"
#include "dhook.h"
#include "../draw/draw.h"

// void	dh_moove_forward(t_data *data, t_engine *engine)
// {

// 	if (engine->pdx < 0)
// 		engine->collision.xo = -10;
// 	else
// 		engine->collision.xo = 10;
// 	if (engine->pdy < 0)
// 		engine->collision.yo = -10;
// 	else
// 		engine->collision.yo = 10;
// 	engine->collision.ym_pos = engine->posy / 32.0;
// 	engine->collision.xm_pos = engine->posx / 32.0;
// 	engine->collision.xo_add = (engine->posx + engine->collision.xo) / 32.0;
// 	engine->collision.yo_add = (engine->posy + engine->collision.yo) / 32.0;
// 	if (e_check_collision(data->map2d, engine->collision.ym_pos,
// 			engine->collision.xo_add) == 0)
// 		engine->posx += engine->pdx;
// 	if (e_check_collision(data->map2d, engine->collision.yo_add,
// 			engine->collision.xm_pos) == 0)
// 		engine->posy += engine->pdy;
// }

// void	dh_moove_backward(t_data *data, t_engine *engine)
// {
// 	if (engine->pdx < 0)
// 		engine->collision.xo = -10;
// 	else
// 		engine->collision.xo = 10;
// 	if (engine->pdy < 0)
// 		engine->collision.yo = -10;
// 	else
// 		engine->collision.yo = 10;
// 	engine->collision.ym_pos = engine->posy / 32.0;
// 	engine->collision.xm_pos = engine->posx / 32.0;
// 	engine->collision.xo_sub = (engine->posx - engine->collision.xo) / 32.0;
// 	engine->collision.yo_sub = (engine->posy - engine->collision.yo) / 32.0;
// 	if (e_check_collision(data->map2d, engine->collision.ym_pos,
// 			engine->collision.xo_sub) == 0)
// 		engine->posx -= engine->pdx;
// 	if (e_check_collision(data->map2d, engine->collision.yo_sub,
// 			engine->collision.xm_pos) == 0)
// 		engine->posy -= engine->pdy;
// }

// void	dh_moove_right(t_data *data, t_engine *engine)
// {
// 	printf("engine->posx = %f\n", engine->posx);
// 	printf("engine->posy = %f\n", engine->posy);
// 	set_xo_and_yo_for_side_walk(engine);
// 	engine->collision.ym_pos = engine->posy / 32.0;
// 	engine->collision.xm_pos = engine->posx / 32.0;
// 	engine->collision.xo_right = (engine->posx + engine->collision.yo) / 32.0;
// 	engine->collision.yo_right = (engine->posy + engine->collision.xo) / 32.0;
// 	if (e_check_collision(data->map2d, engine->collision.ym_pos,
// 			engine->collision.xo_right) == 0)
// 		engine->posx += -engine->pdy;
// 	if (e_check_collision(data->map2d, engine->collision.yo_right,
// 			engine->collision.xm_pos) == 0)
// 		engine->posy += engine->pdx;
// 	printf("engine->posx = %f\n", engine->posx);
// 	printf("engine->posy = %f\n", engine->posy);
// }

// void	dh_moove_left(t_data *data, t_engine *engine)
// {
// 	set_xo_and_yo_for_side_walk(engine);
// 	engine->collision.ym_pos = engine->posy / 32.0;
// 	engine->collision.xm_pos = engine->posx / 32.0;
// 	engine->collision.xo_left = (engine->posx - engine->collision.yo) / 32.0;
// 	engine->collision.yo_left = (engine->posy - engine->collision.xo) / 32.0;
// 	if (e_check_collision(data->map2d, engine->collision.ym_pos,
// 			engine->collision.xo_left) == 0)
// 	{
// 		data->minimap.moove_mapX += engine->pdy;
// 		engine->posx += engine->pdy;
		
// 	}
// 	if (e_check_collision(data->map2d, engine->collision.yo_left,
// 			engine->collision.xm_pos) == 0)
// 		engine->posy += -engine->pdx;
// }