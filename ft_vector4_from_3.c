/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector4_from_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 10:56:23 by jayache           #+#    #+#             */
/*   Updated: 2019/09/01 10:57:09 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector4	ft_vector4_from_3(t_vector3 vtc)
{
	return (ft_vector4(vtc.x, vtc.y, vtc.z, 1));
}