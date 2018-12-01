/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector2_multiply.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 16:02:13 by jayache           #+#    #+#             */
/*   Updated: 2018/12/01 16:03:09 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector2	ft_vector2_multiply(t_vector2 vec, float scalar)
{
	vec.x *= scalar;
	vec.y *= scalar;
	return (scalar);
}
