/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:42:36 by gboucett          #+#    #+#             */
/*   Updated: 2019/11/17 15:08:29 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void				ft_prefix(t_flags *flags, char current)
{
	if (flags->prefix == F_NO_PREFIX)
	{
		if (current == '0' && flags->alignment == F_RIGHT)
			flags->prefix = F_ZERO;
		else if (current == ' ')
			flags->prefix = F_SPACE;
	}
	else if (flags->prefix == F_ZERO && current == ' ')
		flags->prefix = (flags->alignment == F_LEFT) ? F_SPACE : F_ZERO_SPACE;
	else if (flags->prefix == F_SPACE && current == '0'
			&& flags->alignment == F_RIGHT)
		flags->prefix = F_ZERO_SPACE;
	else if (current == '-' && (flags->prefix == F_ZERO_SPACE
			|| flags->prefix == F_ZERO))
		flags->prefix = (flags->prefix == F_ZERO) ? F_NO_PREFIX : F_SPACE;
}

void			ft_alignment(t_flags *flags)
{
	if (flags->alignment == F_RIGHT)
	{
		flags->alignment = F_LEFT;
		ft_prefix(flags, '-');
	}
}

void	ft_flag_numbers(t_flags *flags, const char **str, int *waiting)
{
	int		result;

	result = ft_atoi(*str);
	while (**str && ft_isdigit(**str))
		*str += 1;
	if (*waiting == W_LENGTH)
	{
		flags->length = result;
		*waiting = W_PRECISION;
	}
	else if (*waiting == W_PRECISION)
	{
		flags->precision = result;
		*waiting = W_NOTHING;
	}
}

void			ft_star(t_flags *flags, int *waiting, int number)
{
	if (*waiting == W_LENGTH)
	{
		flags->length = number;
		*waiting = W_PRECISION;
	}
	else if (*waiting == W_PRECISION)
	{
		flags->precision = number;
		*waiting = W_NOTHING;
	}
}

int		ft_print(t_flags flags, va_list args)
{
	int result;
	(void) flags;
	(void) args;
	result = 4;
	return (result);
}
