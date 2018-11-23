/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_rect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:43:44 by jayache           #+#    #+#             */
/*   Updated: 2018/11/23 17:59:55 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_draw_rect(int x, int y, int width, int height, t_pair *id)
{
	int a;
	int b;

	a = 0;
	while (a < width)
	{
		b = 0;
		while (b < height)
		{
			mlx_pixel_put(id->a, id->b, a + x, b + y, 255);
			++b;
		}
		++a;
	}
}
