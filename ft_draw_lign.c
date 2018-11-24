/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_lign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 20:11:58 by jayache           #+#    #+#             */
/*   Updated: 2018/11/24 20:31:59 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

void	ft_draw_lign_h(int x1, int y1, int x2, int y2, t_pair *id)
{
	int e;
	int dx;
	int dy;

	e = x1 - x2;
	dx = e * 2;
	dy = (y1 - y2) * 2;
	while (x1 < x2)
	{
		mlx_pixel_put(id->a, id->b, x1, y1, 255);
		x1 += ft_sign(dx);
		e -= dy;
		if (e <= 0)
	   	{
			++y1;
			e += dx;
		}
	}
}

void	ft_draw_lign_y(int x1, int y1, int x2, int y2, t_pair *id)
{
	int e;
	int dx;
	int dy;

	e = y1 - y2;
	dy = e * 2;
	dx = (x1 - x2) * 2;
	while (y1 < y2)
	{
		mlx_pixel_put(id->a, id->b, x1, y1, 255);
		y1 += ft_sign(dy);
		e -= dx;
		if (e <= 0)
	   	{
			++x1;
			e += dy;
		}
	}
}

void	ft_draw_lign(int x1, int y1, int x2, int y2, t_pair *id)
{
	if (ft_abs(x2 - x1))
		ft_draw_lign_h(x1, y1, x2, y2, id);
	else
		ft_draw_lign_y(x1, y1, x2, y2, id);
}
