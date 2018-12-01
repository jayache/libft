/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_rect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:43:44 by jayache           #+#    #+#             */
/*   Updated: 2018/12/01 16:10:35 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_draw_rect(t_vector2 beg, t_vector2 size, t_pixel *pixel)
{
	int a;
	int b;

	a = 0;
	while (a < size.x)
	{
		b = 0;
		while (b < size.y)
		{
			mlx_pixel_put(pixel->mlxid, pixel->winid, a + beg.x, b + beg.y,
			pixel->color);
			++b;
		}
		++a;
	}
}
