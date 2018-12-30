/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector3_angle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 16:49:23 by jayache           #+#    #+#             */
/*   Updated: 2018/12/30 17:09:48 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_vector3_angle(t_vector3 vec1, t_vector3 vec2)
{
	return (acos(ft_vector3_dot(ft_vector3_normalize(vec1),
	ft_vector3_normalize(vec2))));
}
