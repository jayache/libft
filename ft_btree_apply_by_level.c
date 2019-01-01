/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 14:28:41 by jayache           #+#    #+#             */
/*   Updated: 2018/12/31 14:27:36 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	append(t_pile **pile, t_btree *node)
{
	t_pile *elem;

	elem = *pile;
	while (elem->next)
		elem = elem->next;
	elem->next = malloc(sizeof(t_pile));
	elem->next->elem = node;
	elem->next->level = (*pile)->level + 1;
}

static t_pile	*create_pile(t_btree *root)
{
	t_pile *pile;

	pile = malloc(sizeof(t_pile));
	pile->elem = root;
	pile->level = 1;
	return (pile);
}

void	ft_btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
			int current_level, int is_first))
{
	t_pile	*pile;
	int		is_first;
	int		last_level;

	if (!root)
		return ;
	pile = create_pile(root);
	last_level = 0;
	while (pile)
	{
		if (pile->level != last_level)
		{
			is_first = 1;
			last_level = pile->level;
		}
		if (pile->elem->left)
			append(&pile, pile->elem->left);
		if (pile->elem->right)
			append(&pile, pile->elem->right);
		applyf(pile->elem->item, pile->level, is_first);
		pile = pile->next;
		is_first = 0;
	}
}
