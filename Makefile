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
LIBFT				=	$(LIBFT_PATH)/libft.a

################################################################################
#                              Name of sources files                           #
################################################################################
SRCS_BASENAME		=	putptr		\
						printf		\
						putchar		\
						putstr		\
						putunsigned	\
						flags		\
						puthexa		\
						putnbr		\
						check_parse	\
						nbr_utils

################################################################################
#                             Commands and arguments                           #
################################################################################
RM					=	rm -f
GCC					=	gcc
CFLAGS				=	-Wall -Wextra -Werror -I$(LIBFT_PATH)

################################################################################
#                         DO NOT MODIFY BELOW THIS POINT                       #
################################################################################
SRCS_EXT			=	$(addsuffix .c, $(SRCS_BASENAME))

SRCS				=	$(addprefix $(PATH_SRCS)/ft_, $(SRCS_EXT))
OBJS				=	$(addprefix $(PATH_OBJS)/ft_, $(SRCS_EXT:.c=.o))

$(PATH_OBJS)/%.o:	$(PATH_SRCS)/%.c
					$(GCC) $(CFLAGS) -c $< -o $@

$(NAME):			$(OBJS) $(LIBFT)
					ar rc $(NAME) $(OBJS)
					ranlib $(NAME)

$(LIBFT):
					make -C $(LIBFT_PATH) -f $(LIBFT_MAKE)
					make -C $(LIBFT_PATH) -f $(LIBFT_MAKE) bonus
					mv $(LIBFT) $(NAME)

all:				$(NAME)

clean:
					$(RM) $(OBJS)
					make -C $(LIBFT_PATH) -f $(LIBFT_MAKE) clean

fclean:				clean
					$(RM) $(NAME)
					make -C $(LIBFT_PATH) -f $(LIBFT_MAKE) fclean

re:					fclean all

.PHONY:				all clean fclean re
