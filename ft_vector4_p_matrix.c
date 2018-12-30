/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector4_p_matrix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 11:10:48 by jayache           #+#    #+#             */
/*   Updated: 2018/12/30 16:12:02 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector4	ft_vector4_p_matrix(t_vector4 vec, t_matrix m)
{
	t_vector4	result;
	t_matrix	mr;
	t_matrix	temp;

	temp = ft_vector4_to_matrix(vec);
	mr = ft_matrix_product(m, temp);
	ft_matrix_free(temp);
	result = ft_matrix_to_vector4(mr);
	return (result);
}
