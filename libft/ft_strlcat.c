/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:15:57 by wneel             #+#    #+#             */
/*   Updated: 2023/11/05 16:21:15 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_static_strnlen(char *str, unsigned int n)
{
	unsigned int		i;

	i = 0;
	while (str[i] != '\0' && i < n)
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	src_n_len;
	unsigned int	cpy_len;

	i = 0;
	src_n_len = ft_strlen(src);
	if (size == 0)
		return (src_n_len);
	while (dst[i] != '\0' && i < size)
		i++;
	i = ft_static_strnlen(dst, size);
	if (i == size)
		return (size + src_n_len);
	cpy_len = ft_strlcpy(dst + i, src, size - i);
	return (i + cpy_len);
}
