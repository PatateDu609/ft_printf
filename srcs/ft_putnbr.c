/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:33:57 by gboucett          #+#    #+#             */
/*   Updated: 2019/11/18 23:31:33 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_print_signed(int n, int len, int precision, int sign)
{
	if (n < 0 && sign)
		ft_putchar_fd('-', 1);
	ft_print_zeroes(len - (n < 0 ? 1 : 0), precision);
	if (precision != 0 || n != 0)
		ft_print_nbr((n < 0 ? -n : n));
}
#include <stdio.h>
int		ft_putnbr(int n, t_flags flags)
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
		ft_print_prefix(flags, len);
		ft_print_signed(n, len, precision, !(flags.prefix == F_ZERO && n < 0));
	}
	else if (flags.alignment == F_LEFT)
	{
		ft_print_signed(n, len, precision, 1);
		ft_print_prefix(flags, len);
	}
	if (precision == 0 && n == 0)
		return (0);
	if (len >= precision)
		return ((flags.length <= len) ? len : flags.length);
	else if (n >= 0)
		return (precision <= flags.length ? flags.length : precision);
	else
		return ((precision <= flags.length ? flags.length : precision) + 1);
}
