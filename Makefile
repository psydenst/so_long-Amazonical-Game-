NAME = so_long
LIBFT_DIR = ./libs/libft
MLX_DIR = ./mlx
GNL_DIR = ./libs/get_next_line
SRC =	src/create_map.c \
		src/create_map2.c \
		src/main.c \
		src/validate_map.c \
		src/key_events.c \
		src/asdw.c


CC = gcc
SRC_GNL =	${GNL_DIR}/get_next_line.c \
			${GNL_DIR}/get_next_line_utils.c \

OBJ = ${SRC:.c=.o}
OBJ_GNL = ${SRC_GNL:.c=.o}

all: $(NAME)

$(NAME):	${OBJ} ${OBJ_GNL}
			make -C ${LIBFT_DIR}
			make -C ${MLX_DIR}
			${CC} ${OBJ} ${OBJ_GNL} -Lmlx -lmlx ${LIBFT_DIR}/libft.a ${MLX_DIR}/libmlx.a -framework OpenGL -framework AppKit -o ${NAME}

%.o:	%.c
		$(CC) -Wall -Wextra -Werror -Imlx -g -c $< -o $@

clean:	all
		make clean -C ${LIBFT_DIR}
		make clean -C ${MLX_DIR}
		rm -rf ${GNL_DIR}/*.o
		rm -rf ./src/*.o
	   	${RM} ${OBJ}

fclean: clean
		rm  ${LIBFT_DIR}/libft.a
		rm ${MLX_DIR}/libmlx.a
		rm ${NAME}

re:		clean all

.PHONY: all clean fclean re bonus





