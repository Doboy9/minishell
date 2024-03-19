/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:59:49 by dboire            #+#    #+#             */
/*   Updated: 2024/03/04 18:09:29 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strchr(char *s, int c)
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
static size_t	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}


static int	ft_strligne(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

static char	*ft_strdup(char *src)
{
	int		i;
	int		y;
	char	*dest;

	i = 0;
	if (src[0] == '\0')
		y = 0;
	else
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

static void	ft_str_save(char *src)
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

static char	*ft_strjoin(char *s1, char *s2)
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


char	*get_next_line(int fd)
{
	int			bytes_read;
	static char	buff[BUFFER_SIZE + 1];
	char		*tmp;

	bytes_read = 1;
	tmp = ft_strdup(buff);
	while (bytes_read > 0)
	{
		if (ft_strchr(tmp, '\n'))
		{
			break ;
		}
		bytes_read = (read(fd, buff, BUFFER_SIZE));
		buff[bytes_read] = '\0';
		tmp = ft_strjoin(tmp, buff);
		if (ft_strchr(buff, '\n'))
			break ;
		if ((tmp[0] == '\0') && bytes_read <= 0)
		{
			free(tmp);
			return (NULL);
		}
	}
	ft_str_save(buff);
	return (tmp);
}
