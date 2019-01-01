/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 10:28:25 by jayache           #+#    #+#             */
/*   Updated: 2018/12/31 14:24:54 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_insert_data(t_btree **root, void *item,
		int (*cmpf)(void *, void *))
{
	t_btree *elem;

	elem = *root;
	if (elem)
	{
		if (cmpf(elem->item, item) > 0)
		{
			if (elem->left)
				btree_insert_data(&elem->left, item, cmpf);
			else
				elem->left = btree_create_node(item);
		}
		else
		{
			if (elem->right)
				btree_insert_data(&elem->right, item, cmpf);
			else
				elem->right = btree_create_node(item);
		}
	}
	else
		*root = btree_create_node(item);
}
