/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 07:59:32 by pat               #+#    #+#             */
/*   Updated: 2023/01/25 03:45:52 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

/*DRAW*/
void	draw(t_data *data);

void	d_my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		d_my_mlx_pixel_put_view(t_data *data, int x, int y, int color);
int		d_my_mlx_pixel_put_player(t_data *data, int x, int y, int color);
void	d_my_mlx_pixel_put_minimap(t_data *data, int x, int y, int color);
void	d_my_pixel_clear(t_data *data);

/*Minimap DRAW*/
void	d_draw_minimap(t_data *d, t_map *minimap);
void	d_minimap(t_data *data, t_draw draw, t_map **map);


/*3d DRAW*/
float	d_floor(t_data *data, float j, float i);
float	d_wall(t_data *data, t_engine *engine, float j, float i);
float	d_ceil(t_data *data, t_engine *engine, float j, float i);
void	d_vertical_wall(t_data *data, t_engine *engine, float j, float i);
float	d_wall(t_data *data, t_engine *engine, float j, float i);
void	d_3d(t_data *data, t_engine *engine, float j);

#endif