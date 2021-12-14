INCLUDEFT := ./libraries/libft 
INCLUDEMLX := ./libraries/mlx_linux
MLXPATH := ./libraries/mlx_linux
FTPATH := ./libraries/libft
LIBRARIES := -lft -lmlx -lX11 -lm -lz -lXext
CC ?= clang
SRCS := so_long.c generate.c initiate.c validate.c error.c finish.c render.c movement.c
CFLAGS ?= -Wall -Werror -Wextra -g3
LEAKS := valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes
MYMAIN ?=
MAP ?=
EXEC = ${SRCS:.c=.out}

lib:
	${MAKE} -C ${FTPATH} bonus
	${MAKE} -C ${FTPATH} clean

clib:
	${MAKE} -C ${FTPATH} fclean

so_long:
	${CC} ${CFLAGS} ${SRCS} ${LIBRARIES} -o so_long.out -I ${INCLUDEFT} -I ${INCLUDEMLX} -L ${FTPATH} -L ${MLXPATH} && ${LEAKS} ./so_long.out ${MAP}

clean:
	${RM} ${EXEC}

.PHONY:	so_long
