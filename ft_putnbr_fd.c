/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:07:25 by jayache           #+#    #+#             */
/*   Updated: 2018/12/30 17:22:35 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "libft.h"

void	ft_putnbr_fd(long nb, int fd)
{
	uintmax_t snb;

	snb = ft_abs(nb);
	if (ft_sign(nb) < 0)
		ft_putchar_fd('-', fd);
	if (snb < 10)
		ft_putchar_fd((char)snb + '0', fd);
	else
	{
		ft_putnbr_fd(snb / 10, fd);
		ft_putnbr_fd(snb % 10, fd);
	}
}
