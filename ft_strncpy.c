/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:27:17 by jayache           #+#    #+#             */
/*   Updated: 2018/12/30 16:43:05 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int x;

	x = 0;
	while (src[x] && len)
	{
		dst[x] = src[x];
		++x;
		--len;
	}
	if (len)
	{
		dst[x] = src[x];
		++x;
		len--;
	}
	while (len--)
		dst[x++] = '\0';
	return (dst);
}
