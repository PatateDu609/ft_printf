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

static void		ft_print_prefix(t_flags flags, size_t len)
{
	int		prefix;
	char	pref;

	prefix = 0;
	if (flags.prefix == F_ZERO || flags.prefix == F_ZERO_SPACE)
		pref = '0';
	else if (flags.prefix == F_SPACE)
		pref = ' ';
	while (prefix < flags.length - (int)len)
	{
		write(1, &pref, 1);
		prefix++;
	}
}

void			ft_putunsigned(unsigned int n, int *size, t_flags flags)
{
	int		len;

	len = ft_size(n, 0);
	if (flags.alignment == F_RIGHT)
	{
		ft_print_prefix(flags, len);
		ft_print_nbr(n);
	}
	else if (flags.alignment == F_LEFT)
	{
		ft_print_nbr(n);
		ft_print_prefix(flags, len);
	}
	*size = (len >= flags.length) ? len : flags.length;
}
