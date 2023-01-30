/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_pixel_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:30:09 by pat               #+#    #+#             */
/*   Updated: 2023/01/27 11:44:14 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"
#include "draw.h"

void	d_my_pixel_clear(t_data *data)
{

	int	x;
	int	y;

	x = 0;
	while (x < 1920)
	{
		y = 0;
		while (y < 1080)
		{
			d_my_mlx_pixel_put(data, x, y, 0);
			y++;
		}
		x++;
	}
}

void	d_my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	// int		tmp_fusion;
	if (x > 1920 || y > 1080 || x < 0 || y < 0)
		return ;
	dst = data->window.addr + (y * data->window.line_length
			+ x * (data->window.bits_per_pixel / 8));
	// tmp_fusion = *(unsigned int *)dst;
	// *(unsigned int *)dst = ft_colinterpolate(tmp_fusion, color, 0.1);
	*(unsigned int *)dst = color;
	
}

void	d_my_mlx_pixel_put_minimap(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		tmp_fusion;
	if (x > data->minimap.x_max_minimap || y > data->minimap.y_max_minimap || x < 0 || y < 0)
		return ;
	dst = data->window.addr + (y * data->window.line_length
			+ x * (data->window.bits_per_pixel / 8));
	tmp_fusion = *(unsigned int *)dst;
	*(unsigned int *)dst = color;
	*(unsigned int *)dst = ft_colinterpolate(color, tmp_fusion, 0.2);
	
}

int	d_my_mlx_pixel_put_view(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x > data->minimap.x_max_minimap || y > data->minimap.y_max_minimap || x < 0 || y < 0)
		return (0);
	dst = data->window.addr + (y * data->window.line_length
			+ x * (data->window.bits_per_pixel / 8));
	if (*(unsigned int *)dst == WALL_COLOR || *(unsigned int *)dst == GRID_WALL_COLOR)
		return (0);
	*(unsigned int *)dst = color;
	return (1);
}

int	d_my_mlx_pixel_put_player(t_data *data, int x, int y, int color)
{
	char	*dst;
	char	*check_hit;
	
	if (x + 3 > data->minimap.x_max_minimap || y + 3> data->minimap.y_max_minimap || x - 3 < 0 || y - 3 < 0)
		return (0);
	check_hit = data->window.addr + (y * data->window.line_length
		+ (x + 3) * (data->window.bits_per_pixel / 8));
	if (*(unsigned int *)check_hit == WALL_COLOR)
		data->minimap.hit_right = 1;
	check_hit = data->window.addr + (y * data->window.line_length
		+ (x - 3) * (data->window.bits_per_pixel / 8));
	if (*(unsigned int *)check_hit == WALL_COLOR)
		data->minimap.hit_left = 1;
	check_hit = data->window.addr + ((y + 3) * data->window.line_length
		+ x * (data->window.bits_per_pixel / 8));
	if (*(unsigned int *)check_hit == WALL_COLOR)
		data->minimap.hit_bottom = 1;
	check_hit = data->window.addr + ((y - 3) * data->window.line_length
		+ x * (data->window.bits_per_pixel / 8));
	if (*(unsigned int *)check_hit == WALL_COLOR)
		data->minimap.hit_top = 1;
	dst = data->window.addr + (y * data->window.line_length
			+ x * (data->window.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return (1);
}