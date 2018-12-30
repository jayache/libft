/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 23:00:44 by jayache           #+#    #+#             */
/*   Updated: 2018/12/30 16:42:31 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t x;
	size_t j;

	x = 0;
	if (needle[0] == '\0')
		return (haystack);
	while (haystack[x] && len)
	{
		j = 0;
		while (haystack[x + j] == needle[j])
		{
			++j;
			if (!needle[j])
				return (haystack + x);
			if (!haystack[x + j])
				return (NULL);
			if (len - j <= 0)
				return (NULL);
		}
		++x;
		--len;
	}
	return (NULL);
}
