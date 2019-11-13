/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 10:40:08 by jayache           #+#    #+#             */
/*   Updated: 2019/11/08 14:29:36 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** RETURNS A NEW COLOR STRUCT
*/

t_color	ft_color(unsigned char red, unsigned char green, unsigned char blue)
{
	t_color	result;

	result.red = red;
	result.green = green;
	result.blue = blue;
	return (result);
}
