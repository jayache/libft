/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector2_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 16:03:32 by jayache           #+#    #+#             */
/*   Updated: 2018/12/01 16:14:31 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "libft.h"

t_vector2	ft_vector2_add(t_vector2 vec, t_vector2 vec2)
{
	vec.x += vec2.x;
	vec.y += vec2.y;
	return (vec);
}
