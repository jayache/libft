/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 11:05:19 by jayache           #+#    #+#             */
/*   Updated: 2019/01/01 11:09:47 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*ft_graph_node_new(void *elem, size_t size)
{
	t_node *node;

	node = (t_node*)ft_memalloc(sizeof(t_node));
	node->size = size;
	node->elem = elem;
	node->neighbors = ft_memalloc(1);
	node->neighbors_number = 0;
	return (node);
}
