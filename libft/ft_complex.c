/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 10:17:10 by jayache           #+#    #+#             */
/*   Updated: 2019/11/03 10:18:34 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** RETURN A NEW COMPLEX NUMBER
*/

t_complex	ft_complex(double real, double i)
{
	t_complex result;

	result.real = real;
	result.i = i;
	return (result);
}
