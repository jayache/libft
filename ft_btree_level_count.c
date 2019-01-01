/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 14:20:28 by jayache           #+#    #+#             */
/*   Updated: 2018/12/31 14:25:49 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_btree_level_count(t_btree *root)
{
	int count_r;
	int count_l;

	count_r = 1;
	count_l = 1;
	if (root->right)
		count_r = count_r + btree_level_count(root->right);
	if (root->left)
		count_l = count_l + btree_level_count(root->left);
	return (count_l > count_r ? count_l : count_r);
}
