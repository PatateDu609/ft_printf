/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 18:09:24 by gboucett          #+#    #+#             */
/*   Updated: 2019/11/18 19:34:48 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// static void		ft_print_nbr(int mode, unsigned long n)
// {
// 	if (n / 16)
// 		ft_print_nbr(mode, n / 16);
// 	ft_putchar_fd(
// 		(mode ? "0123456789abcdef"[n % 16] : "0123456789ABCDEF"[n % 16]), 1);
// }

void			ft_puthexa(int mode, unsigned long n, int *size, t_flags flags)
{
	(void)mode;
	(void)n;
	(void)size;
	(void)flags;
}
