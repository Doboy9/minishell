/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:25:04 by wneel             #+#    #+#             */
/*   Updated: 2023/11/05 16:22:15 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_static_match_sep(const char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_s1;
	int		s1_len;
	int		i;
	int		j;
	int		end;

	i = 0;
	j = 0;
	end = 0;
	if (!s1 || !set)
		return (0);
	s1_len = ft_strlen(s1);
	while (ft_static_match_sep(s1[i], set))
		i ++;
	while (ft_static_match_sep(s1[s1_len - end - 1], set))
		end++;
	if (end + i > s1_len)
		i = 0;
	new_s1 = malloc(sizeof(char) * ((s1_len - end) - i + 1));
	if (!new_s1)
		return (0);
	while (i < (s1_len - end))
		new_s1[j++] = s1[i++];
	new_s1[j] = '\0';
	return (new_s1);
}
