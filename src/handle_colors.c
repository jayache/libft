/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 10:35:58 by jayache           #+#    #+#             */
/*   Updated: 2019/11/11 11:27:28 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	return (ft_color_get_gradient(screen->close_color, screen->far_color,
				proximity));
}
