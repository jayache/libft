/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 10:12:48 by jayache           #+#    #+#             */
/*   Updated: 2019/11/03 10:14:11 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** RETURN THE SUM OF TWO COMPLEX NUMBERS
*/

t_complex	ft_complex_sum(t_complex a, t_complex b)
{
	t_complex result;

	result.real = a.real + b.real;
	result.i = a.i + b.i;
	return (result);
}
