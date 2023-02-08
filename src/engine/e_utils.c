/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 03:40:05 by pat               #+#    #+#             */
/*   Updated: 2023/02/08 15:42:33 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "engine.h"
#include "../draw/draw.h"
#include "../init/init.h"

double	e_set_ra_before_loop(double ra, double pa)
{
	ra = pa - (M_PI / 6);
	if (ra < 0)
		ra += 2 * M_PI;
	if (ra > 2 * M_PI)
		ra -= 2 * M_PI;
	return (ra);
}

double	e_set_ra_end_of_loop(double ra)
{
	ra = ra + ((2 * M_PI / 6) / 1920);
	if (ra <= 0)
		ra += 2 * M_PI;
	if (ra >= 2 * M_PI)
		ra -= 2 * M_PI;
	return (ra);
}

unsigned int	e_get_value(t_engine *engine, t_img *img, int y, int x)
{
	int	texx;
	int	texy;

	(void)y;
	texx = 0;
	if (engine->v_check == 1)
		texx = ((engine->ray_v.ry / 32) - engine->ray_v.my) * 32;
	else
		texx = ((engine->ray_h.rx / 32) - engine->ray_h.mx) * 32;
	texy = ((x - (540 - engine->lineh / 2)) / engine->lineh) * img->height;
	img->addr = (int *)mlx_get_data_addr(img->data, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (texx < 0)
		texx = 0;
	if (texy < 0)
		texy = 0;
	return (((unsigned int *)img->addr)[texy * img->line_length / 4 + texx]);
}

int	e_check_ray(t_engine *engine)
{
	if (sqrtf((powf(engine->ray_h.rx - engine->posx, 2)
				+ powf(engine->ray_h.ry - engine->posy, 2)))
		>= sqrtf((powf(engine->ray_v.rx - engine->posx, 2)
				+ powf(engine->ray_v.ry - engine->posy, 2))))
		return (1);
	else
		return (0);
	return (0);
}
