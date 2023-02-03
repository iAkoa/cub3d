/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 07:49:28 by pat               #+#    #+#             */
/*   Updated: 2023/01/30 18:20:38 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

void	init_data(t_data *data, t_track *track, t_map *map);
void	init_window(t_data *data);
void	init_parsing(t_data *data);
void	init_minimap_engine(t_data *data);
void	init_dhook(t_data *data);
void	init_engine(t_data *data);
void	init_ray_var(t_data *data);

#endif