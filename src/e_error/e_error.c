/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 05:46:17 by pat               #+#    #+#             */
/*   Updated: 2023/02/03 17:03:36 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void free_mlx(t_data *data)
{
	if (data->window.mlx_ptr)
	{
		if(data->engine.img_e.data)
			mlx_destroy_image(data->window.mlx_ptr, data->engine.img_e.data);
		if(data->engine.img_n.data)
			mlx_destroy_image(data->window.mlx_ptr, data->engine.img_n.data);
		if(data->engine.img_w.data)
			mlx_destroy_image(data->window.mlx_ptr, data->engine.img_w.data);
		if(data->engine.img_s.data)
			mlx_destroy_image(data->window.mlx_ptr, data->engine.img_s.data);
		if(data->window.img)
			mlx_destroy_image(data->window.mlx_ptr, data->window.img);
		if (data->window.win_ptr)
			mlx_destroy_window(data->window.mlx_ptr, data->window.win_ptr);
		mlx_destroy_display(data->window.mlx_ptr);
		free(data->window.mlx_ptr);
	}
}
void	e_error(t_data *data, char *str)
{
	//printf("%s\n", str);
	free_mlx(data);
	gc_free_all(&data->track);
	exit(0);
}
