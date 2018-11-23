/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:43:35 by jayache           #+#    #+#             */
/*   Updated: 2018/11/18 12:25:57 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "libft.h"

char	*ft_strtrim(char const *s)
{
	char		*str;
	size_t		x;
	int			i;

	if (!s)
		return (NULL);
	i = 0;
	x = ft_cntspfront(s, ' ');
	if (x >= ft_strlen(s) - 1)
		return (ft_strnew(0));
	str = ft_strnew(sizeof(char) * (ft_strlen(s) - x - ft_cntspfront(s, ' ')) + 1);
	if (!str)
		return (NULL);
	while (x < (ft_strlen(s) - ft_cntspback(s, ' ')))
	{
		str[i] = s[x];
		++x;
		++i;
	}
	str[i] = '\0';
	return (str);
}
