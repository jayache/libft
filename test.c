#include "libft.h"
#include <stdio.h>

int main()
{
	t_graph *g = ft_graph_new();
	
	ft_graph_add_node(g, ft_graph_node_new("test", sizeof("test")));
	ft_graph_add_node(g, ft_graph_node_new("tist", sizeof("test")));
	ft_graph_add_node(g, ft_graph_node_new("t5st", sizeof("test")));
	ft_graph_add_node(g, ft_graph_node_new("t5st", sizeof("test")));
	ft_graph_add_link(g->nodes[0], g->nodes[1]);
	ft_graph_add_link(g->nodes[0], g->nodes[2]);
	ft_graph_add_link(g->nodes[0], g->nodes[3]);
	for (int x = 0; x < g->size; ++x)
		printf("%s\n", ((char*)(g->nodes[x]->elem)));
	for (int x = 0; x < g->nodes[0]->neighbors_number; ++x)
		printf("%s\n", ((char*)(g->nodes[0]->neighbors[x]->elem)));
}
