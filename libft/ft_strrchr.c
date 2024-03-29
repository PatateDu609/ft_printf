/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 23:25:35 by gboucett          #+#    #+#             */
/*   Updated: 2019/11/04 23:33:27 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*strr;

	strr = (char*)str + ft_strlen(str);
	while (strr != str && *strr != (char)c)
		strr--;
	return ((*strr != (char)c) ? NULL : strr);
}
