# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/15 15:25:50 by dpeyrat           #+#    #+#              #
#    Updated: 2022/11/24 14:17:52 by dopeyrat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= fract_ol.c fract_ol_utils.c display.c hooks.c iterate.c find_fractal.c

OBJS	= ${SRCS:.c=.o}

NAME	= fractol

LIBFT	= LIBFT/libft.a

CFLAGS	= -Wall -Wextra -Werror -O3 -O2 -Os 

MLXFLAGS	= -Lmlx -lmlx -framework OpenGL -framework Appkit

MLX		= libmlx.dylib

CC		= gcc

all:		${NAME}

%.o:		%.c
	${CC} ${CFLAGS} -Imlx -c $< -o $@

${LIBFT}:
	make -C LIBFT

${NAME}:	${OBJS} ${LIBFT}
	make -C mlx
	cp mlx/libmlx.dylib ./
	${CC} ${CFLAGS} ${MLXFLAGS} ${OBJS} ${LIBFT} ${MLX} -o ${NAME}

clean:
	rm -f ${OBJS}
	make clean -C LIBFT

fclean:		clean
	rm -f ${NAME}
	rm -f ${MLX}
	make fclean -C LIBFT
	make clean -C mlx

re:			fclean all

.PHONY:		re clean fclean bonus

