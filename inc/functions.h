/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 11:24:35 by jayache           #+#    #+#             */
/*   Updated: 2019/11/13 11:34:14 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

void	fractal(t_screen *screen);
t_color	create_color(t_screen *screen, double proximity);
void	zoom_plus(t_screen *screen, double x, double y);
void	zoom_minus(t_screen *screen, double x, double y);

/*
** PRINT COMMANDLINE
** GOAL: GIVE HINTS AS TO THE USAGE OF THE PROGRAM
*/

int		help(void);
void	print_keys(void);

/*
**	FRACTALS FUNCTIONS
**	GOAL: COMPUTE FRACTALS FORMULA
*/

int		mandelbrot(t_screen *screen, t_complex c);
int		julia(t_screen *screen, t_complex z, t_complex c);
int		phoenix(t_screen *screen, t_complex z, t_complex c);

/*
** DRAW FUNCTIONS
** GOAL: HANDLE SCREEN PRINTING
*/

void	ft_draw_point(t_screen *screen, t_vector2 pos, t_color color);
void	draw_single_pixel(t_screen *screen, t_vector2 pos, int prox);
void	draw_everything(t_screen *screen);

/*
** HOOKS FUNCTIONS
** GOAL: HANDLE USER INTERACTION
*/

int		hook_mouse(int button, int x, int y, void *screen);
int		hook_motion(int x, int y, void *screen);
int		hook_keys(int key, void *screen);

#endif
