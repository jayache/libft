/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:56:30 by jayache           #+#    #+#             */
/*   Updated: 2018/12/30 17:35:53 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** CONVERTS NB IN AN UNSIGNED DIGIT OF SIZE BASE
** MAX BASE (CURRENT) IS 16
** RETURN NULL ON FAILURE
*/

static size_t	nblen_base(uintmax_t nb, unsigned int base)
{
	size_t x;

	x = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= base;
		++x;
	}
	return (x);
}

char		*ft_itoa_base(intmax_t nb, unsigned int base)
{
	char		*str;
	size_t		c;
	size_t		s;
	uintmax_t	nbs;

	nbs = ft_abs(nb);
	s = nblen_base(nbs, base);
	c = 0;
	if (base > 16 || base < 2)
		return (NULL);
	str = ft_strnew(s);
	if (nb == 0)
		str[c++] = '0';
	while (nbs > 0)
	{
		str[s - c - 1] = "0123456789ABCDEF"[ft_abs(nbs % base)];
		nbs /= base;
		++c;
	}
	str[c] = '\0';
	return (str);
}
