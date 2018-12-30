/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:19:21 by jayache           #+#    #+#             */
/*   Updated: 2018/12/30 17:02:41 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, unsigned char c, size_t n)
{
	size_t x;

	x = 0;
	while (x < n)
	{
		((unsigned char*)dst)[x] = ((unsigned const char*)src)[x];
		if (((unsigned const char*)src)[x] == c)
			return ((unsigned char*)dst + x + 1);
		++x;
	}
	return (NULL);
}
