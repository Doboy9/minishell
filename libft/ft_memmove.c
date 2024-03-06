/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:24:41 by wneel             #+#    #+#             */
/*   Updated: 2023/11/05 16:31:27 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dest_char;
	char	*src_char;

	if (!dest && !src)
		return (0);
	dest_char = (char *) dest;
	src_char = (char *) src;
	if (dest > src)
	{
		while (n > 0)
		{
			n--;
			dest_char[n] = src_char[n];
		}
		return (dest_char);
	}
	i = 0;
	while (i < n)
	{
		dest_char[i] = src_char[i];
		i++;
	}
	return (dest_char);
}
