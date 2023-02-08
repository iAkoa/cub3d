/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dh_keyloop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:16:13 by pat               #+#    #+#             */
/*   Updated: 2023/02/03 18:10:59 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "dhook.h"
#include "../draw/draw.h"

int	dh_keyloop(t_data *data)
{
	if (data->tab_keycode[4] == 1)
	{
		mlx_destroy_image(data->window.mlx_ptr, data->window.img);
		mlx_destroy_window(data->window.mlx_ptr, data->window.win_ptr);
		gc_free_all(&data->track);
		exit(0);
	}
	dh_translation(data);
	dh_rotation(data);
	draw(data);
	return (0);
}
