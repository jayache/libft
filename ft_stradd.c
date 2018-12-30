/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 14:55:36 by jayache           #+#    #+#             */
/*   Updated: 2018/12/30 16:49:47 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stradd(char **str, char c)
{
	size_t	s;
	char	*result;
	char	*sc;

	sc = ft_strnew(1);
	sc[0] = c;
	s = ft_strlen(*str);
	result = ft_strjoin(sc, *str);
	free(*str);
	free(sc);
	*str = result;
}
