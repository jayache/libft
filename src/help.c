/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:26:23 by jayache           #+#    #+#             */
/*   Updated: 2019/11/14 10:52:40 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			help(void)
{
	ft_printf("./fractol [mandelbrot|julia|phoenix]\n");
	ft_printf("./fractol [mandelbrot|julia|phoenix] [width] [height]\n");
	return (0);
}

void		print_keys(void)
{
	ft_printf("Arrows: Move inside the fractal\n");
	ft_printf("+/-/Scroll: Change zoom\n");
	ft_printf("F: Change fractal\n");
	ft_printf("Right Click: Lock current fractal\n");
	ft_printf("Escape: Quit program\n");
	ft_printf("Z/X: Change level of details (more is slower)\n");
	ft_printf("C: Toggle smooth coloring (slightly slower)\n");
}
