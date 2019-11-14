/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:45:30 by jayache           #+#    #+#             */
/*   Updated: 2019/11/14 10:46:25 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_single_pixel(t_screen *screen, t_vector2 pos, int prox)
{
	t_color color;

	if (screen->smooth_color)
		color = create_color_smooth(screen, (double)prox);
	else
		color = create_color(screen, (double)prox);
	ft_draw_point(screen, pos, color);
}

void	draw_everything(t_screen *screen)
{
	fractal(screen);
	mlx_put_image_to_window(screen->mlx_ptr, screen->win_ptr, screen->img_ptr,
			0, 0);
}
