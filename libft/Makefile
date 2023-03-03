SRCS	=  	ft_bzero.c \
			ft_calloc.c \
			ft_memcpy.c \
			ft_strdup.c \
			ft_strlen.c \
			ft_putchar.c \
			ft_putstr_fd.c \
			ft_strjoin.c \
			ft_strchr.c \
			ft_strncmp.c \
			gnl.c \
			ft_split.c \
			ft_substr.c \
			ft_printf.c

OBJS	= ${SRCS:.c=.o}


NAME 	= libft.a

.c.o:
			gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
				ar rc ${NAME} ${OBJS}

bonus:		$(OBJS)
				ar rc ${NAME} ${OBJS}

all:		${NAME}

clean:		
				rm -f ${OBJS}

fclean:		clean
				rm -f ${NAME}

re: 		fclean clean all re