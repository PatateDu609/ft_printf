/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:33:57 by gboucett          #+#    #+#             */
/*   Updated: 2019/11/17 23:36:10 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnbr(int n, t_flags flags)
{
	int				result;
	unsigned int	nbr;

	result = 1;
	nbr = (n < 0) ? -n : n;
	if (n < 0)
		ft_putchar_fd('-', 1);
	ft_putunsigned(nbr, &result, flags);
	return (result);
}
