/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_abs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 10:31:42 by jayache           #+#    #+#             */
/*   Updated: 2019/11/11 11:28:49 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ABSOLUTE VALUE OF A COMPLEX NUMBER *WITHOUT* SQRT FOR PERF
** TAKE ACCOUNT OF THAT WHEN USING IT
*/

double	ft_complex_abs(t_complex c)
{
	return (c.real * c.real + c.i * c.i);
}
