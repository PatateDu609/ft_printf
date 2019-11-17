/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:55:17 by gboucett          #+#    #+#             */
/*   Updated: 2019/11/17 20:45:57 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

int		ft_putptr(void *ptr)
{
	unsigned long	p;
	int				result;

	p = (unsigned long)ptr;
	result = 0;
	ft_putstr_fd("0x", 1);
	ft_puthexa(1, p, &result);
	return (result + 1);
}
