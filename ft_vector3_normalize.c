/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector3_normalize.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 14:57:19 by jayache           #+#    #+#             */
/*   Updated: 2018/12/30 17:09:03 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector3	ft_vector3_normalize(t_vector3 vec)
{
	double mag;

	mag = ft_vector3_magnitude(vec);
	vec.x /= mag;
	vec.y /= mag;
	vec.z /= mag;
	return (vec);
}
