/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_mult.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 10:10:03 by jayache           #+#    #+#             */
/*   Updated: 2019/11/11 11:09:04 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** RETURN THE PRODUCT OF TWO COMPLEX NUMBERS
*/

t_complex	ft_complex_product(t_complex a, t_complex b)
{
	t_complex result;

	result.real = a.real * b.real - a.i * b.i;
	result.i = a.i * b.real + b.i * a.real;
	return (result);
}
