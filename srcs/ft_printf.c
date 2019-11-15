/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:14:16 by gboucett          #+#    #+#             */
/*   Updated: 2019/11/15 21:46:14 by gboucett         ###   ########.fr       */
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

static t_flags		ft_parse(const char **str)
{
	t_flags		flags;
	int			waiting;

	*str += 1;
	flags = (t_flags){ 0, 1, 0 };
	waiting = 1;
	while (**str && ft_isformat_or_flag(**str))
	{
		if (!flags.prefix && (**str == '0' || **str == ' '))
			flags.prefix = (**str == '0') ? 1 : 2;
		else if (!flags.alignment && **str == '-')
			flags.alignment = 1;
		else if (waiting != 0 && !ft_isdigit(**str))
			waiting = 0;
		else if ((waiting == 1 || waiting == 3) && **str == '.')
			waiting = 2;
		else if (waiting == 1 && ft_isdigit(**str))
		{
			flags.length = ft_flag_numbers(str);
			waiting = 3;
		}
		else if (waiting == 2 && ft_isdigit(**str))
		{
			flags.precision = ft_flag_numbers(str);
			waiting = 0;
		}
	}
	printf("%s\n", *str);
	printf("end of ft_parse.\n");
	return (flags);
}

int					ft_printf(const char *str, ...)
{
	va_list		args;
	int			printed;

	va_start(args, str);
	printed = 0;
	if (*str)
	{
		if (*str == '%')
			ft_parse(&str);
		else
			printed += write(1, str++, 1);
	}
	va_end(args);
	return (printed);
}
