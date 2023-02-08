/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:33:15 by pat               #+#    #+#             */
/*   Updated: 2023/02/08 15:42:33 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

/*RAYCASTING*/
void			e_raycasting(t_data *data, t_engine *engine);
void			e_vertical_line_check(t_data *data, t_engine *engine,
					double ra, double ntan);
/*HORIZONTAL ENGINE*/
void			e_size_h_rayon(t_engine *engine,
					double rx, double ry, double ra);
void			e_horizontal_line_check(t_data *data, t_engine *engine,
					double ra, double atan);
/*VERTICAL ENGINE*/
void			e_size_v_rayon(t_engine *engine,
					double rx, double ry, double ra);

/*UTILS*/
double			e_set_ra_before_loop(double ra, double pa);
double			e_set_ra_end_of_loop(double ra);
unsigned int	e_get_value(t_engine *engine, t_img *img, int y, int x);
int				e_check_ray(t_engine *engine);

/*MINIMAP*/
void			e_minimap(t_data *data, t_minimap minimap, t_map **map);

/*COLLISION*/
int				e_check_collision(t_map **map, int y, int x);

/*TEXTURE*/
unsigned int	get_value(t_engine *engine, t_img *img, int y, int x);

#endif