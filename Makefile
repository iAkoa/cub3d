include config/parsing_srcs.mk
include config/init_srcs.mk
include config/draw_srcs.mk
include config/dhook_srcs.mk
include config/error_srcs.mk
include config/engine_srcs.mk

NAME    = cub3D

HEADER    =     include/cub3d.h        \
			src/init/init.h            \
			src/parsing/parsing.h    \
			src/dhook/dhook.h        \
			src/draw/draw.h            \
			src/engine/engine.h    \
			mlx/mlx.h                \
			mlx/mlx_new_window.h    \
			mlx/mlx_int.h            \
			mlx/mlx_opengl.h        \
			mlx/mlx_png.h            \
			libft2/include/gc.h        \
			libft2/include/libft.h    \

LIBFT    = libft2

UNAME_S = $(shell uname -s)


	MLX_DIR        =    ./mlx/
	MLX_FLAGS    =    -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz
	MLX_CCFLAGS    =    -I/usr/include -Imlx -O3

INCLUDES= ${addprefix -I, ${sort ${dir ${HEADER}}}}

SRCS    +=    src/main.c


OBJS    = ${SRCS:.c=.o}
CC        = gcc
CFLAGS    = -O3 -Iinclude -g3

all: maker ${NAME}

%.o : %.c    ${HEADER}  libft2/libft2.a $(MLX_DIR)/libmlx.a Makefile
		${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

${NAME}: ${OBJS}
		$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -lm $(MLX_DIR)libmlx.a $(LIBFT)/libft2.a -o $(NAME)

maker:
		@${MAKE} -C ${LIBFT}
		@${MAKE}    -C ${MLX_DIR} 1>/dev/null
clean:
		rm -f ${OBJS}
		${MAKE} clean -C ${LIBFT}
		${MAKE} clean -C ${MLX_DIR}
fclean:    clean
		rm -f ${NAME}
		${MAKE} fclean -C ${LIBFT}
		${MAKE} clean -C ${MLX_DIR}
re:        fclean all
.PHONY: all clean fclean re makerls
