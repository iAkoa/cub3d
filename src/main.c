	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:57:51 by pat               #+#    #+#             */
/*   Updated: 2022/12/13 17:11:37 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"
#include "init/init.h"
#include "draw/draw.h"
#include "dhook/dhook.h"
#include "parsing/parsing.h"
#include "engine/engine.h"

static int	ft_exit(void *param)
{
	(void)param;
	exit(0);
	return (0);
}


int	main(int ac, char **av)
{
	t_data	data;
	t_track *track;
	t_map	*map;

	track = NULL;
	map = NULL;
	init_data(&data ,track, map);
	init_window(&data);
	init_parsing(&data);
	init_draw(&data);
	data.ac = ac;
	data.av = av;
	if(!p_parsing(&data, av[1]))
		return (0);
	init_engine(&data);
	data.engine.pa = data.draw.player_angle;
	// printf("parsing ok !\n");
	data.engine.posx = (data.draw.posX * 32) + 16;
	data.engine.posy = (data.draw.posY * 32) + 16;
	data.engine.pa = data.draw.player_angle;
	// int	i;
	
	// i  = 0;
	// while (data.mapchar[i])
	// {
	// 	dprintf(2, "////////////%i/////////////\n", i);
	// 	dprintf(2, "x = %c\n", data.mapchar[i]);
	// 	i++;
	// }
	// printf("data->map = %s\n", data.mapchar);
	// int i = 0;
	// i = 0;
	// int j;
	// while (i < data.parsing.y_max)
	// {
	// 	j = 0;
	// 	while (!data.map2d[i][j].stop)
	// 	{
	// 		dprintf(2, ">>>>>>>>>>>>>>>%i\n", j * i + i);
	// 		dprintf(2, "y = %d et x = %d et z = %f \n",i , j, data.map2d[i][j].z);
	// 		j++;
	// 	}
	// 	i++;
	// }
	e_raycasting(&data, &data.engine);
	d_minimap(&data, data.draw, data.map2d);
	mlx_put_image_to_window(data.window.mlx_ptr, data.window.win_ptr, data.window.img, 0, 0);
	// printf("draw.x = %d\n",data.draw.x);
	// printf("draw.y = %d\n", data.draw.y);
	mlx_hook(data.window.win_ptr, 2, 1L << 0, ft_keyhook, &data);
	mlx_hook(data.window.win_ptr, 17, 0, ft_exit, &data);
	mlx_loop(data.window.mlx_ptr);
	return (0);
}