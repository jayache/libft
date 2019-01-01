/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_create_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 14:19:19 by jayache           #+#    #+#             */
/*   Updated: 2018/12/31 14:21:43 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_btree_create_node(void *elem)
{
	t_btree *node;

	node = (t_btree*)ft_memalloc(sizeof(t_btree));
	node->data = elem;
	right = NULL;
	left = NULL;
	parent = NULL;
	return (node);
}
