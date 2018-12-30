/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:48:06 by jayache           #+#    #+#             */
/*   Updated: 2018/12/30 18:05:45 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** PRINTS A %
*/

void		ft_printf_putpercent(t_arg arg, t_buffer *buf, va_list *ap)
{
	long	i;

	arg.str = ft_strnew(2);
	arg.str[0] = '%';
	arg.str[1] = '\0';
	i = paddingspace(arg, buf);
	printf_putchar(buf, '%');
	i += reverse_padding(arg, buf, (int)i + 1);
	free_arg(&arg);
	ap = NULL;
}

/*
** PRINTS A UNSIGNED OCTAL
*/

void		ft_printf_putoct(t_arg arg, t_buffer *buf, va_list *ap)
{
	uintmax_t	i;
	int			size;
	intmax_t	c;

	i = take_unsigned_arg(arg, ap);
	arg.str = ft_itoa_base((intmax_t)i, 8);
	c = paddingspace(arg, buf);
	c += hashflag(arg, buf, arg.str);
	size = print_arg_oct(arg, buf, arg.str);
	c += reverse_padding(arg, buf, (int)c + size);
	free_arg(&arg);
}

void		ft_printf_putuns(t_arg arg, t_buffer *buf, va_list *ap)
{
	uintmax_t	i;
	int			s;
	intmax_t	c;

	i = take_unsigned_arg(arg, ap);
	arg.str = ft_itoa_base((intmax_t)i, 10);
	c = paddingspace(arg, buf);
	c += paddingzeros(arg, buf);
	s = 0;
	while (arg.str[s])
		printf_putchar(buf, arg.str[s++]);
	c += reverse_padding(arg, buf, (int)c + (int)ft_strlen(arg.str));
	free_arg(&arg);
}

void		ft_printf_puthexa(t_arg arg, t_buffer *buf, va_list *ap)
{
	uintmax_t	i;
	int			size;
	intmax_t	c;

	i = take_unsigned_arg(arg, ap);
	arg.str = ft_itoa_base((intmax_t)i, 16);
	c = 0;
	if (ft_strchr(arg.flags, '0'))
		c = hashflag(arg, buf, arg.str);
	c += paddingspace(arg, buf);
	if (!ft_strchr(arg.flags, '0'))
		c += hashflag(arg, buf, arg.str);
	if (arg.type == 'x' || arg.type == 'p')
		ft_striter(arg.str, &ptolower);
	size = print_arg_hexa(arg, buf, arg.str);
	c += reverse_padding(arg, buf, (int)c + size);
	free_arg(&arg);
}
