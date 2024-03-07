/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wawa_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:50:27 by wneel             #+#    #+#             */
/*   Updated: 2024/03/06 12:29:00 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wawa.h"

static char	*ft_static_get_part(const char *str, int i)
{
	char	*part;
	int		part_len;
	int		j;

	part_len = 0;
	while (str[i] != '\0' && !ft_is_word_cutter(str, i))
	{
		part_len++;
		i++;
	}
	j = 0;
	part = ft_calloc((part_len + 1), sizeof(char));
	if (!part)
		return (0);
	while ((i - part_len + j) < i)
	{
		part[j] = str[(i - part_len + j)];
		j++;
	}
	return (part);
}

static void	ft_static_count_alloc_space(
	const char *str,
	int *total_space
)
{
	int		i;
	char	*part;
	int		part_len;

	i = 0;
	*total_space = 0;
	while (str[i] != '\0')
	{
		if (ft_is_word_cutter(str, i))
			i++;
		else
		{
			part = ft_static_get_part(str, i);
			if (!part)
				return ;
			part_len = ft_strlen(part);
			*total_space += 1;
			i += part_len;
			free(part);
		}
	}
	*total_space += 1;
}

static char	**ft_split_loop(
	char **split,
	char const *s
)
{
	int	i;
	int	split_count;

	i = 0;
	split_count = 0;
	while (s[i] != '\0')
	{
		if (ft_is_word_cutter(s, i))
			i++;
		else
		{
			split[split_count] = ft_static_get_part(s, i);
			if (!split[split_count])
			{
				free_tab(split);
				return (0);
			}
			i += ft_strlen(split[split_count]);
			split_count++;
		}
	}
	return (split);
}

char	**ft_split_bash_words(char const *s)
{
	char	**split;
	int		total_space;

	if (!s)
		return (0);
	ft_static_count_alloc_space(s, &total_space);
	split = ft_calloc(total_space, sizeof(char *));
	if (!split)
		return (0);
	split = ft_split_loop(split, s);
	return (split);
}
