/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_check_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:11:46 by pat               #+#    #+#             */
/*   Updated: 2023/01/25 08:48:16 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"
#include "parsing.h"
#include "../error/error.h"

static void	check_left(t_data *data, t_map *map, int checkpoint)
{
	int i;
	
	i = checkpoint;
	while (i >= 0 && map[i].stop != 1 && map[checkpoint].y == map[i].y)
	{
		// if (map[i].z == EMPTY)
		// 	error(data, "MAP OPEN !");
		if (map[i].z == WALL)
			return ;
		i--;
	}
	error(data, "MAP OPEN ON THE LEFT !");
}

static void	check_right(t_data *data, t_map *map, int checkpoint)
{
	int i;
	
	i = checkpoint;
	while (i >= 0 && map[i].stop != 1 && map[checkpoint].y == map[i].y)
	{
		// if (map[i].z == EMPTY)
		// 	error(data, "MAP OPEN !");
		if (map[i].z == WALL)
			return ;
		i++;
	}
	error(data, "MAP OPEN ONT THE RIGHT !");
}

static void	check_top(t_data *data, t_map *map, int checkpoint)
{
	int i;
	
	i = checkpoint;
	while (i >= 0)
	{
		// if (map[i].z == EMPTY)
		// 	error(data, "MAP OPEN !");
		if (map[i].z == WALL && map[i].x == map[checkpoint].x)
			return ;
		i--;
	}
	error(data, "MAP OPEN ON THE TOP !");
}

static void	check_bottom(t_data *data, t_map *map, int checkpoint)
{
	int i;
	
	i = checkpoint;
	while (i >= 0 && map[i].stop != 1)
	{
		// if (map[i].z == EMPTY)
		// 	error(data, "MAP OPEN !");
		if (map[i].z == WALL && map[i].x == map[checkpoint].x  && map[i].stop != 1)
			return ;
		i++;
	}
	error(data, "MAP OPEN ON THE BOTTOM !");
}

void	p_check_map(t_data *data, t_map *map)
{
	int	i;

	i = 0;
	while (!map[i].stop)
	{
		if (map[i].z == FLOOR)
		{
			check_left(data, map, i);
			check_right(data, map, i);
			check_top(data, map, i);
			check_bottom(data, map, i);
		}
		i++;
	}
}