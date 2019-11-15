/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:14:16 by gboucett          #+#    #+#             */
/*   Updated: 2019/11/15 17:49:42 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_isformat_or_flag(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
			c == 'u' || c == 'x' || c == 'X' || c == '%' || c == '.' ||
			c == '-' || c == '*' || ft_isdigit(c));
}

static int		ft_parse(const char **str, va_list args)
{
	int printed;

	*str += 1;
	printed = 0;
	while (**str && ft_isformat_or_flag(**str))
	{
		if (**str == 'c' || **str == '%')
			printed += ft_putchar((**str == '%' ? '%' : va_arg(args, int)));
		else if (**str == 's')
			printed += ft_putstr(va_arg(args, char*));
		else if (**str == 'p')
			printed += ft_putptr(va_arg(args, void*));
		else if (**str == 'd' || **str == 'i')
			printed += ft_putnbr(va_arg(args, int));
		else if (**str == 'x' || **str == 'X')
			ft_puthexa(**str == 'x', va_arg(args, unsigned int), &printed);
		else if (**str == 'u')
			ft_putunsigned(va_arg(args, unsigned int), &printed);
		if (**str == 'x' || **str == 'u')
			printed++;
		*str += 1;
		if (**str == '%')
			break ;
	}
	return (printed);
}

int				ft_printf(const char *str, ...)
{
	va_list		args;
	int			printed;

	va_start(args, str);
	printed = 0;
	while (*str)
	{
		if (*str == '%')
			printed += ft_parse(&str, args);
		else
			printed += write(1, str++, 1);
	}
	va_end(args);
	return (printed);
}
