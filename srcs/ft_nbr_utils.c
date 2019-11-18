/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 22:24:55 by gboucett          #+#    #+#             */
/*   Updated: 2019/11/18 22:29:39 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_size_base(unsigned int n, size_t size, int base)
{
	if (n == 0 && !size)
		return (1);
	else if (n == 0)
		return (size);
	return (ft_size_base(n / base, size + 1, base));
}

void	ft_print_nbr(unsigned int n)
{
	if (n / 10)
		ft_print_nbr(n / 10);
	ft_putchar_fd(n % 10 + '0', 1);
}

void	ft_print_prefix(t_flags flags, int len)
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
	if ((flags.prefix == F_ZERO || flags.prefix == F_ZERO_SPACE)
		&& flags.precision == F_DEF_PREC)
		pref = '0';
	else
		pref = ' ';
	while (prefix < size - (precision < len ? len : precision))
	{
		write(1, &pref, 1);
		prefix++;
	}
}

void	ft_print_zeroes(int len, int precision)
{
	int		zeroes;

	zeroes = 0;
	while (zeroes < precision - len)
	{
		write(1, "0", 1);
		zeroes++;
	}
}
