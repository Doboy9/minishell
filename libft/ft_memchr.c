/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:55:18 by wneel             #+#    #+#             */
/*   Updated: 2023/11/05 12:16:04 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_static_strchr(unsigned char *s, unsigned char c, size_t n)
{
	unsigned int		i;

	i = 0;
	while (i < n)
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_as_string;
	int				chr_idx;

	if (n == 0)
		return (0);
	s_as_string = (unsigned char *) s;
	chr_idx = ft_static_strchr(s_as_string, (unsigned char)c, n);
	s_as_string += chr_idx;
	if (chr_idx == -1)
		return (0);
	return (s_as_string);
}
