include config/parsing_srcs.mk
include config/init_srcs.mk
include config/draw_srcs.mk
include config/dhook_srcs.mk
include config/error_srcs.mk

NAME	= cube3d

HEADER	= 	include/cube3d.h		\
			src/init/init.h			\
			src/parsing/parsing.h	\
			src/dhook/dhook.h		\
			src/draw/draw.h			\
			src/error/error.h		\
			mlx/mlx.h				\
			mlx/mlx_new_window.h	\
			mlx/mlx_int.h			\
			mlx/mlx_opengl.h		\
			mlx/mlx_png.h			\
			libft2/include/gc.h		\
			libft2/include/libft.h	\

LIBFT	= libft2

MLX		= mlx

INCLUDES= ${addprefix -I, ${sort ${dir ${HEADER}}}}

SRCS	+=	src/main.c


OBJS	= ${SRCS:.c=.o}
CC		= gcc
CFLAGS	= -fsanitize=address -g3 -Wall -Werror -Wextra -O2
LIBFLAGS= -framework OpenGL -framework AppKit

all: maker ${NAME}

%.o : %.c	${HEADER}
			${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

${NAME}: ${OBJS} libft2/libft2.a mlx/libmlx.a
		${CC} ${CFLAGS} ${OBJS} ${LIBFLAGS} ${INCLUDES} -o $@ libft2/libft2.a mlx/libmlx.a

maker:
		${MAKE} -C ${LIBFT}
		${MAKE}	-C ${MLX}
clean:
		rm -f ${OBJS}
		${MAKE} clean -C ${LIBFT}
		${MAKE} clean -C ${MLX}
fclean:	clean
		rm -f ${NAME}
		${MAKE} fclean -C ${LIBFT}
		${MAKE} clean -C ${MLX}
re:		fclean all
.PHONY: all clean fclean re maker
