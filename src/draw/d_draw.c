/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_draw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:47:04 by pat               #+#    #+#             */
/*   Updated: 2023/01/30 19:47:45 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"
#include "draw.h"
#include "../engine/engine.h"

void	draw(t_data *data)
{
	data->engine.pa = data->draw.player_angle;
	e_raycasting(data, &data->engine);
	e_minimap(data, data->minimap, data->map2d);
	mlx_put_image_to_window(data->window.mlx_ptr,
		data->window.win_ptr, data->window.img, 0, 0);
}
