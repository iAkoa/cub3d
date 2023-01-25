/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_draw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:47:04 by pat               #+#    #+#             */
/*   Updated: 2023/01/25 15:51:02 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"
#include "draw.h"
#include "../engine/engine.h"

void	draw(t_data *data)
{
	d_my_pixel_clear(data);
	e_raycasting(data, &data->engine);
	e_minimap(data, data->minimap, data->map2d);
	mlx_put_image_to_window(data->window.mlx_ptr, data->window.win_ptr, data->window.img, 0, 0);
}