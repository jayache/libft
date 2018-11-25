/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_rect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:43:44 by jayache           #+#    #+#             */
/*   Updated: 2018/11/25 17:00:58 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_draw_rect(int x, int y, int width, int height, t_pixel *pixel)
{
	int a;
	int b;

	a = 0;
	while (a < width)
	{
		b = 0;
		while (b < height)
		{
			mlx_pixel_put(pixel->mlxid, pixel->winid, a + x, b + y, pixel->color);
			++b;
		}
		++a;
	}
}
