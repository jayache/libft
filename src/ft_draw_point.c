/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:39:31 by jayache           #+#    #+#             */
/*   Updated: 2019/11/02 15:58:42 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** DRAW A POINT IN A BUFFER
** ARGS:		 t_screen *screen-> screen structure
**				 t_vector2 coor-> position to draw the point in
**				 t_pixel pixel->	pixel color
*/

void	ft_draw_point(t_screen *screen, t_vector2 coor, t_color pixel)
{
	int	index;

	index = ((int)coor.y * screen->width * 4) + ((int)coor.x * 4);
	if (coor.x >= 0 && coor.y >= 0 && coor.x < screen->width
			&& coor.y < screen->height)
	{
		screen->screen[index] = pixel.blue;
		screen->screen[index + 1] = pixel.green;
		screen->screen[index + 2] = pixel.red;
		screen->screen[index + 3] = 0;
	}
}
