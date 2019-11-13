/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 11:14:35 by jayache           #+#    #+#             */
/*   Updated: 2019/11/12 10:31:30 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef enum	e_fractal
{
	FRACTAL_MANDELBROT,
	FRACTAL_JULIA,
	FRACTAL_PHOENIX,
	FRACTAL_LAST
}				t_fractal;

/*
** STORE INFORMATION ABOUT THE WINDOW AND THE SCREEN
** USED FOR CONVENIENCE
** I SWEAR IT'S NOT A GOD OBJECT
*/

typedef struct	s_screen
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*screen;
	int		width;
	int		height;
	int		details;
	char	fractal;
	char	arg_lock;
	double	top;
	double	left;
	double	zoom;
	double	argx;
	double	argy;
	t_color	close_color;
	t_color	far_color;
}				t_screen;

#endif
