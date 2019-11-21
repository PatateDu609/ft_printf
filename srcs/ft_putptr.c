/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:55:17 by gboucett          #+#    #+#             */
/*   Updated: 2019/11/21 16:17:30 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_print_pref(unsigned long n, t_flags flags)
{}
}

int				ft_putptr(void *ptr, t_flags flags)
{
	unsigned long	p;
	int				result;

	p = (unsigned long)ptr;
	ft_putstr_fd("0x", 1);
	ft_puthexa(1, p, &result, flags);
	return (result + 2);
}
