/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 13:57:54 by jayache           #+#    #+#             */
/*   Updated: 2018/12/31 14:25:24 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	void *elem;

	elem = (NULL);
	if (root->left)
		elem = (btree_search_item(root->left, data_ref, cmpf));
	if (elem)
		return (elem);
	if (!cmpf(root->item, data_ref))
		return (root->item);
	if (root->right)
		elem = (btree_search_item(root->right, data_ref, cmpf));
	if (elem)
		return (elem);
	return (NULL);
}
