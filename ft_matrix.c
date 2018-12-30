/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 17:37:48 by jayache           #+#    #+#             */
/*   Updated: 2018/12/30 17:13:52 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** CREATES A MATRIX
** THE MATRIX AS A HEIGHT OF -1
** IN CASE OF FAILURE
*/

t_matrix	ft_matrix(int width, int height)
{
	t_matrix	matrix;
	int			x;
	int			y;

	x = 0;
	matrix.height = -1;
	if (!(matrix.matrix = malloc(sizeof(int) * (size_t)height + 1)))
		return (matrix);
	while (x < height)
	{
		y = -1;
		if (!(matrix.matrix[x] = malloc(sizeof(int) * (size_t)width + 1)))
			return (matrix);
		while ((y++) < width)
			matrix.matrix[x][y] = 0;
		++x;
	}
	matrix.height = height;
	matrix.width = width;
	return (matrix);
}
