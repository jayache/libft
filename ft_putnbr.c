/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:07:25 by jayache           #+#    #+#             */
/*   Updated: 2018/12/30 17:22:59 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "libft.h"

void	ft_putnbr(long nb)
{
	uintmax_t snb;

	snb = ft_abs(nb);
	if (ft_sign(nb) < 0)
		ft_putchar('-');
	if (snb < 10)
		ft_putchar((unsigned char)snb + '0');
	else
	{
		ft_putnbr(snb / 10);
		ft_putnbr(snb % 10);
	}
}
