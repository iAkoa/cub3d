/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 07:59:32 by pat               #+#    #+#             */
/*   Updated: 2023/02/08 15:42:33 by pat              ###   ########lyon.fr   */
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

/*3d DRAW*/
double	d_floor(t_data *data, double j, double i);
double	d_wall(t_data *data, t_engine *engine, double j, double i);
double	d_ceil(t_data *data, t_engine *engine, double j, double i);
void	d_vertical_wall(t_data *data, t_engine *engine, double j, double i);
double	d_wall(t_data *data, t_engine *engine, double j, double i);
void	d_3d(t_data *data, t_engine *engine, double j);

#endif