/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 12:44:53 by jayache           #+#    #+#             */
/*   Updated: 2018/12/30 17:41:30 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "libft.h"

int	ft_atoi(const char *str)
{
	uintmax_t	nb;
	int			x;
	int			sign;

	sign = 1;
	x = 0;
	nb = 0;
	while (ft_iswhitespace(str[x]))
		x++;
	if (str[x] == '-')
	{
		sign = -1;
		x++;
	}
	else if (str[x] == '+')
		x++;
	while (str[x] >= '0' && str[x] <= '9')
	{
		nb *= 10;
		nb += (uintmax_t)(str[x] - '0');
		++x;
		if (nb > 9223372036854775807)
			return (sign < 0 ? -0 : -1);
	}
	return ((int)((int)nb * sign));
}
