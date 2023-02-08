/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_collision.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:28:44 by pat               #+#    #+#             */
/*   Updated: 2023/02/03 18:55:45 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "engine.h"

int	e_check_collision(t_map **map, int y, int x)
{
	int		i;

	i = 0;
	while (i < 5)
	{
		if (map[y][x].z != WALL)
			return (0);
		i++;
	}
	return (1);
}
