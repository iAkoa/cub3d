/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dh_translation_minimap.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:32:07 by pat               #+#    #+#             */
/*   Updated: 2023/01/25 12:38:46 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"
#include "dhook.h"
#include "../draw/draw.h"

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
				data->minimap.size_playerxMin = i * 2;
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
			check += data->minimap.size_of_bloc / 4;
			i++;
		}
	}
	else if (side == RIGHT)
	{
		check = posX;
		while (check < data->minimap.x_max_minimap)
		{
			dst = data->window.addr + (posY * data->window.line_length
			+ check * (data->window.bits_per_pixel / 8));
			if (*(unsigned int *)dst == WALL_COLOR || *(unsigned int *)dst == FLOOR_COLOR || *(unsigned int *)dst == GRID_COLOR || *(unsigned int *)dst == GRID_WALL_COLOR)
				data->minimap.size_playerxMax = i * 2;
			if (*(unsigned int *)dst == WALL_COLOR || *(unsigned int *)dst == GRID_WALL_COLOR)
			{
				// printf("check = %i\n", check / data->minimap.size_of_bloc);
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
			check += data->minimap.size_of_bloc / 4;
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
				// printf("data->minimap.size_playeryMin = %i\n", data->minimap.size_playeryMin);
				data->minimap.size_playeryMin = i * 2;
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
			check += data->minimap.size_of_bloc / 4;
			i++;
		}
	}
	else if (side == BOTTOM)
	{
		check = 0;
		while (check < data->minimap.y_max_minimap)
		{
			dst = data->window.addr + ((check + posY) * data->window.line_length
			+ posX * (data->window.bits_per_pixel / 8));
			if (*(unsigned int *)dst == WALL_COLOR || *(unsigned int *)dst == FLOOR_COLOR || *(unsigned int *)dst == GRID_COLOR || *(unsigned int *)dst == GRID_WALL_COLOR)
				data->minimap.size_playeryMax = i * 2;
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
			check += data->minimap.size_of_bloc / 4;
			i++;
		}
	}
	return (0);
}