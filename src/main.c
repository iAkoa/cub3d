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

void	e_set_texture_struct(t_data *data)
{
	// printf("data->parsing.north_path = %s\n", data->parsing.north_path);
	data->engine.img_n.data = mlx_xpm_file_to_image(data->window.mlx_ptr,
			data->parsing.north_path, &(data->engine.img_n.width), &(data->engine.img_n.height));
	data->engine.img_s.data = mlx_xpm_file_to_image(data->window.mlx_ptr,
			data->parsing.south_path, &(data->engine.img_s.width), &(data->engine.img_s.height));
	data->engine.img_w.data = mlx_xpm_file_to_image(data->window.mlx_ptr,
			data->parsing.west_path, &(data->engine.img_w.width), &(data->engine.img_w.height));
	data->engine.img_e.data = mlx_xpm_file_to_image(data->window.mlx_ptr,
			data->parsing.east_path, &(data->engine.img_e.width), &(data->engine.img_e.height));
	// printf("data->engine.img_n.data %p\n", data->engine.img_n.data);
}

static int	ft_exit(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int	check_name(char *av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	if (!av[i - 5] || av[i - 4] != '.' || av[i - 3] != 'c' || av[i - 2] != 'u'
		|| av[i - 1] != 'b')
	{
		ft_putendl_fd("Wrong map name", 2);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_track *track;
	t_map	*map;

	track = NULL;
	map = NULL;
	if (ac != 2 || check_name(av[1]) != 1)
		return (0);
	init_data(&data ,track, map);
	init_window(&data);
	init_parsing(&data);
	init_minimap_engine(&data);
	data.ac = ac;
	data.av = av;
	if(!p_parsing(&data, av[1]))
		return (0);
	init_engine(&data);
	p_set_texture_struct(&data.engine, &data);
	// printf("parsing ok !\n");
	data.engine.posx = (data.minimap.posX * 32) + 16;
	data.engine.posy = (data.minimap.posY * 32) + 16;
	data.engine.player_angle = data.minimap.player_angle;
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
	draw(&data);
	// printf("draw.x = %d\n",data.draw.x);
	// printf("draw.y = %d\n", data.draw.y);
	mlx_hook(data.window.win_ptr, 2, 1L << 0, dh_keyhook, &data);
	mlx_hook(data.window.win_ptr, 17, 0, ft_exit, &data);
	mlx_loop(data.window.mlx_ptr);
	return (0);
}
