/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 14:26:38 by jayache           #+#    #+#             */
/*   Updated: 2019/03/05 16:05:47 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*allocator(size_t size, int free)
{
	static t_list	*mem;
	t_list			*current;

	if (free)
		return (mem);
	if (!mem)
		current = (t_list*)malloc(size + sizeof(t_list));
	else
		current = (t_list*)malloc(size + sizeof(t_list));
	
	current->next = mem;
	current->content = &((char*)(current))[sizeof(t_list)];
	mem = current;
	return (current->content);
}

void	*ft_malloc(size_t size)
{
	return (allocator(size, 0));
}

void	ft_free(void)
{
	t_list *to_free;
	t_list *next;

	to_free = allocator(0, 1);
	while (to_free)
	{
		next = to_free->next;
		free(to_free);
		to_free = next;
	}
}

char	*ft_sstrdup(const char *s1)
{
	char	*s2;
	int		x;

	x = 0;
	s2 = ft_malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!s2)
	{
		return (NULL);
	}
	while (s1[x])
	{
		s2[x] = s1[x];
		++x;
	}
	s2[x] = '\0';
	return (s2);
}

int main()
{
	printf("%s\n", ft_sstrdup("Hello World"));
	printf("%s\n", ft_sstrdup("Hello World"));
	printf("%s\n", ft_sstrdup("Hello World"));
	char* test = ft_sstrdup("Hallo\n");
	void *t = ft_malloc(10000);

	char* tost = ft_sstrdup("Koko\n");
	printf("%s%s", test, tost);
	ft_free();
}
