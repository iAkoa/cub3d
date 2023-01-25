/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:44:39 by rmattheo          #+#    #+#             */
/*   Updated: 2023/01/25 06:37:16 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "../libft2/include/libft.h"
# include "../libft2/include/gc.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

typedef struct s_data		t_data;
typedef struct s_window		t_window;
typedef struct s_map		t_map;
typedef struct s_parsing	t_parsing;
typedef struct s_draw		t_draw;
typedef struct s_dhook		t_dhook;
typedef struct s_fix		t_fix;
typedef struct s_engine		t_engine;
typedef struct s_rayv		t_rayv;
typedef struct s_rayh		t_rayh;

struct s_parsing
{
	int	fd;
	char *file;
	int	count;
	int	size_mal;
	int	y_max;
	int	x_max;
	int	sky_red;
	int sky_green;
	int sky_blue;
	int	floor_red;
	int floor_green;
	int floor_blue;
	int f_color;
	int s_color;
	char *east_path;
	char *west_path;
	char *south_path;
	char *north_path;
	int	start_spawn;
	int test;
};

struct s_window
{
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*img;
	void	*mlx_ptr;
	void	*win_ptr;
	int		x_max;
	int		y_max;
	int		x_max_minimap;
	int		y_max_minimap;
};

struct s_draw
{
	int	x_max_minimap;
	int	y_max_minimap;
	int	x_display;
	int y_display;
	int	size_of_bloc;
	int	x;
	int	y;
	double	posX;
	double	posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	int	posY_display;
	int	posX_display;
	double	player_angle;
	int	ref_posX;
	int	ref_posY;
	int moove_mapX;
	int moove_mapY;
	int	hit_top;
	int	hit_bottom;
	int	hit_left;
	int	hit_right;
	int size_playerxMax;;
	int size_playerxMin;
	int size_playeryMax;
	int size_playeryMin;
	int size_check;
	int map_Xmax;
	int map_Ymax;
	int map_Xmin;
	int map_Ymin;
	int map_size;
};

struct s_rayv
{
	float	rx;
	float	ry;
	float	xo;
	float	yo;
	int		mx;
	int		my;
	int		mp;
	int		dof;
};

struct s_rayh
{
	float	rx;
	float	ry;
	float	xo;
	float	yo;
	int		mx;
	int		my;
	int		mp;
	int		dof;
};
struct s_engine
{
	t_rayv		ray_v;
	t_rayh		ray_h;
	int			test;
	int			hit_wall;
	int			v_check;
	int			h_check;
	int			dof_limit;
	float		p2;
	float		p3;
	float		ra;
	float		atan;
	float		ntan;
	float		ty_off;
	float		lineo;
	float		lineh;
	float		x;
	float		y;
	float		z;
	float		pa;
	float		pdx;
	float		pdy;
	float		posx;
	float		posy;
	float		x1;
	float		x2;
	float		y1;
	float		y2;
	float		max;
	float		bresenx;
	float		breseny;
	float		raylx;
	float		rayly;
	float		dist;
	int			fd;
};

struct s_dhook
{
	int	moove_spawn_x;
	int	moove_spawn_y;
};

struct s_data
{
	int			ac;
	char		**av;
	t_track		*track;
	t_map		*map;
	t_map		**map2d;
	t_window	window;
	t_parsing	parsing;
	t_draw		draw;
	t_dhook		dhook;
	t_engine	engine;
	int			width;
	int			lenght;
	char		*mapchar;
	int			*mapint;
};

struct s_map
{
	int		size_x;
	double	x;
	double	y;
	double	z;
	double	x_max;
	int		color;
	int		stop;
};


# define WALL_COLOR 0x00FFA500
# define FLOOR_COLOR 0x00FFFFFE
# define GRID_COLOR 0x0000002
# define GRID_WALL_COLOR 0x00000003
# define PLAYER_COLOR 0x00F00001

# define FIX_MAP_TOP 1
# define FIX_MAP_BOT 2
# define FIX_MAP_RIGHT 3
# define FIX_MAP_LEFT 4

# define HIT_TOP 1
# define HIT_BOT 2
# define HIT_LEFT 3
# define HIT_RIGHT 4

#define EMPTY 0
#define FLOOR 1
#define WALL 2
#define EAST 3
#define NORTH 4
#define WEST 5
#define SOUTH 6

# define ESC 53

# define A 0
# define B 11
# define C 8
# define D 2
# define E 14
# define F 3
# define G 9
# define H 4
# define I 34
# define J 38
# define K 40
# define L 37
# define M 46
# define N 45
# define O 31
# define P 35
# define Q 12
# define R 15
# define S 1
# define T 17
# define U 32
# define V 9
# define W 13
# define X 7
# define Y 16
# define Z 6

# define ONE_NUM_PAD 83
# define TWO_NUM_PAD 84
# define THREE_NUM_PAD 85
# define FOUR_NUM_PAD 86
# define FIVE_NUM_PAD 87
# define SIX_NUM_PAD 88
# define SEVEN_NUM_PAD 89
# define EIGHT_NUM_PAD 91
# define NINE_NUM_PAD 92

# define LESS 78
# define MORE 69

# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define DOWN_ARROW 125
# define UP_ARROW 126

#endif
