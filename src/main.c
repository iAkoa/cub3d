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
	init_window(&data);
	init_parsing(&data);
	init_data(&data ,track, map);
	init_draw(&data);
	data.ac = ac;
	data.av = av;
	if(!p_parsing(&data, av[1]))
		return (0);
	printf("parsing ok !\n");
	d_minimap(&data, data.draw, data.map2d);
	// int	i;
	
	// i  = 0;
	// while (!data.map[i].stop)
	// {
	// 	dprintf(2, "////////////%i/////////////\n", i);
	// 	dprintf(2, "x = %f\n", data.map[i].x);
	// 	dprintf(2, "y = %f\n", data.map[i].y);
	// 	dprintf(2, "z = %f\n", data.map[i].z);
	// 	dprintf(2, "x_max = %f\n", data.map[i].x_max);
	// 	dprintf(2, "stop = %d\n", data.map[i].stop);
	// 	i++;
	// }
	// int i = 0;
	// i = 0;
	// int j;
	// while (i < data.parsing.y_max)
	// {
	// 	j = 0;
	// 	while (!data.map2d[i][j].stop)
	// 	{
	// 		dprintf(2, "////////////%i/////////////\n", j);
	// 		dprintf(2, "x = %f\n", data.map2d[i][j].x);
	// 		dprintf(2, "z = %f\n", data.map2d[i][j].z);
	// 		j++;
	// 	}
	// 	i++;
	// }
	mlx_put_image_to_window(data.window.mlx_ptr, data.window.win_ptr, data.window.img, 0, 0);
	mlx_hook(data.window.win_ptr, 2, 1L << 0, ft_keyhook, &data);
	mlx_hook(data.window.win_ptr, 17, 0, ft_exit, &data);
	mlx_loop(data.window.mlx_ptr);
	return (0);
}