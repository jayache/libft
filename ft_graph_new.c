/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_graph.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 10:53:49 by jayache           #+#    #+#             */
/*   Updated: 2019/01/01 11:05:08 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_graph	*ft_graph_new(void)
{
	t_graph *graph;

	graph = (t_graph*)ft_memalloc(sizeof(t_graph) + 1);
	graph->size = 0;
	graph->nodes = ft_memalloc(1);
	return (graph);
}