/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:25:18 by wneel             #+#    #+#             */
/*   Updated: 2024/01/12 10:21:02 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	s1_len;
	unsigned int	s2_len;
	unsigned int	i;
	char			*concat;

	if (!s1 && !s2)
		return (0);
	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	concat = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!concat)
		return (0);
	while (s1 && s1[i] != '\0')
	{
		concat[i] = s1[i];
		i++;
	}
	while (s2 && s2[i - s1_len] != '\0')
	{
		concat[i] = s2[i - s1_len];
		i++;
	}
	concat[i] = '\0';
	return (concat);
}
