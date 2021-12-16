NAME			:= so_long
NAME_BONUS		:= so_long_bonus

CC 				:= clang

RM 				:= rm -rf

CFLAGS 			:= -Wall -Wextra -Werror -g
MLXFLAGS		:= -lmlx -Imlx -lXext -lX11

PATH_SRC 		:= ./src/
PATH_SRC_BONUS	:= ./src_bonus/

SRCS 		:= ${addprefix ${PATH_SRC}, \
							so_long.c \
							generate.c \
							initiate.c \
							validate.c \
							error.c \
							finish.c \
							render.c \
							movement.c}

SRCS_BONUS	:= ${addprefix ${PATH_SRC_BONUS}, \
							so_long_bonus.c \
							generate_bonus.c \
							initiate_bonus.c \
							validate_bonus.c \
							error_bonus.c \
							finish_bonus.c \
							render_bonus.c \
							movement_bonus.c}

PATH_LIBFT	:= 	./libraries/libft/
LIBFT		:= 	${PATH_LIBFT}libft.a

OBJS 		:= 	${SRCS:.c=.o}
OBJS_BONUS	:= 	${SRCS_BONUS:.c=.o}

all: 			$(NAME)
bonus:			${NAME_BONUS}

$(NAME): 		${LIBFT} $(OBJS)
				${CC} ${CFLAGS} ${SRCS} -lft -o ${NAME} -L ${PATH_LIBFT} ${MLXFLAGS}

$(NAME_BONUS): 	${LIBFT} $(OBJS_BONUS)
				${CC} ${CFLAGS} ${SRCS_BONUS} -lft -o ${NAME_BONUS} -L ${PATH_LIBFT} ${MLXFLAGS}

${LIBFT}:
				${MAKE} -C ${PATH_LIBFT} bonus
				${MAKE} -C ${PATH_LIBFT} clean

clean:
				${RM} ${OBJS} ${OBJS_BONUS}

fclean: 		clean
				${RM} ${NAME} ${NAME_BONUS}

re: 			fclean all

.PHONY:			all clean fclean re
