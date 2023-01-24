/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dh_keyhook_exec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 03:44:17 by pat               #+#    #+#             */
/*   Updated: 2023/01/23 14:32:37 by pat              ###   ########lyon.fr   */
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
	int		count;
	int		check;
	char	*dst;
	int		i;

	i = 0;
	count = 0;
	if (side == LEFT)
	{
		check = 0;
		while (posX - check >=  0)
		{
			dst = data->window.addr + (posY * data->window.line_length
			+ (posX - check )* (data->window.bits_per_pixel / 8));
			if (*(unsigned int *)dst == WALL_COLOR || *(unsigned int *)dst == FLOOR_COLOR || *(unsigned int *)dst == GRID_COLOR || *(unsigned int *)dst == GRID_WALL_COLOR)
				data->draw.size_playerxMin = i * 2;
			if (*(unsigned int *)dst == WALL_COLOR || *(unsigned int *)dst == GRID_WALL_COLOR)
			{
				// printf("check  = %i\n", check); 
				while((*(unsigned int *)dst == WALL_COLOR || *(unsigned int *)dst == GRID_WALL_COLOR) && (posX - check >=  0))
				{
						dst = data->window.addr + (posY * data->window.line_length
						+ (posX - check) * (data->window.bits_per_pixel / 8));
						check++;
						count++;
				}
				if (count >= 30)
					return(i);
			}
			check += data->draw.size_of_bloc / 4;
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
			if (*(unsigned int *)dst == WALL_COLOR || *(unsigned int *)dst == FLOOR_COLOR || *(unsigned int *)dst == GRID_COLOR || *(unsigned int *)dst == GRID_WALL_COLOR)
				data->draw.size_playerxMax = i * 2;
			if (*(unsigned int *)dst == WALL_COLOR || *(unsigned int *)dst == GRID_WALL_COLOR)
			{
				// printf("check = %i\n", check / data->draw.size_of_bloc);
				while((*(unsigned int *)dst == WALL_COLOR || *(unsigned int *)dst == GRID_WALL_COLOR))
				{
					check++;
					count++;
					dst = data->window.addr + (posY * data->window.line_length
						+ check * (data->window.bits_per_pixel / 8));
				}
				if (count > 30)
					return(i);
			}
			check += data->draw.size_of_bloc / 4;
			i++;
		}
	}
	else if (side == TOP)
	{
		check = 0;
		while (posY - check >= 0)
		{
			dst = data->window.addr + ((posY - check) * data->window.line_length
			+ posX * (data->window.bits_per_pixel / 8));
			if (*(unsigned int *)dst == WALL_COLOR || *(unsigned int *)dst == FLOOR_COLOR || *(unsigned int *)dst == GRID_COLOR || *(unsigned int *)dst == GRID_WALL_COLOR)
			{
				// printf("data->draw.size_playeryMin = %i\n", data->draw.size_playeryMin);
				data->draw.size_playeryMin = i * 2;
			}
			if (*(unsigned int *)dst == WALL_COLOR || *(unsigned int *)dst == GRID_WALL_COLOR)
			{
				while(((*(unsigned int *)dst == WALL_COLOR || *(unsigned int *)dst == GRID_WALL_COLOR)) && (posY - check >= 0))
				{
					dst = data->window.addr + ((posY - check)* data->window.line_length
						+ posX * (data->window.bits_per_pixel / 8));
					count++;
					check++;
				}
				// printf("count = %i\n", count);
				if (count > 30)
				{
					// printf("ok !\n");
					return(i);
				}
			}
			check += data->draw.size_of_bloc / 4;
			i++;
		}
	}
	else if (side == BOTTOM)
	{
		check = 0;
		while (check < data->draw.y_max_minimap)
		{
			dst = data->window.addr + ((check + posY) * data->window.line_length
			+ posX * (data->window.bits_per_pixel / 8));
			if (*(unsigned int *)dst == WALL_COLOR || *(unsigned int *)dst == FLOOR_COLOR || *(unsigned int *)dst == GRID_COLOR || *(unsigned int *)dst == GRID_WALL_COLOR)
				data->draw.size_playeryMax = i * 2;
			if (*(unsigned int *)dst == WALL_COLOR || *(unsigned int *)dst == GRID_WALL_COLOR)
			{
				while((*(unsigned int *)dst == WALL_COLOR || *(unsigned int *)dst == GRID_WALL_COLOR))
				{
					count++;
					check++;
					dst = data->window.addr + ((check + posY)* data->window.line_length
						+ posX * (data->window.bits_per_pixel / 8));
				}
				if (count > 30)
					return(i);
			}
			check += data->draw.size_of_bloc / 4;
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
		data->draw.player_angle-= M_PI/25;
		draw(data);
	}
}

void	ft_keyhook2(t_data *data, t_window win, t_map *map, int keycode)
{
	(void)map;
	(void)data;


	if (keycode == RIGHT_ARROW)
	{
		ft_my_pixel_clear(data);
		data->draw.player_angle+= M_PI/25;
		ft_keyhook_process(win);
		draw(data);
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

	if (keycode == A)
	{
		check1 = check_wall(data, data->draw.posX_display, data->draw.posY_display, LEFT);			// printf("check1 = %i\n", check1);
		// printf("check2 = %i\n", check2);
		if (!data->draw.hit_left)
		{
			if(check1 == 0)
			{
				if (data->draw.size_playerxMin > 20)
					data->dhook.moove_spawn_x-=5;
				else
					data->draw.moove_mapX+=5;
			}
			else
				data->dhook.moove_spawn_x -=5;
		}
		data->draw.hit_left = 0;
		ft_my_pixel_clear(data);
		ft_keyhook_process(win);
		draw(data);
	}
	if (keycode == D)
	{
		check1 = check_wall(data, data->draw.posX_display, data->draw.posY_display, RIGHT);
		printf("check1 = %i\n", check1);
		printf("check2 = %i\n", check2);
		printf("data->draw.size_playerxMax = %i\n", data->draw.size_playerxMax);
		if(!data->draw.hit_right)
		{
			if(check1 == 0)
			{
				if (data->draw.size_playerxMax > 20)
					data->dhook.moove_spawn_x+=5;
				else
					data->draw.moove_mapX-=5;
			}
			else
				data->dhook.moove_spawn_x+=5;
		}
		data->draw.hit_right = 0;
		ft_my_pixel_clear(data);
		ft_keyhook_process(win);
		draw(data);
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
		if(!data->draw.hit_bottom)
		{
			if(check1 == 0)
			{
				if (data->draw.size_playeryMax > 20)
					data->dhook.moove_spawn_y+=5;
				else
					data->draw.moove_mapY-=5;
			}
			else
				data->dhook.moove_spawn_y +=5;
		}
		data->draw.hit_bottom = 0;
		ft_my_pixel_clear(data);
		ft_keyhook_process(win);
		draw(data);
	}
	if (keycode == W)
	{
		check1 = check_wall(data, data->draw.posX_display, data->draw.posY_display, TOP);
		printf("check1 = %i\n", check1);
		printf("data->draw.size_playeryMin = %i\n", data->draw.size_playeryMin);
		if (!data->draw.hit_top)
		{
			if(check1 == 0)
			{
				if (data->draw.size_playeryMin > 20)
					data->dhook.moove_spawn_y-=5;
				else
					data->draw.moove_mapY+=5;
			}
			else
				data->dhook.moove_spawn_y -=5;
		}
		data->draw.hit_top= 0;
		ft_my_pixel_clear(data);
		ft_keyhook_process(win);
		draw(data);
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
