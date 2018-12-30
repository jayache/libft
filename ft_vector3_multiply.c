/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector3_multiply.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 16:54:19 by jayache           #+#    #+#             */
/*   Updated: 2018/12/30 17:09:19 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector3	ft_vector3_multiply(t_vector3 vec1, double scalar)
{
	vec1.x *= scalar;
	vec1.y *= scalar;
	vec1.z *= scalar;
	return (vec1);
}
