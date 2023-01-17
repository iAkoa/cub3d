/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 07:59:32 by pat               #+#    #+#             */
/*   Updated: 2023/01/16 16:50:31 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

void	draw(t_data *data, t_map *map);
void	ft_my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		ft_my_mlx_pixel_put_view(t_data *data, int x, int y, int color);
int		ft_my_mlx_pixel_put_player(t_data *data, int x, int y, int color);
void	ft_my_mlx_pixel_put_minimap(t_data *data, int x, int y, int color);
void	ft_draw_minimap(t_data *d, t_map *minimap);
void	d_minimap(t_data *data, t_draw draw, t_map **map);
void	ft_my_pixel_clear(t_data *data);

#endif