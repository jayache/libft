/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 10:36:03 by jayache           #+#    #+#             */
/*   Updated: 2019/11/13 11:26:20 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_screen	new_screen(int width, int height)
{
	t_screen	screen;
	int			devnull;

	screen.width = width;
	screen.height = height;
	screen.mlx_ptr = mlx_init();
	screen.win_ptr = mlx_new_window(screen.mlx_ptr, width, height, "fractol");
	screen.img_ptr = mlx_new_image(screen.mlx_ptr, width, height);
	screen.screen = mlx_get_data_addr(screen.img_ptr, &devnull, &devnull,
			&devnull);
	screen.details = 30;
	screen.zoom = 100;
	screen.top = -height / 2.0 / screen.zoom;
	screen.left = -width / 2.0 / screen.zoom;
	screen.close_color = ft_color(0, 0, 255);
	screen.far_color = ft_color(0, 255, 0);
	return (screen);
}

t_screen	new_screen_custom_size(char **av)
{
	int	width;
	int	height;

	width = ft_atoi(av[2]);
	height = ft_atoi(av[3]);
	if (width <= 1500 && width >= 500 && height <= 1500 && height >= 500)
		return (new_screen(width, height));
	ft_printf("Invalid size argument !\n");
	exit(0);
}

int			get_fractal(char *str)
{
	if (!ft_strcmp(str, "mandelbrot"))
		return (FRACTAL_MANDELBROT);
	else if (!ft_strcmp(str, "julia"))
		return (FRACTAL_JULIA);
	else if (!ft_strcmp(str, "phoenix"))
		return (FRACTAL_PHOENIX);
	else
		return (-1);
}

int			main(int ac, char **av)
{
	t_screen	screen;

	if (ac != 2 && ac != 4)
		return (help());
	screen.fractal = get_fractal(av[1]);
	if (screen.fractal == -1)
		return (help());
	if (ac == 4)
		screen = new_screen_custom_size(av);
	else
		screen = new_screen(600, 600);
	screen.fractal = get_fractal(av[1]);
	draw_everything(&screen);
	mlx_key_hook(screen.win_ptr, hook_keys, &screen);
	mlx_hook(screen.win_ptr, 6, 0, hook_motion, &screen);
	mlx_mouse_hook(screen.win_ptr, hook_mouse, &screen);
	mlx_loop(screen.mlx_ptr);
	return (0);
}
