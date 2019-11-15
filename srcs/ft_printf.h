/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 19:12:17 by gboucett          #+#    #+#             */
/*   Updated: 2019/11/15 17:28:17 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_flags
{
	int			type;
	int			precision;
	int			length;
}				t_flags;

void	ft_puthexa(int mode, unsigned long n, int *size);
int		ft_putptr(void *ptr);
int		ft_putchar(char c);
int		ft_putstr(char *c);
int		ft_putnbr(int n);
void	ft_putunsigned(unsigned int n, int *size);

int		ft_printf(const char *str, ...);

#endif
