/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dh_keyhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:37:54 by rmattheo          #+#    #+#             */
/*   Updated: 2022/12/13 17:10:26 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"
#include "dhook.h"
#include "../draw/draw.h"

int	ft_keyhook(int keycode, t_data *data)
{
	ft_keyhook1(data, data->window, data->map, keycode);
	ft_keyhook2(data, data->window, data->map, keycode);
	ft_keyhook3(data, data->window, data->map, keycode);
	ft_keyhook4(data, data->window, data->map, keycode);
	ft_keyhook5(data, data->window, data->map, keycode);
	return (0);
}
