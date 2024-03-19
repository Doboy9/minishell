/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:03:44 by dboire            #+#    #+#             */
/*   Updated: 2023/12/12 11:03:30 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strligne(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		y;
	char	*dest;

	if (!src)
		return (NULL);
	i = 0;
	y = ft_strligne(src);
	dest = malloc(sizeof(char) * (y + 1));
	if (!dest)
		return (NULL);
	while (i < y)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(char *s, int c)
{
	unsigned char	y;
	size_t			i;

	if (!s)
		return (NULL);
	y = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == y)
			return (&s[i]);
		i++;
	}
	if (s[i] == y)
		return (&s[i]);
	if (y == 0)
		return (&s[i]);
	return (NULL);
}

void	ft_str_save(char *src)
{
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	while (src[i] != '\n' && src[i] != 0)
		i++;
	if (src[i] == '\n')
		i++;
	while (src[i + y])
	{
		src[y] = src[i + y];
		y++;
	}
	src[y] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		y;
	char	*dest;
	int		l;

	i = 0;
	y = 0;
	l = ft_strligne(s2);
	dest = malloc(sizeof(char) * (ft_strlen(s1) + l + 1));
	while (s1[i])
	{
		dest[i++] = s1[y++];
	}
	y = 0;
	while (s2 != NULL && y < l)
	{
		dest[i + y] = s2[y];
		y++;
	}
	dest[i + y] = '\0';
	free(s1);
	return (dest);
}
