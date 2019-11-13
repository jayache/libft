/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 12:13:37 by jayache           #+#    #+#             */
/*   Updated: 2019/09/14 17:14:35 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_append(t_list *root, t_list *append)
{
	while (root && root->next)
		root = root->next;
	if (!root)
		root = append;
	else
		root->next = append;
}
