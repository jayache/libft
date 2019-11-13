/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_gradient.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:18:35 by jayache           #+#    #+#             */
/*   Updated: 2019/11/11 11:30:04 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** RETURN A COLOR FROM THE GRADIENT START-END, AT POSITION STEP
** STEP BETWEEN 0 AND 1
** WHATEVER I CAN'T COMMENT IN ENGLISH LOL
*/

t_color	ft_color_get_gradient(t_color start, t_color end, double step)
{
	t_color	result;

	result.blue = start.blue + (end.blue - start.blue) * step;
	result.green = start.green + (end.green - start.green) * step;
	result.red = start.red + (end.red - start.red) * step;
	return (result);
}
