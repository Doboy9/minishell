/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:35:00 by wneel             #+#    #+#             */
/*   Updated: 2023/11/05 16:22:28 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	s_len;
	unsigned int	i;
	char			*substr;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (len >= s_len)
		len = s_len - start;
	if (start > s_len)
		len = 0;
	substr = ft_calloc(len + 1, sizeof(char));
	if (!substr)
		return (0);
	if (start >= s_len)
		return (substr);
	i = 0;
	while (s[start + i] != '\0' && i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	return (substr);
}
