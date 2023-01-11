/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_draw_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:30:09 by pat               #+#    #+#             */
/*   Updated: 2023/01/11 04:48:28 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"
#include "draw.h"

void	ft_my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x > 1300 || y > 900 || x < 0 || y < 0)
		return ;
	dst = data->window.addr + (y * data->window.line_length
			+ x * (data->window.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_my_mlx_pixel_put_tuning(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x > 1300 || y > 900 || x < 0 || y < 0)
		return (0);
	dst = data->window.addr + (y * data->window.line_length
			+ x * (data->window.bits_per_pixel / 8));
	if (*(unsigned int *)dst == 15728895)
		return (0);
	*(unsigned int *)dst = color;
	return (1);
}