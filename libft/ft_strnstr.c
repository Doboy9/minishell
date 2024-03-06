/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:11:10 by wneel             #+#    #+#             */
/*   Updated: 2023/11/05 11:35:06 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_static_strindex(char *str, char *to_find, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < len && str[i] != '\0')
	{
		j = 0;
		while (str[i] == to_find[j] && str[i] != '\0' && i < len)
		{
			if (to_find[j + 1] == '\0')
				return (i - j);
			j++;
			i++;
		}
		i++;
		i = i - j;
	}
	return (-1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		first_occur;
	char	*char_big;
	char	*char_little;

	char_big = (char *) big;
	char_little = (char *) little;
	if (little[0] == 0)
		return (char_big);
	if (!big && len == 0)
		return (0);
	first_occur = ft_static_strindex(char_big, char_little, len);
	if (first_occur == -1)
		return (0);
	char_little = char_big + first_occur;
	return (char_little);
}
