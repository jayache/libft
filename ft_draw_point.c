/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:39:31 by jayache           #+#    #+#             */
/*   Updated: 2018/12/30 17:25:13 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_draw_point(t_vector2 coor, t_pixel *pixel)
{
	if (coor.x >= 0 && coor.y >= 0)
		mlx_pixel_put(pixel->mlxid, pixel->winid, (int)coor.x, (int)coor.y, pixel->color);
}
