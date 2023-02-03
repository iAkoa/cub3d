/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 07:59:53 by pat               #+#    #+#             */
/*   Updated: 2023/01/30 17:39:16 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

char	*p_parsing_map(t_data *data, char *line);
void	p_check_map(t_data *data, t_map *map);
void	p_color_sky_blue(t_data *data, char *line);
void	p_color_sky_red(t_data *data, char *line);
void	p_color_sky_green(t_data *data, char *line);
void	p_color_floor_blue(t_data *data, char *line);
void	p_color_floor_red(t_data *data, char *line);
void	p_color_floor_green(t_data *data, char *line);
void	p_path(t_data *data, char *line);
int		p_parsing(t_data *data, char *fd);
char	*p_gnl_secure(t_data *data, char *line, char *str);
char	*jump_new_line(t_data *data, char *line);
char	*p_gnl_jnl_secure(t_data *data, char *line, char *str);
int		ft_strlen_split(char **str);
void	p_convert_map_1d(t_data *data, t_map *map1d);
void	p_set_texture_struct(t_engine *engine, t_data *data);
int		p_strcmp(char *line, char *cmp);
void	p_startspawn(t_data *data, t_map *map);
void	p_set_angle(t_data *data, t_map *map, int i);

#endif