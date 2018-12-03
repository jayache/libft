/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_product.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:39:38 by jayache           #+#    #+#             */
/*   Updated: 2018/12/03 16:57:06 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static float	productcase(t_matrix a, t_matrix b, int x, int y)
{
	int		t;
	float	result;

	result = 0;
	t = 0;
	while (t < b.height)
	{
		result += ((b.matrix[t])[x] * (a.matrix[y])[t]);
		++t;
	}
	return (result);
}

t_matrix		ft_matrix_product(t_matrix a, t_matrix b)
{
	t_matrix	matrix;
	int			x;
	int			y;

	matrix = ft_matrix(b.width, a.height);
	if (a.width != b.height)
		return (matrix);
	x = 0;
	while (x < matrix.width)
	{
		y = 0;
		while (y < matrix.height)
		{
			(matrix.matrix[y])[x] = productcase(a, b, x, y);
			++y;
		}
		++x;
	}
	return (matrix);
}
