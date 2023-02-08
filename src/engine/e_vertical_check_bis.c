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

void	e_size_v_rayon(t_engine *engine, double rx, double ry, double ra)
{
	double	c;

	(void)ra;
	c = 0;
	c = sqrtf((powf(rx - engine->posx, 2) + powf(ry - engine->posy, 2)));
	engine->dist = c;
	engine->v_check = 1;
}
