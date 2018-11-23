/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:53:06 by jayache           #+#    #+#             */
/*   Updated: 2018/11/10 12:26:00 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "libft.h"

void	ft_strclr(char *s)
{
	int x;

	x = 0;
	if (!s)
		return ;
	while (s[x])
	{
		s[x] = '\0';
		++x;
	}
}
