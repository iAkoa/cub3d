/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:33:15 by pat               #+#    #+#             */
/*   Updated: 2023/01/25 03:58:23 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

/*RAYCASTING*/
void			e_raycasting(t_data * data, t_engine *engine);
void			e_vertical_line_check(t_data *data, t_engine *engine, float ra, float ntan);
/*HORIZONTAL ENGINE*/
void			e_size_h_rayon(t_engine *engine, float rx, float ry, float ra);
void			e_horizontal_line_check(t_data *data, t_engine *engine, float ra, float atan);
/*VERTICAL ENGINE*/
void			e_size_v_rayon(t_engine *engine, float rx, float ry, float ra);

/*UTILS*/
float			e_set_ra_before_loop(float ra, float pa);
float			e_set_ra_end_of_loop(float ra);
unsigned int	e_get_value(t_data *data, t_engine *engine, int y, int x);
int				e_check_ray(t_engine *engine);

#endif