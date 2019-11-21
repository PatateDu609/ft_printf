/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:33:57 by gboucett          #+#    #+#             */
/*   Updated: 2019/11/21 16:16:45 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void		ft_print_signed(int n, int len, int precision, int sign)
{
	if (n < 0 && sign)
		ft_putchar_fd('-', 1);
	ft_print_zeroes((n < 0) ? len - 1 : len, precision);
	if (precision != 0 || n != 0)
		ft_print_nbr((n < 0 ? -n : n));
}

static void		ft_print_pref(t_flags flags, int len, int n)
{
	if (!flags.length_def && !flags.precision && !n)
		len = 0;
	ft_print_prefix(flags, len);
}

static int		ft_result(int precision, int n, t_flags flags, int len)
{
	if (precision == 0 && n == 0)
		return (flags.length_def ? 0 : flags.length);
	if (len >= precision)
		return ((flags.length <= len) ? len : flags.length);
	else
		return ((n < 0) +
				(precision <= flags.length ? flags.length : precision));
}

int				ft_putnbr(int n, t_flags flags)
{
	int				len;
	unsigned int	nbr;
	int				precision;

	precision = (flags.precision == F_DEF_PREC) ? 1 : flags.precision;
	nbr = (n < 0) ? -n : n;
	len = ft_size_base(nbr, ((n < 0) ? 1 : 0), 10);
	if (flags.alignment == F_RIGHT)
	{
		if (flags.prefix == F_ZERO && n < 0)
			ft_putchar_fd('-', 1);
		ft_print_pref(flags, len, n);
		ft_print_signed(n, len, precision, !(flags.prefix == F_ZERO && n < 0));
	}
	else if (flags.alignment == F_LEFT)
	{
		ft_print_signed(n, len, precision, 1);
		ft_print_pref(flags, len, n);
	}
	return (ft_result(precision, n, flags, len));
}
