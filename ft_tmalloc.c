/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tmalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 12:39:47 by jayache           #+#    #+#             */
/*   Updated: 2018/11/28 10:48:20 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_tmalloc(void **target, size_t size)
{
	*target = ft_memalloc(size);
	if (!(*target))
		return (NULL);
	return (target);
}
