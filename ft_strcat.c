/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 20:14:23 by jayache           #+#    #+#             */
/*   Updated: 2018/11/07 20:20:03 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *s1, const char *s2)
{
	int x;
	int j;

	j = 0;
	x = 0;
	while (s1[x])
		++x;
	while (s2[j])
	{
		s1[x + j] = s2[j];
		++j;
	}
	s1[x + j] = '\0';
	return (s1);
}
