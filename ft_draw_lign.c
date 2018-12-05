/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_lign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 20:11:58 by jayache           #+#    #+#             */
/*   Updated: 2018/12/05 15:53:35 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

extern void	ft_draw_lign_h(t_vector2 beg, t_vector2 end, t_pixel *pixel)
{
	int e;
	int dx;
	int dy;

	e = ft_abs(beg.x - end.x);
	dx = (beg.x - end.x) * 2;
	dy = (beg.y - end.y) * 2;
	while (beg.x != end.x)
	{
		ft_draw_point(beg, pixel);
		beg.x += -ft_sign(dx);
		e -= ft_abs(dy);
		if (e <= 0)
		{
			beg.y += (-ft_sign(dy));
			e += ft_abs(dx);
		}
	}
}

extern void	ft_draw_lign_y(t_vector2 beg, t_vector2 end, t_pixel *pixel)
{
	int e;
	int dx;
	int dy;

	e = ft_abs(beg.y - end.y);
	dy = (beg.y - end.y) * 2;
	dx = (beg.x - end.x) * 2;
	while (beg.y != end.y)
	{
		ft_draw_point(beg, pixel);
		beg.y += -ft_sign(dy);
		e -= ft_abs(dx);
		if (e <= 0)
		{
			beg.x += ft_sign(dx);
			e += ft_abs(dy);
		}
	}
}

void		ft_draw_lign(t_vector2 beg, t_vector2 end, t_pixel *pixel)
{
	if (ft_abs(end.x - beg.x) > ft_abs(end.y - beg.y))
		ft_draw_lign_h(beg, end, pixel);
	else
		ft_draw_lign_y(beg, end, pixel);
}
