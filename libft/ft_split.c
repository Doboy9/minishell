/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:20:51 by wneel             #+#    #+#             */
/*   Updated: 2023/11/09 16:10:55 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_static_get_part(const char *str, char c, int i)
{
	char	*part;
	int		part_len;
	int		j;

	part_len = 0;
	while (str[i] != '\0' && str[i] != c)
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
	char c,
	int i,
	int *total_space
)
{
	char	*part;
	int		part_len;

	*total_space = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			part = ft_static_get_part(str, c, i);
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

static void	ft_free_array(char **split)
{
	while (*split != NULL)
	{
		free(*split);
		split++;
	}
}

static char	**ft_split_loop(
	char **split,
	int split_count,
	char c,
	char const *s
)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			split[split_count] = ft_static_get_part(s, c, i);
			if (!split[split_count])
			{
				ft_free_array(split);
				return (0);
			}
			i += ft_strlen(split[split_count]);
			split_count++;
		}
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		total_space;

	if (!s)
		return (0);
	ft_static_count_alloc_space(s, c, 0, &total_space);
	split = ft_calloc(total_space, sizeof(char *));
	if (!split)
		return (0);
	split = ft_split_loop(split, 0, c, s);
	return (split);
}
