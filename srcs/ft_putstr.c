/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:33:41 by gboucett          #+#    #+#             */
/*   Updated: 2019/11/17 18:12:14 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int		ft_special_len(char *str, int precision)
{
	int		len;
	int		true_len;

	len = 0;
	true_len = ft_strlen(str);
	if (precision == F_DEF_PREC)
		precision = true_len;
	while (len < precision && len < true_len)
		len++;
	return (len);
}

static void		ft_disp(int len, char *str, t_flags flags)
{
	int spaces;

	spaces = 0;
	if (flags.alignment == F_RIGHT)
	{
		while (spaces < flags.length - len)
		{
			write(1, " ", 1);
			spaces++;
		}
		write(1, str, len);
	}
	else
	{
		write(1, str, len);
		while (spaces < flags.length - len)
		{
			write(1, " ", 1);
			spaces++;
		}
	}
}

int				ft_putstr(char *str, t_flags flags)
{
	int		len;

	if (flags.precision == 0)
		return (0);
	if (!str)
		str = "(null)";
	len = ft_special_len(str, flags.precision);
	ft_disp(len, str, flags);
	return ((flags.length < len) ? len : flags.length);
}
