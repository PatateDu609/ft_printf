/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:55:17 by gboucett          #+#    #+#             */
/*   Updated: 2019/11/14 18:55:20 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

int		ft_putptr(void *ptr)
{
	unsigned long	p;
	int				result;

	p = (unsigned long)ptr;
	result = ft_putstr("0x");
	ft_puthexa(1, p, &result);
	return (result + 1);
}
