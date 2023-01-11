/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dhook.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 07:49:28 by pat               #+#    #+#             */
/*   Updated: 2022/12/13 17:13:32 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DHOOK_H
# define DHOOK_H

int		ft_keyhook(int keycode, t_data *data);
void	ft_keyhook_process(t_window win);
void	ft_keyhook5(t_data *data, t_window win, t_map *map, int keycode);
void	ft_keyhook4(t_data *data, t_window win, t_map *map, int keycode);
void	ft_keyhook3(t_data *data, t_window win, t_map *map, int keycode);
void	ft_keyhook2(t_data *data, t_window win, t_map *map, int keycode);
void	ft_keyhook1(t_data *data, t_window win, t_map *map, int keycode);


#endif