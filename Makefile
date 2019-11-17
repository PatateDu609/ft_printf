################################################################################
#                               Name of the output                             #
################################################################################
NAME				=	libftprintf.a

################################################################################
#                          Paths of sources and objects                        #
################################################################################
PATH_SRCS			=	srcs
PATH_OBJS			=	objs

################################################################################
#                                 Libft's infos                                #
################################################################################
LIBFT_PATH			=	libft
LIBFT_MAKE			=	libft_makefile
LIBFT				=	${LIBFT_PATH}/libft.a

################################################################################
#                              Name of sources files                           #
################################################################################
SRCS_BASENAME		=	ft_puthexa.c		\
						ft_putptr.c			\
						ft_printf.c			\
						ft_putchar.c		\
						ft_putstr.c			\
						ft_putunsigned.c	\
						ft_putnbr.c			\
						ft_flags.c			\
						ft_check_parse.c

################################################################################
#                             Commands and arguments                           #
################################################################################
RM					=	rm -f
GCC					=	gcc
CFLAGS				=	-Wall -Wextra -Werror -I${LIBFT_PATH}

################################################################################
#                         DO NOT MODIFY BELOW THIS POINT                       #
################################################################################
SRCS				=	$(addprefix ${PATH_SRCS}/, ${SRCS_BASENAME})
OBJS				=	$(addprefix ${PATH_OBJS}/, ${SRCS_BASENAME:.c=.o})

$(PATH_OBJS)/%.o:	$(PATH_SRCS)/%.c
					${GCC} ${CFLAGS} -c $< -o $@

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
