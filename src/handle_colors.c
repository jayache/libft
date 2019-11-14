/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 10:35:58 by jayache           #+#    #+#             */
/*   Updated: 2019/11/14 10:50:09 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	create_color_smooth(t_screen *screen, double proximity)
{
	proximity = proximity / screen->details;
	if (proximity >= 0 && proximity <= .2)
		return (ft_color_get_gradient(ft_color(0, 0, 0), ft_color(0, 0, 255),
					proximity * 5));
	else if (proximity > .2 && proximity <= .4)
		return (ft_color_get_gradient(ft_color(0, 0, 255), ft_color(255, 0, 0),
					(proximity - .2) * 5));
	else if (proximity > .4 && proximity <= .6)
		return (ft_color_get_gradient(ft_color(255, 0, 0), ft_color(0, 255, 0),
					(proximity - .4) * 5));
	else if (proximity > .6 && proximity <= .8)
		return (ft_color_get_gradient(ft_color(0, 255, 0),
					ft_color(255, 255, 0), (proximity - .6) * 5));
	else if (proximity > .8 && proximity <= 1)
		return (ft_color_get_gradient(ft_color(255, 255, 0),
					ft_color(255, 0, 255), (proximity - .8) * 5));
	else
		return (ft_color(255, 0, 255));
}

t_color	create_color(t_screen *screen, double proximity)
{
	int	i;

	i = (int)proximity % 5;
	if (proximity == screen->details)
		return (ft_color(255, 255, 255));
	else if (proximity == 0)
		return (ft_color(0, 0, 0));
	if (i == 0)
		return (ft_color(0, 0, 255));
	else if (i == 1)
		return (ft_color(255, 0, 0));
	else if (i == 2)
		return (ft_color(0, 255, 0));
	else if (i == 3)
		return (ft_color(255, 255, 0));
	else
		return (ft_color(255, 0, 255));
}
