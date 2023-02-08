/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:44:39 by rmattheo          #+#    #+#             */
/*   Updated: 2023/02/08 16:08:44 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

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
typedef struct s_minimap		t_minimap;
typedef struct s_dhook		t_dhook;
typedef struct s_fix		t_fix;
typedef struct s_engine		t_engine;
typedef struct s_rayv		t_rayv;
typedef struct s_rayh		t_rayh;
typedef struct s_collision	t_collision;
typedef struct s_img		t_img;

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
	int	checker;
	int	test;
};

typedef struct s_img
{
	void	*data;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

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

struct s_minimap
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
	double moove_mapX;
	double moove_mapY;
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
	double	rx;
	double	ry;
	double	xo;
	double	yo;
	int		mx;
	int		my;
	int		mp;
	int		dof;
};


struct s_collision
{
	int		ym_pos;
	int		xm_pos;
	int		yo_add;
	int		xo_add;
	int		yo_sub;
	int		xo_sub;
	int		xo_right;
	int		yo_right;
	int		xo_left;
	int		yo_left;
	int		xo;
	int		yo;
};

struct s_rayh
{
	double	rx;
	double	ry;
	double	xo;
	double	yo;
	int		mx;
	int		my;
	int		mp;
	int		dof;
};
struct s_engine
{
	t_collision	collision;
	t_rayv		ray_v;
	t_rayh		ray_h;
	int			test;
	int			hit_wall;
	int			v_check;
	int			h_check;
	int			dof_limit;
	double		p2;
	double		p3;
	double		ra;
	double		atan;
	double		ntan;
	double		ty_off;
	double		lineo;
	double		lineh;
	double		x;
	double		y;
	double		z;
	double		player_angle;
	double		pdx;
	double		pdy;
	double		posx;
	double		posy;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		max;
	double		bresenx;
	double		breseny;
	double		raylx;
	double		rayly;
	double		dist;
	int			fd;
	t_img		img_n;
	t_img		img_s;
	t_img		img_w;
	t_img		img_e;
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
	t_minimap	minimap;
	t_dhook		dhook;
	t_engine	engine;
	t_img		img;
	int			width;
	int			lenght;
	char		*mapchar;
	int			*mapint;
	int			tab_keycode[7];
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



# define WALL_COLOR 0x00C4C5B2
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

# define LEFT 1
# define RIGHT 2
# define TOP 3
# define BOTTOM 4

/*KEYCODE*/
# define ESC 65307
// # define ESC 53
# define TAB 48

# define A 97
// # define A 0
# define B 11
# define C 8
# define D 100
// # define D 2
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
# define S 115
// # define S 1
# define T 17
# define U 32
# define V 9
# define W 119
// # define W 13
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

// # define LEFT_ARROW 123
// # define RIGHT_ARROW 124
// # define DOWN_ARROW 125
// # define UP_ARROW 126
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363

#endif
