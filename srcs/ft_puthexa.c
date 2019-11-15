/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 18:09:24 by gboucett          #+#    #+#             */
/*   Updated: 2019/11/12 18:09:30 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthexa(int mode, unsigned long n, int *size)
{
	char	*min;
	char	*maj;

	min = "0123456789abcdef";
	maj = "0123456789ABCDEF";
	if (n / 16)
	{
		*size += 1;
		ft_puthexa(mode, n / 16, size);
	}
	ft_putchar_fd((mode ? min[n % 16] : maj[n % 16]), 1);
}
