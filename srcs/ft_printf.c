/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:14:16 by gboucett          #+#    #+#             */
/*   Updated: 2019/11/17 15:10:20 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

// static int		ft_parse(const char **str, va_list args)
// {
// 	int printed;

// 	*str += 1;
// 	printed = 0;
// 	while (**str && ft_isformat_or_flag(**str))
// 	{
// 		if (**str == 'c' || **str == '%')
// 			printed += ft_putchar((**str == '%' ? '%' : va_arg(args, int)));
// 		else if (**str == 's')
// 			printed += ft_putstr(va_arg(args, char*));
// 		else if (**str == 'p')
// 			printed += ft_putptr(va_arg(args, void*));
// 		else if (**str == 'd' || **str == 'i')
// 			printed += ft_putnbr(va_arg(args, int));
// 		else if (**str == 'x' || **str == 'X')
// 			ft_puthexa(**str == 'x', va_arg(args, unsigned int), &printed);
// 		else if (**str == 'u')
// 			ft_putunsigned(va_arg(args, unsigned int), &printed);
// 		if (**str == 'x' || **str == 'u')
// 			printed++;
// 		*str += 1;
// 		if (**str == '%')
// 			break ;
// 	}
// 	return (printed);
// }

static t_flags		ft_parse(const char **str, va_list args)
{
	t_flags		flags;
	int			waiting;

	*str += 1;
	flags = (t_flags){ F_RIGHT, 1, 0, F_NO_PREFIX, 0 };
	waiting = W_FIRST_FLAG;
	while (**str && ft_isformat_or_flag(**str))
	{
		if (waiting == W_FIRST_FLAG && (**str == '0' || **str == ' '))
			ft_prefix(&flags, **str);
		else if (waiting == W_FIRST_FLAG
				&& (flags.alignment == F_RIGHT && **str == '-'))
			ft_alignment(&flags);
		else if (waiting != W_NOTHING && **str == '.')
			waiting = W_PRECISION;
		else if (**str == '*')
			ft_star(&flags, &waiting, va_arg(args, int));
		else if (ft_isformat(**str))
			flags.conversion = **str;
		else if (ft_isdigit(**str))
			ft_flag_numbers(&flags, str, &waiting);
		*str += 1;
	}
	printf("end of ft_parse.\n\n");
	return (flags);
}

int					ft_printf(const char *str, ...)
{
	va_list		args;
	int			printed;
	t_flags		flags;

	va_start(args, str);
	printed = 0;
	if (*str)
	{
		if (*str == '%')
		{
			flags = ft_parse(&str, args);
			printed += ft_print(flags, args);
		}
		else
			printed += write(1, str++, 1);
	}
	va_end(args);
	return (printed);
}
