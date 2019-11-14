SRCS				= ft_puthexa.c \
						ft_putptr.c \
						ft_printf.c \
						ft_putchar.c \
						ft_putstr.c \
						ft_putunsigned.c \
						ft_putnbr.c
OBJS				= ${SRCS:.c=.o}
GCC					= gcc
NAME				= libftprintf.a
RM					= rm -f
LIBFT_PATH			= libft
LIBFT_MAKE			= libft_makefile
LIBFT				= ${LIBFT_PATH}/libft.a
CFLAGS				= -Wall -Wextra -Werror -I${LIBFT_PATH}

.c.o:
					${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):			${OBJS} ${LIBFT}
					ar rc ${NAME} ${OBJS}
					ranlib ${NAME}

${LIBFT}:
					make -C ${LIBFT_PATH} -f ${LIBFT_MAKE}
					mv ${LIBFT} ${NAME}

all:				${NAME}

clean:
					${RM} ${OBJS} ${BONUSOBJS}
					make -C ${LIBFT_PATH} -f ${LIBFT_MAKE} clean

fclean:				clean
					${RM} ${NAME}
					make -C ${LIBFT_PATH} -f ${LIBFT_MAKE} fclean

re:					fclean all

.PHONY:				all clean fclean re
