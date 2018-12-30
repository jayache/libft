/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:01:58 by jayache           #+#    #+#             */
/*   Updated: 2018/12/30 16:59:21 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const void	*ft_memchr(const void *s, unsigned char c, size_t n)
{
	size_t x;

	x = 0;
	while (x < n)
	{
		if (((unsigned const char*)s)[x++] == (unsigned char)c)
		{
			return ((const char*)s + x - 1);
		}
	}
	return (NULL);
}
