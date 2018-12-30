/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_lign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 20:11:58 by jayache           #+#    #+#             */
/*   Updated: 2018/12/30 17:31:11 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_draw_lign_h(t_vector2 beg, t_vector2 end, t_pixel *pixel)
{
	uintmax_t	e;
	int			dx;
	int			dy;

	e = ft_abs((int)beg.x - (int)end.x);
	dx = (int)(beg.x - end.x) * 2;
	dy = (int)(beg.y - end.y) * 2;
	while ((int)beg.x != (int)end.x)
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

static void	ft_draw_lign_y(t_vector2 beg, t_vector2 end, t_pixel *pixel)
{
	uintmax_t	e;
	int			dx;
	int			dy;

	e = ft_abs((int)(beg.y - end.y));
	dy = (int)(beg.y - end.y) * 2;
	dx = (int)(beg.x - end.x) * 2;
	while ((int)beg.y != (int)end.y)
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
	if (ft_abs((int)(end.x - beg.x)) > ft_abs((int)(end.y - beg.y)))
		ft_draw_lign_h(beg, end, pixel);
	else
		ft_draw_lign_y(beg, end, pixel);
}
