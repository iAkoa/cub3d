/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dh_keyhook_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:54:48 by pat               #+#    #+#             */
/*   Updated: 2023/01/30 17:23:17 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"c
#include "dhook.h"
#include "../draw/draw.h"

void	ft_keyhook_process(t_window win)
{
	mlx_clear_window(win.mlx_ptr, win.win_ptr);
	mlx_new_image(win.mlx_ptr, 1300, 900);
}
