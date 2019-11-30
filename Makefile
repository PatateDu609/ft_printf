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
EXTENSION			=	.c
EXTENSION_BONUS		=	_bonus.c

SRCS_COMMON			=	ft_flags		\
						ft_puthexa		\
						ft_putnbr		\
						ft_check_parse	\
						ft_nbr_utils

SRCS_BASENAME_ONLY	=	ft_putptr		\
						ft_printf		\
						ft_putchar		\
						ft_putstr		\
						ft_putunsigned

SRCS_BONUS_BN_ONLY	=


################################################################################
#                             Commands and arguments                           #
################################################################################
RM					=	rm -f
GCC					=	gcc
CFLAGS				=	-Wall -Wextra -Werror -I$(LIBFT_PATH)

################################################################################
#                         DO NOT MODIFY BELOW THIS POINT                       #
################################################################################
SRCS_BASENAME		= $(SRCS_BASENAME_ONLY) $(SRCS_COMMON)
SRCS_BONUS_BASENAME		= $(SRCS_BONUS_BN_ONLY) $(SRCS_COMMON)

SRCS_EXT			=	$(addsuffix $(EXTENSION), $(SRCS_BASENAME))
SRCS_BONUS_EXT		=	$(addsuffix $(EXTENSION_BONUS), $(SRCS_BONUS_BASENAME))

SRCS_COMMON_EXT		=	$(addsuffix .o, $(SRCS_COMMON))
SRCS_COMMON_WPATH	=	$(addprefix $(PATH_SRCS)/, $(SRCS_COMMON_EXT))

SRCS				=	$(addprefix $(PATH_SRCS)/, $(SRCS_EXT))
OBJS				=	$(addprefix $(PATH_OBJS)/, $(SRCS_EXT:.c=.o))
OBJS_BONUS			=	$(addprefix $(PATH_OBJS)/, $(SRCS_BONUS_EXT:.c=.o))

$(PATH_OBJS)/%.o:	$(PATH_SRCS)/%.c
					$(GCC) $(CFLAGS) -c $< -o $@

$(NAME):			$(OBJS) $(LIBFT)
					ar rc $(NAME) $(OBJS)
					ranlib $(NAME)

$(LIBFT):
					make -C $(LIBFT_PATH) -f $(LIBFT_MAKE)
					mv $(LIBFT) $(NAME)

all:				$(NAME)

clean:
					$(RM) $(OBJS) $(OBJS_BONUS)
					make -C $(LIBFT_PATH) -f $(LIBFT_MAKE) clean

fclean:				clean
					$(RM) $(NAME)
					make -C $(LIBFT_PATH) -f $(LIBFT_MAKE) fclean

bonus:				$(OBJS_BONUS)
					ar d $(NAME) $(SRCS_COMMON_WPATH)
					ar rc $(NAME) $(OBJS_BONUS)

re:					fclean all

.PHONY:				all clean fclean re
