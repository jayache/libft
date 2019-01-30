/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_aueens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 16:11:41 by jayache           #+#    #+#             */
/*   Updated: 2019/01/26 14:58:36 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* bruteforce, return an array of nodes */

t_node	**bruteforce(t_node *current, t_node** (*neighbors)(t_node *), int (*valid)(t_node *), int level)
{
	size_t x;
	t_node **n;
	t_node **path;

	x = 0;
	ft_printf("%d\n", level);
	if (valid(current)) //success condition
	{
		ft_printf("HELLO\n");
		path = ft_memalloc(sizeof(t_node*) * level + 1);
		path[level] = current;
		return (path);
	}
	n = neighbors(current);
	while (x < current->neighbors_number) //test each neighbors
	{
		if ((path = bruteforce(n[x], neighbors, valid, level + 1)))
		{
			path[level] = current;
			return (path);
		}
		x++;
	}
	return (NULL);
}

/* ft_solve, prepare the bruteforce */
t_node	**ft_solve(t_node *start, t_node** (*n)(t_node *), int (*v)(t_node *))
{
	t_node **path;

	path = bruteforce(start, n, v, 0);
	return (path);
}
