/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 11:13:15 by jayache           #+#    #+#             */
/*   Updated: 2019/11/13 10:55:51 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_val_for_fractal(t_screen *screen, t_complex c)
{
	if (screen->fractal == FRACTAL_MANDELBROT)
		return (mandelbrot(screen, c));
	else if (screen->fractal == FRACTAL_JULIA)
		return (julia(screen, c, ft_complex(screen->argx, screen->argy)));
	else if (screen->fractal == FRACTAL_PHOENIX)
		return (phoenix(screen, c, ft_complex(screen->argx, screen->argy)));
	return (0);
}

void	fractal(t_screen *screen)
{
	double	cx;
	double	cy;
	int		y;
	int		x;
	int		val;

	y = 0;
	while (y < screen->height)
	{
		x = 0;
		while (x < screen->width)
		{
			cx = x / screen->zoom + screen->left;
			cy = y / screen->zoom + screen->top;
			val = get_val_for_fractal(screen, ft_complex(cx, cy));
			draw_single_pixel(screen, ft_vector2(x, y), val);
			++x;
		}
		++y;
	}
}

int		julia(t_screen *screen, t_complex z, t_complex c)
{
	int			prec;

	prec = 0;
	while (ft_complex_abs(z) < 4 && prec < screen->details)
	{
		z = ft_complex_sum(ft_complex_product(z, z), c);
		++prec;
	}
	return (prec);
}

int		mandelbrot(t_screen *screen, t_complex c)
{
	t_complex	z;
	int			prec;

	z = ft_complex(0, 0);
	prec = 0;
	while (ft_complex_abs(z) < 4 && prec < screen->details)
	{
		z = ft_complex_sum(ft_complex_product(z, z), c);
		++prec;
	}
	return (prec);
}

int		phoenix(t_screen *screen, t_complex c, t_complex b)
{
	t_complex	z;
	t_complex	lastz;
	t_complex	temp;
	int			prec;

	z = ft_complex(1, 0);
	lastz = ft_complex(0, 0);
	prec = 0;
	while (ft_complex_abs(z) < 4 && prec < screen->details)
	{
		temp = ft_complex_sum(ft_complex_product(z, z), c);
		temp = ft_complex_sum(temp, ft_complex_product(lastz, b));
		lastz = z;
		z = temp;
		++prec;
	}
	return (prec);
}
