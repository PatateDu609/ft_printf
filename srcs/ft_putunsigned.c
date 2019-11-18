/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:34:15 by gboucett          #+#    #+#             */
/*   Updated: 2019/11/18 22:24:33 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void			ft_putunsigned(unsigned int n, int *size, t_flags flags)
{
	int		len;
	int		precision;

	precision = (flags.precision == F_DEF_PREC) ? 1 : flags.precision;
	len = ft_size_base(n, 0, 10);
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
