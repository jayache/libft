#include "libft.h"
#include "test.h"

#include <stdio.h>
#define ABS(x) (x < 0 ? x * -1 : x)

int		dispo(int val, int pos, int grid[8])
{
	int c;

	if (val == 0)
		return (0);
	c = 0;
	while (c < pos)
		if (grid[c++] == val)
			return (0);
	c = 0;
	while (c < pos)
	{
		if (ABS((grid[c] - grid[pos])) == ABS((c - pos)))
		{
			return (0);
		}
		c++;
	}
	return (1);
}

t_queens *queens_add(int grid[8], int level)
{
	t_queens *q;

	q = (t_queens*)ft_memalloc(sizeof(t_queens));
	for (int i = 0; i < 8; ++i)
		q->grid[i] = grid[i];
	q->level = level;
	return (q);
}

t_node	**voisins(t_node *node)
{
	t_queens *t;
	int	c;
	int	grid[8];

	t = (t_queens*)node->elem;
	c = 0;
	for (int i = 0; i < 8; ++i)
		grid[i] = t->grid[i];
	while (c <= 8 && t->level < 8)
	{
		grid[t->level] = c;
		if (dispo(c, t->level, grid))
		{
			ft_printf("%d %d\n", t->level, c);
			t_node *n = ft_graph_node_new(queens_add(grid, t->level + 1), sizeof(t_queens*));
			ft_graph_add_link(node, n);
			//true;
		}
		++c;
	}
	return (node->neighbors);
}

int	perfect(t_node *start)
{
	t_queens *t;

	t = (t_queens*)start->elem;
	if (t->level == 8)
		return (1);
	return (0);
}

int main()
{
	t_graph *g = ft_graph_new();
	int grid[8];

	for (int i = 0; i < 8; ++i)
		grid[i] = 0;
	ft_graph_add_node(g, ft_graph_node_new(queens_add(grid, 0), sizeof(t_queens*)));
	t_node **path = ft_solve(g->nodes[0], &voisins, &perfect);
	if (!path)
		return (0);
	t_node *c = path[0];
	
	for (int i = 0; path[i]->neighbors_number > 0; ++i)	
		c = path[i];
	t_queens* t = (t_queens*)c->elem;

	for (int i = 0; i < 8; ++i)
		ft_printf("[%d]", t->grid[i]);
}
