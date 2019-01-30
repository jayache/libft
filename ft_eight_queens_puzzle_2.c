/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_aueens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 16:11:41 by jayache           #+#    #+#             */
/*   Updated: 2019/01/26 14:27:04 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ABS(x) (x < 0 ? x * -1 : x)

void	ft_putchar(char c);

int		dispo(int x, int y, int grid[8])
{
	int c;

	if (x == 0)
		return (0);
	c = 0;
	while (c < y)
		if (grid[c++] == x)
			return (0);
	c = 0;
	while (c < y)
	{
		if (ABS((grid[c] - grid[y])) == ABS((c - y)))
		{
			return (0);
		}
		c++;
	}
	return (1);
}

void	print_tab(int grid[8])
{
	int c;

	c = 0;
	while (c < 8)
	{
		ft_putchar(grid[c++] + '0');
	}
	ft_putchar('\n');
}

int		bruteforce(int grid[8], int queen, int *solution)
{
	int x;

	x = 1;
	if (queen == 8)
	{
		print_tab(grid);
		return (0);
	}
	while (x < 9)
	{
		grid[queen] = x;
		if (dispo(x, queen, grid))
		{
			if (bruteforce(grid, queen + 1, solution))
				return (1);
			else
				grid[queen] = 0;
		}
		x++;
	}
	grid[queen] = 0;
	return (0);
}

int		ft_eight_queens_puzzle_2(void)
{
	int grille[8];
	int x;
	int y;
	int solutions;

	solutions = 1;
	x = 0;
	y = 0;
	while (x < 8)
	{
		grille[x++] = 0;
	}
	bruteforce(grille, 0, &solutions);
	return (solutions - 1);
}
