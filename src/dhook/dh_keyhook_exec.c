/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dh_keyhook_exec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 03:44:17 by pat               #+#    #+#             */
/*   Updated: 2023/01/17 17:56:32 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"
#include "dhook.h"
#include "../draw/draw.h"

# define LEFT 1
# define RIGHT 2
# define TOP 3
# define BOTTOM 4

int check_wall(t_data *data, int posX, int posY, int side)
{
	int		check;
	char	*dst;
	int		i;

	i = 0;
	if (side == LEFT)
	{
		check = posX;
		while (check > 4)
		{
				// printf("test");
			dst = data->window.addr + (posY * data->window.line_length
					+ check * (data->window.bits_per_pixel / 8));
			if (*(unsigned int *)dst == WALL_COLOR)
				return(i);
			check -= data->draw.size_of_bloc / 2;
			i++;
		}
	}
	else if (side == RIGHT)
	{
		check = posX;
		while (check < data->draw.x_max_minimap)
		{
			dst = data->window.addr + (posY * data->window.line_length
					+ check * (data->window.bits_per_pixel / 8));
			if (*(unsigned int *)dst == WALL_COLOR)
				return(i);
			check += data->draw.size_of_bloc / 2;
			i++;
		}
	}
	else if (side == TOP)
	{
		check = posY;
		while (check > 0)
		{
			dst = data->window.addr + (check * data->window.line_length
					+ posX * (data->window.bits_per_pixel / 8));
			if (*(unsigned int *)dst == WALL_COLOR)
				return(i);
			check -= data->draw.size_of_bloc / 2;
			i++;
		}
	}
	else if (side == BOTTOM)
	{
		check = posY;
		while (check < data->draw.y_max_minimap)
		{
			// printf("test");
			dst = data->window.addr + (check * data->window.line_length
					+ posX * (data->window.bits_per_pixel / 8));
			if (*(unsigned int *)dst == WALL_COLOR)
				return(i);
			// printf("*(unsigned int *)dst = %i\n", *(unsigned int *)dst);
			check += data->draw.size_of_bloc / 2;
			i++;
		}
	}
	return (0);
}

void	ft_keyhook1(t_data *data, t_window win, t_map *map, int keycode)
{
	(void)map;
	(void)data;
	if (keycode == ESC)
	{
		mlx_destroy_image(win.mlx_ptr, win.img);
		mlx_destroy_window(win.mlx_ptr, win.win_ptr);
		gc_free_all(&data->track);
		exit(0);
	}
	if (keycode == LEFT_ARROW)
	{
		ft_my_pixel_clear(data);
		data->draw.player_angle-= M_PI/50;
		ft_keyhook_process(win);
		d_minimap(data, data->draw, data->map2d);
	}
}

void	ft_keyhook2(t_data *data, t_window win, t_map *map, int keycode)
{
	(void)map;
	(void)data;


	if (keycode == RIGHT_ARROW)
	{
		ft_my_pixel_clear(data);
		data->draw.player_angle+= M_PI/50;
		ft_keyhook_process(win);
		d_minimap(data, data->draw, data->map2d);
	}
}

void	ft_keyhook3(t_data *data, t_window win, t_map *map, int keycode)
{
	(void)map;
	(void)data;
	int check1;
	int check2;
	(void)check2;
	check1 = 0;
	check2 = 0;

	if (keycode == W)
	{
		check1 = check_wall(data, data->draw.posX_display, data->draw.posY_display, TOP);
		check2 = check_wall(data, data->draw.posX_display, data->draw.posY_display, BOTTOM);
		if(((check1 >= 5 || check1 == 0) && (check2 >= 5 || check2 == 0)))
			data->draw.moove_mapY+=3;
		else if(!data->draw.hit_top)
			data->dhook.moove_spawn_y -= 3;
		data->draw.hit_top = 0;
		ft_my_pixel_clear(data);
		ft_keyhook_process(win);
		d_minimap(data, data->draw, data->map2d);
	}
	if (keycode == A)
	{
		check1 = check_wall(data, data->draw.posX_display, data->draw.posY_display, LEFT);
		check2 = check_wall(data, data->draw.posX_display, data->draw.posY_display, RIGHT);
		printf("check1 = %i\n", check1);
		printf("check2 = %i\n", check2);
		if(((check1 >= 9 || check1 == 0) && (check2 >= 9 || check2 == 0)))
			data->draw.moove_mapX+=3;
		else if (!data->draw.hit_left)
			data->dhook.moove_spawn_x-= 3;
		data->draw.hit_left = 0;
		ft_my_pixel_clear(data);
		ft_keyhook_process(win);
		d_minimap(data, data->draw, data->map2d);
	}
}

void	ft_keyhook4(t_data *data, t_window win, t_map *map, int keycode)
{
	(void)map;
	(void)data;
	int check1;
	int check2;
	(void)check2;
	check1 = 0;
	check2 = 0;
	if (keycode == S)
	{
		check1 = check_wall(data, data->draw.posX_display, data->draw.posY_display, BOTTOM);
		check2 = check_wall(data, data->draw.posX_display, data->draw.posY_display, TOP);
		printf("check1 = %i\n", check1);
		printf("check2 = %i\n", check2);
		if(((check1 >= 5 || check1 == 0) && (check2 >= 5 || check2 == 0)))
			data->draw.moove_mapY-=3;
		else if(!data->draw.hit_bottom)
			data->dhook.moove_spawn_y+=3;
		data->draw.hit_bottom = 0;
		ft_my_pixel_clear(data);
		ft_keyhook_process(win);
		d_minimap(data, data->draw, data->map2d);
	}
	if (keycode == D)
	{
		check1 = check_wall(data, data->draw.posX_display, data->draw.posY_display, RIGHT);
		check2 = check_wall(data, data->draw.posX_display, data->draw.posY_display, LEFT);
		printf("check1 = %i\n", check1);
		printf("check2 = %i\n", check2);
		if(((check1 >= 9 || check1 == 0) && (check2 >= 9 || check2 == 0)))
			data->draw.moove_mapX-=3;
		else if (!data->draw.hit_right)
			data->dhook.moove_spawn_x+=3;
		data->draw.hit_right = 0;
		ft_my_pixel_clear(data);
		ft_keyhook_process(win);
		d_minimap(data, data->draw, data->map2d);
	}
}

void	ft_keyhook5(t_data *data, t_window win, t_map *map, int keycode)
{
	(void)map;
	(void)data;


	if (keycode == X)
	{
		ft_keyhook_process(win);
		// ft_draw(data, map);
	}
}
