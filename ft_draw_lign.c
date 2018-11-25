/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_lign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 20:11:58 by jayache           #+#    #+#             */
/*   Updated: 2018/11/25 17:39:16 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

extern void	ft_draw_lign_h(int x1, int y1, int x2, int y2, t_pixel *pixel)
{
	int e;
	int dx;
	int dy;

	e = ft_abs(x1 - x2);
	dx = (x1 - x2) * 2;
	dy = (y1 - y2) * 2;
	while (x1 != x2)
	{
		mlx_pixel_put(pixel->mlxid, pixel->winid, x1, y1, pixel->color);
		x1 += -ft_sign(dx);
		e -= ft_abs(dy);
		if (e <= 0)
	   	{
			y1 += ft_sign(dy);
			e += ft_abs(dx);
		}
	}
}

extern void	ft_draw_lign_y(int x1, int y1, int x2, int y2, t_pixel *pixel)
{
	int e;
	int dx;
	int dy;

	e = ft_abs(y1 - y2);
	dy = (y1 - y2) * 2;
	dx = (x1 - x2) * 2;
	while (y1 != y2)
	{
		mlx_pixel_put(pixel->mlxid, pixel->winid, x1, y1, pixel->color);
		y1 += -ft_sign(dy);
		e -= ft_abs(dx);
		if (e <= 0)
	   	{
			x1 += ft_sign(dx);
			e += ft_abs(dy);
		}
	}
}

void	ft_draw_lign(int x1, int y1, int x2, int y2, t_pixel *pixel)
{
	if (ft_abs(x2 - x1) > ft_abs(y2 - y1))
		ft_draw_lign_h(x1, y1, x2, y2, pixel);
	else
		ft_draw_lign_y(x1, y1, x2, y2, pixel);
}
