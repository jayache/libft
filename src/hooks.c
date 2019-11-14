/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:02:32 by jayache           #+#    #+#             */
/*   Updated: 2019/11/14 10:48:06 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** HANDLE KEYBOARD INPUT
*/

static void	update_screen(t_screen *screen, int key)
{
	if (key == KEY_UP)
		screen->top -= 0.1 / screen->zoom * 100;
	else if (key == KEY_DOWN)
		screen->top += 0.1 / screen->zoom * 100;
	else if (key == KEY_LEFT)
		screen->left += 0.1 / screen->zoom * 100;
	else if (key == KEY_RIGHT)
		screen->left -= 0.1 / screen->zoom * 100;
	else if (key == KEY_PLUS)
		zoom_plus(screen, screen->width / 2.0, screen->height / 2.0);
	else if (key == KEY_MINUS)
		zoom_minus(screen, screen->width / 2, screen->height / 2);
	else if (key == KEY_ESCAPE)
		exit(0);
	else if (key == KEY_F)
		screen->fractal = (screen->fractal + 1) % FRACTAL_LAST;
	else if (key == KEY_Z)
		screen->details += 3;
	else if (key == KEY_X)
		screen->details -= 3;
	else if (key == KEY_C)
		screen->smooth_color = !screen->smooth_color;
}

int			hook_keys(int key, void *screen)
{
	t_screen *s;

	s = screen;
	update_screen(s, key);
	draw_everything(s);
	return (0);
}

/*
** HANDLE MOUSE INPUT
*/

int			hook_mouse(int button, int x, int y, void *screen)
{
	t_screen *s;

	s = screen;
	if (button == SCROLL_UP)
		zoom_plus(s, x, y);
	else if (button == SCROLL_DOWN)
		zoom_minus(s, x, y);
	else if (button == RIGHTCLICK)
	{
		s->arg_lock = !s->arg_lock;
	}
	draw_everything(s);
	return (0);
}

int			hook_motion(int x, int y, void *screen)
{
	t_screen *s;

	s = screen;
	if (s->arg_lock)
		return (0);
	s->argx = (double)x / s->width;
	s->argy = (double)y / s->height;
	draw_everything(s);
	return (0);
}
