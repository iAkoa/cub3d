/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_raycasting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pata->draw.player_anglet <pata->draw.player_anglet@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:40:52 by pat               #+#    #+#             */
/*   Updated: 2023/01/19 17:49:19 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"
#include "engine.h"
#include "../draw/draw.h"
#include "../init/init.h"

void	vertical_mx_my_check(t_data *data, t_engine *engine)
{
	if (engine->ray_v.my < 0)
		engine->ray_v.my *= -1;
	if (engine->ray_v.mx < 0)
		engine->ray_v.mx *= -1;
	if (engine->ray_v.my >= data->draw.map_Ymax)
		engine->ray_v.my = data->draw.map_Ymax - 1;
}

void	horizontal_mx_my_check(t_data *data, t_engine *engine)
{
		// printf("engine->ray_h.my = %d\n", engine->ray_h.my);
	if (engine->ray_h.my < 0)
		engine->ray_h.my *= -1;
	if (engine->ray_h.mx < 0)
		engine->ray_h.mx *= -1;
	if (engine->ray_h.my >= data->draw.map_Ymax)
		engine->ray_h.my = data->draw.map_Ymax - 1;
	// printf("engine->ray_h.my = %d\n", engine->ray_h.my);
}


void	print_vertical_wall(t_data *data, t_engine *engine, float j, float i)
{
	int s = 1;
	if(s == 1)
	{
	if (engine->ray_v.rx < engine->posx)
		ft_my_mlx_pixel_put(data, (int)j, (int)i,
			0x000000FF);
	if (engine->ray_v.rx > engine->posx)
		ft_my_mlx_pixel_put(data, (int)j, (int)i,
			0x00FF0000);
	}
}

void	set_ray_v_case_1(t_engine *engine, float ntan)
{
	engine->ray_v.rx = (((int)engine->posx >> 5) * 32) - 0.0001;
	engine->ray_v.ry = (engine->posx - engine->ray_v.rx) * ntan + engine->posy;
	engine->ray_v.xo = -32;
	engine->ray_v.yo = (-engine->ray_v.xo * ntan);
	return ;
}

void	set_ray_v_case_2(t_engine *engine, float ntan)
{
	engine->ray_v.rx = (((int)engine->posx >> 5) * 32) + 32;
	engine->ray_v.ry = (engine->posx - engine->ray_v.rx) * ntan + engine->posy;
	engine->ray_v.xo = 32;
	engine->ray_v.yo = (-engine->ray_v.xo * ntan);
	return ;
}

void	set_ray_v_case_3(t_engine *engine)
{
	engine->ray_v.rx = engine->posx;
	engine->ray_v.ry = engine->posy;
	engine->ray_v.dof = engine->dof_limit;
	return ;
}


void	set_ray_h_case_1(t_engine *engine, float atan)
{

	engine->ray_h.ry = (((int)engine->posy >> 5) << 5) - 0.0001;
	engine->ray_h.rx = (engine->posy - engine->ray_h.ry) * atan + engine->posx;
	engine->ray_h.yo = -32;
	engine->ray_h.xo = (-engine->ray_h.yo * atan);
	return ;
}

void	set_ray_h_case_2(t_engine *engine, float atan)
{
	engine->ray_h.ry = (((int)engine->posy >> 5) << 5) + 32;
	engine->ray_h.rx = (engine->posy - engine->ray_h.ry) * atan + engine->posx;
	engine->ray_h.yo = 32;
	engine->ray_h.xo = (-engine->ray_h.yo * atan);
	return ;
}

void	set_ray_h_case_3(t_engine *engine)
{
	engine->ray_h.rx = engine->posx;
	engine->ray_h.ry = engine->posy;
	engine->ray_h.dof = engine->dof_limit;
	return ;
}


float	set_ra_before_loop(float ra, float pa)
{
	ra = pa - (M_PI / 6);
	if (ra < 0)
		ra += 2 * M_PI;
	if (ra > 2 * M_PI)
		ra -= 2 * M_PI;
	return (ra);
}

float	set_ra_end_of_loop(float ra)
{
	ra = ra + ((2 * M_PI / 6) / 1919);
	if (ra < 0)
		ra += 2 * M_PI;
	if (ra > 2 * M_PI)
		ra -= 2 * M_PI;
	return (ra);
}

unsigned int	get_value(t_data *data, t_engine *engine, int y, int x)
{
	int	texx;
	int	texy;

	(void)y;
	texx = 0;
	if (engine->v_check == 1)
		texx = ((engine->ray_v.ry / 32) - engine->ray_v.my) * 32;
	else
		texx = ((engine->ray_h.rx / 32) - engine->ray_h.mx) * 32;
	texy = ((x - (540 - engine->lineh / 2)) / engine->lineh) * data->width;
	data->window.addr = mlx_get_data_addr(data->window.img, &(data->window.bits_per_pixel),
			&(data->lenght), &data->window.endian);
	return (data->window.addr[texy * data->window.line_length / 4 + texx]);
}

float	print_floor(t_data *data, float j, float i)
{
	while (i < 1080)
	{
		if (j < 1919 && i < 1079 && j >= 0 && i >= 0)
		{
			ft_my_mlx_pixel_put(data, (int)j, (int)i, 0x0000FF00);
		}
		i++;
	}
	return (i);
}

float	print_wall(t_data *data, t_engine *engine, float j, float i)
{

	while (i < (540 + engine->lineh / 2))
	{
		if (j < 1919 && i < 1079 && j >= 0 && i >= 0)
		{
			if (engine->v_check == 1)
			{
				print_vertical_wall(data, engine, j, i);
			}
			else
			{
				if (engine->ray_h.ry > engine->posy)
					ft_my_mlx_pixel_put(data, (int)j, (int)i,
						0x00FFFF00);
				if (engine->ray_h.ry < engine->posy)
					ft_my_mlx_pixel_put(data, (int)j, (int)i,
						0x00FF00FF);
			}
		}
		i++;
	}
	return (i);
}

float	print_ceil(t_data *data, t_engine *engine, float j, float i)
{
			// printf("data->parsing.s_color = %f\n", 540 - engine->lineh / 2);
	while (i < (540 - engine->lineh / 2))
	{
		if (j < 1919 && i < 1079 && j >= 0 && i >= 0)
		{
			ft_my_mlx_pixel_put(data, (int)j,
				(int)i, 0x000000FF);
		}
		i++;
	}
	return (i);
}

void	print_3d_wall(t_data *data, t_engine *engine, float j)
{
	float i = 0;

	i = 0;
	i = print_ceil(data, engine, j, i);
	i = print_wall(data, engine, j, i);
	i = print_floor(data, j, i);
}

void	draw_walls(t_data *data, t_engine *engine, float ra, float j)
{
	float	ca;
	ca = engine->pa - ra;
	if (ca < 0)
		ca += 2 * M_PI;
	if (ca > 2 * M_PI)
		ca -= 2 * M_PI;
	engine->dist = engine->dist * cos(ca);
	engine->lineh = ((25 * 1920) / engine->dist);
	engine->lineo = (960 - engine->lineh / 2);

	print_3d_wall(data, engine, j);
	return ;
}

void	print_v_rayon(t_engine *engine, float rx, float ry, float ra)
{
	float	c;
	(void)ra;
	c = 0;
	c = sqrtf((powf(rx - engine->posx, 2) + powf(ry - engine->posy, 2)));
	engine->dist = c;
	engine->v_check = 1;
}

void	 print_h_rayon(t_engine *engine, float rx, float ry, float ra)
{
	float	c;

	(void)ra;
	c = 0;
	c = sqrtf((powf(rx - engine->posx, 2) + powf(ry - engine->posy, 2)));
	engine->dist = c;
}

int	check_ray(t_engine *engine)
{
	if (sqrtf((powf(engine->ray_h.rx - engine->posx, 2)
				+ powf(engine->ray_h.ry - engine->posy, 2)))
		>= sqrtf((powf(engine->ray_v.rx - engine->posx, 2)
				+ powf(engine->ray_v.ry - engine->posy, 2))))
		return (1);
	else
		return (0);
	return (0);
}

void	vertical_line_check(t_data *data, t_engine *engine, float ra, float ntan)
{
	if ((ra > engine->p2) && (ra < engine->p3))
		set_ray_v_case_1(engine, ntan);
	if ((ra < engine->p2) || (ra > engine->p3))
		set_ray_v_case_2(engine, ntan);
	if (ra == 0 || ra == M_PI)
		set_ray_v_case_3(engine);
		(void)data;
	while (engine->ray_v.dof < engine->dof_limit)
	{
		engine->ray_v.mx = ((int)(engine->ray_v.rx) >> 5);
		engine->ray_v.my = ((int)(engine->ray_v.ry) >> 5);
		vertical_mx_my_check(data, &(data->engine));
		if (engine->ray_v.my >= data->draw.map_Ymax)
			break;
		if (engine->ray_v.mx >= data->draw.map_Xmax)
			break;
		engine->ray_v.mp = engine->ray_v.my * data->draw.map_Xmax + engine->ray_v.mx;
		// dprintf(engine->fd, "data->map2d[engine->ray_h.my][0].x_max  = %i\n", data->draw.map_Xmax);
		if (engine->ray_h.mp > 0 && (engine->ray_v.mp
				< (data->draw.map_Xmax  * data->draw.map_Ymax))
			&& data->map2d[engine->ray_v.my][engine->ray_v.mx].z == WALL)
		{
			// printf("cub->data.width * cub->data.map_data.map_size = %i\n", data->draw.map_Xmax * data->draw.map_Ymax);
			engine->ray_v.dof = engine->dof_limit;
		}
		else
		{
			engine->ray_v.rx += engine->ray_v.xo;
			engine->ray_v.ry += engine->ray_v.yo;
			engine->ray_v.dof += 1;
		}
	}
}

void	horizontal_line_check(t_data *data, t_engine *engine, float ra, float atan)
{
	if (ra > M_PI)
		set_ray_h_case_1(engine, atan);
	if (ra < M_PI)
		set_ray_h_case_2(engine, atan);
	if (ra == 0 || ra == M_PI)
		set_ray_h_case_3(engine);
	// (void)data;
	while (engine->ray_h.dof < engine->dof_limit)
	{
		engine->ray_h.mx = ((int)(engine->ray_h.rx) >> 5);
		engine->ray_h.my = ((int)(engine->ray_h.ry) >> 5);
		if (engine->ray_h.my >= data->draw.map_Ymax)
			break;
		if (engine->ray_h.mx >= data->draw.map_Xmax)
			break;
		horizontal_mx_my_check(data, engine);
		// printf("engine->ray_h.mx = %i, engine->ray_h.my = %i\n", engine->ray_h.mx, engine->ray_h.my);
		engine->ray_h.mp = engine->ray_h.my * data->draw.map_Xmax + engine->ray_h.mx;
		if (engine->ray_h.mp > 0 && (engine->ray_h.mp
				< (data->draw.map_Xmax * data->draw.map_Ymax))
			&& data->map2d[engine->ray_h.my][engine->ray_h.mx].z == WALL)
			engine->ray_h.dof = engine->dof_limit;
		else
		{
			engine->ray_h.rx += engine->ray_h.xo;
			engine->ray_h.ry += engine->ray_h.yo;
			engine->ray_h.dof += 1;
		}
	}
}

void	draw_rays(t_data * data, t_engine *engine)
{
	int		r;
	float	j;

	r = 0;
	j = 0;
	engine->ra = 0.0;
	engine->ra = set_ra_before_loop(engine->ra, engine->pa);
	data->engine.test = 0x00FFFFFF;
	while (r < 1920)
	{
		// printf("test\n");
		engine->v_check = 0;
		init_ray_var(data);
		engine->atan = -1 / tanf(engine->ra);
		engine->ntan = -tanf(engine->ra);
		horizontal_line_check(data, engine, engine->ra, engine->atan);
		vertical_line_check(data, engine, engine->ra, engine->ntan);
		if (check_ray(engine) == 0)
		{
			print_h_rayon(engine, engine->ray_h.rx, engine->ray_h.ry, engine->ra);
		}
		else
		{
			print_v_rayon(engine, engine->ray_v.rx, engine->ray_v.ry, engine->ra);
		}
		draw_walls(data, engine, engine->ra, j);
		j += 1;
		engine->ra = set_ra_end_of_loop(engine->ra);
		r++;
	}
}