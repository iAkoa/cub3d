/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dhook.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 07:49:28 by pat               #+#    #+#             */
/*   Updated: 2023/01/26 08:28:48 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DHOOK_H
# define DHOOK_H

int		dh_keyhook(int keycode, t_data *data);
int		check_wall(t_data *data, int posX, int posY, int side);
void	dh_roation(t_data *data,int keycode);
void	dh_translation(t_data *data,int keycode);
void	dh_translation_minimap(t_data *data,int keycode);
void	dh_bonus(t_data *data,int keycode);
void	dh_moove_forward(t_data *data, t_engine *engine);
void	dh_moove_backward(t_data *data, t_engine *engine);
void	dh_moove_right(t_data *data, t_engine *engine);
void	dh_moove_left(t_data *data, t_engine *engine);
void	set_xo_and_yo_for_side_walk(t_engine *engine);
void	dh_rotation_minimap_left(t_data *data, t_minimap *minimap);
void	dh_rotation_minimap_right(t_data *data, t_minimap *minimap);
void	dh_rotation_right(t_data *data, t_engine *engine);
void	dh_rotation_left(t_data *data, t_engine *engine);

#endif