/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:33:57 by gboucett          #+#    #+#             */
/*   Updated: 2019/11/14 20:33:59 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnbr(int n)
{
	int				result;
	unsigned int	nbr;

	result = 1;
	nbr = (n < 0) ? -n : n;
	if (n < 0)
		result += ft_putchar('-');
	ft_putunsigned(nbr, &result);
	return (result);
}
