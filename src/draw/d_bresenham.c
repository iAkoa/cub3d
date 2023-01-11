/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_bresenham.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:49:50 by pat               #+#    #+#             */
/*   Updated: 2023/01/10 12:56:38 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/cube3d.h"
#include "draw.h"

void drawLine(t_data * data, int x1, int y1, int x2, int y2) {
	int dx, dy, sx, sy, err, e2;
	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	sx = x1 < x2 ? 1 : -1;
	sy = y1 < y2 ? 1 : -1;
	err = dx > dy ? dx : -dy;
	err /= 2;
	while (1) {
		ft_my_mlx_pixel_put(data, x1, y1, 0xFFFFFF);
		if (x1 == x2 && y1 == y2)
			break;
		e2 = err;
		if (e2 > -dx) {
			err -= dy;
			x1 += sx;
		}
		if (e2 < dy) {
			err += dx;
			y1 += sy;
		}
	}
}