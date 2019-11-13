/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_update_screen.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:28:04 by jayache           #+#    #+#             */
/*   Updated: 2019/11/08 14:36:33 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_plus(t_screen *screen, double x, double y)
{
	double xx;
	double yy;

	yy = y / screen->zoom + screen->top;
	xx = x / screen->zoom + screen->left;
	screen->details += 3;
	screen->zoom *= 1.1;
	screen->left = xx - x / screen->zoom;
	screen->top = yy - y / screen->zoom;
}

void	zoom_minus(t_screen *screen, double x, double y)
{
	double xx;
	double yy;

	yy = y / screen->zoom + screen->top;
	xx = x / screen->zoom + screen->left;
	screen->zoom /= 1.1;
	screen->left = xx - x / screen->zoom;
	screen->top = yy - y / screen->zoom;
	if (screen->details > 15)
		screen->details -= 3;
}
