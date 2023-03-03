#*********** VARS **********/

NAME = 			so_long

FLAGS =			-Wall -Wextra -Werror

CC =			gcc

MLX_DIR = 		./mlx

LIBFT_DIR = 	./libft

MLX = 			${MLX_DIR}/libmlx.a	

LIBFT = 		${LIBFT_DIR}/libft.a

RM = 			rm -f


#********** SOURCES ***********/


SRCS =			create_map.c \
				check_map.c \
				render_game.c \
				handle_actions.c \
				utils.c \
				utils1.c\
				so_long.c

OBJS = 			${SRCS:.c=.o}

#INCLUDES = 	-I${MLX_DIR} -I${LIBFT_DIR}
INCLUDE = 		-I${LIBFT_DIR}

#LIBS = 		-L${MLX_DIR} -lmlx -L${LIBFT_DIR} -lft
LIB = 			-L${LIBFT_DIR} -lft

#*********** RULES **********/

%.o: %.c
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}


${NAME}: 	${OBJS} 
			make -C ${LIBFT_DIR}
			${CC} ${OBJS} ${INCLUDE} ${LIB} -lmlx -framework OpenGL -framework AppKit -o ${NAME}

${MLX}:
			make -C ${MLX_DIR}

#${LIBFT}:	make -C ${LIBFT_DIR}

all:		$(NAME)

clean:		
			${RM} ${OBJS}
			make clean -C ${LIBFT_DIR}
#make clean -C ${MLX_DIR}
			

fclean:		clean
			${RM} ${NAME}
			${RM} ${LIBFT}
#${RM} ${MLX}
			

re: 		fclean all	

.PHONY:		fclean clean all re