/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_graph.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 10:53:49 by jayache           #+#    #+#             */
/*   Updated: 2018/12/30 16:08:13 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_graph	*ft_create_graph(void *elem, int size)
{
	t_graph *graph;

	graph = ft_memalloc(sizeof(t_graph));
	graph->elem = elem;
	graph->size = size;
	graph->neighbors_number = 0;
	graph->neighbors = ft_memalloc(1);;
	return (graph);
}
