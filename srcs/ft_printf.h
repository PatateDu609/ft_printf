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
**	alignment	: right (0) or left (1)
**	length		: maximal / minimal length (it depends of the context)
**	precision	: precision in float
**	prefix		: is there any prefix (space or zero) ?
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

int				ft_printf(const char *str, ...);

#endif
