/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_add_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 15:30:31 by jayache           #+#    #+#             */
/*   Updated: 2019/01/01 15:34:41 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_graph_add_node(t_graph *graph, t_node *node)
{
	t_node **tmp;

	tmp = graph->nodes;
	graph->nodes = (t_node**)ft_memalloc((graph->size + 1) * sizeof(t_node*));
	ft_memcpy(graph->nodes, tmp);
	graph->nodes[size] = node;
	size++;
}
