/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 21:58:35 by jayache           #+#    #+#             */
/*   Updated: 2018/12/30 16:39:32 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "libft.h"
#	include <string.h>

const char	*ft_strrchr(const char *s, int c)
{
	size_t	x;

	x = ft_strlen(s);
	while (x)
	{
		if (s[x] == c)
			break ;
		--x;
	}
	if (s[x] == c)
		return (s + x);
	return (NULL);
}
