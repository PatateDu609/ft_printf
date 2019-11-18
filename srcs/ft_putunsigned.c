/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:34:15 by gboucett          #+#    #+#             */
/*   Updated: 2019/11/17 23:51:16 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int		ft_size(unsigned int n, size_t size)
{
	if (n == 0 && !size)
		return (1);
	else if (n == 0)
		return (size);
	return (ft_size(n / 10, size + 1));
}

static void		ft_print_nbr(unsigned int n)
{
	if (n / 10)
		ft_print_nbr(n / 10);
	ft_putchar_fd(n % 10 + '0', 1);
}

static void		ft_print_prefix(t_flags flags, int len)
{
	int		prefix;
	char	pref;
	int		size;
	int		precision;

	precision = (flags.precision == F_DEF_PREC) ? 1 : flags.precision;
	if (len >= precision)
		size = (flags.length <= len) ? len : flags.length;
	else
		size = (precision <= flags.length) ? flags.length : precision;
	prefix = 0;
	pref = ' ';
	while (prefix < size - (precision < len ? len : precision))
	{
		write(1, &pref, 1);
		prefix++;
	}
}

static void		ft_print_zeroes(int len, int precision)
{
	int		zeroes;

	zeroes = 0;
	while (zeroes < precision - len)
	{
		write(1, "0", 1);
		zeroes++;
	}
}

void			ft_putunsigned(unsigned int n, int *size, t_flags flags)
{
	int		len;
	int		precision;

	precision = (flags.precision == F_DEF_PREC) ? 1 : flags.precision;
	len = ft_size(n, 0);
	if (flags.alignment == F_RIGHT)
	{
		ft_print_prefix(flags, len);
		ft_print_zeroes(len, precision);
		if (precision != 0 || n != 0)
			ft_print_nbr(n);
	}
	else if (flags.alignment == F_LEFT)
	{
		ft_print_zeroes(len, precision);
		if (precision != 0 || n != 0)
			ft_print_nbr(n);
		ft_print_prefix(flags, len);
	}
	if (precision == 0 && n == 0)
		*size = 0;
	else if (len >= precision)
		*size = (flags.length <= len) ? len : flags.length;
	else
		*size = (precision <= flags.length) ? flags.length : precision;
}
