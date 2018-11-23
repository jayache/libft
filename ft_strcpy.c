/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:27:17 by jayache           #+#    #+#             */
/*   Updated: 2018/11/07 19:38:57 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dst, const char *src)
{
	int x;

	x = 0;
	while (src[x])
	{
		dst[x] = src[x];
		++x;
	}
	dst[x] = src[x];
	return (dst);
}