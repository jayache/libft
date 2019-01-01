/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_link.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 10:59:39 by jayache           #+#    #+#             */
/*   Updated: 2019/01/01 11:07:37 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_graph_add_link(t_node *nodea, t_node *nodeb)
{
	void	*temp;

	temp = nodea->neighbors;
	nodea->neighbors = ft_memalloc(nodea->neighbors_number * sizeof(t_graph*));
	ft_memcpy(nodea->neighbors, temp, nodea->neighbors_number);
	nodea->neighbors[nodea->neighbors_number] = nodeb;
	free(temp);
	temp = nodeb->neighbors;
	nodeb->neighbors = ft_memalloc(nodeb->neighbors_number * sizeof(t_graph*));
	ft_memcpy(nodeb->neighbors, temp, nodeb->neighbors_number);
	nodeb->neighbors[nodeb->neighbors_number] = nodea;
	free(temp);
	nodea->neighbors_number += 1;
	nodeb->neighbors_number += 1;
}