/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 19:12:17 by gboucett          #+#    #+#             */
/*   Updated: 2019/11/15 21:27:06 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>


/*
**	F_*			: defines about flags' values
**	F_ZERO		: there is some zeroes as prefix
**	F_SPACE		: there is a space as prefix
**	F_ZERO_SIZE	: there is both zeros and space as prefix
**	F_RIGHT		: data is aligned to right
**	F_LEFT		: data is aligned to left
*/
# define F_NO_PREFIX	0
# define F_ZERO			1
# define F_SPACE		2
# define F_ZERO_SPACE	3
# define F_RIGHT		4
# define F_LEFT			5

/*
**	W_*				: defines about waiting states
**	W_NOTHING		: wating for nothing
**	W_LENGTH		: waiting for the length of data
**	W_PRECISION		: waiting for the precision
**	W_FIRST_FLAG	: waiting for members of the first flag
*/
# define W_NOTHING		0
# define W_LENGTH		1
# define W_PRECISION	2
# define W_FIRST_FLAG	3

/*
**	alignment	: right (0) or left (1)
**	length		: maximal / minimal length (it depends of the context)
**	precision	: precision on float
**	prefix		: is there any prefix (zero(1) or space(2) or both(3)) ?
*/
typedef struct	s_flags
{
	int			alignment;
	int			length;
	int			precision;
	int			prefix;
}				t_flags;

void			ft_puthexa(int mode, unsigned long n, int *size);
int				ft_putptr(void *ptr);
int				ft_putchar(char c);
int				ft_putstr(char *c);
int				ft_putnbr(int n);
void			ft_putunsigned(unsigned int n, int *size);

int				ft_flag_numbers(const char **str);
int				ft_isformat_or_flag(char c);
void			ft_prefix(t_flags *flags, char current);
void			ft_alignment(t_flags *flags);
void			ft_length(t_flags *flags, int *waiting, char *str);
void			ft_precision(t_flags *flags, int *waiting, char *str);
void			ft_star(t_flags *flags, int *waiting, int number);
t_flags			ft_parse(const char **str, va_list args);

int				ft_printf(const char *str, ...);

#endif
