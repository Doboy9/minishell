/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:59:49 by dboire            #+#    #+#             */
/*   Updated: 2023/12/12 11:28:51 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	int			bytes_read;
	static char	buff[OPEN_MAX][BUFFER_SIZE + 1];
	char		*tmp;

	bytes_read = 1;
	tmp = ft_strdup(buff[fd]);
	while (bytes_read > 0)
	{
		if (ft_strchr(tmp, '\n'))
			break ;
		bytes_read = (read(fd, buff[fd], BUFFER_SIZE));
		buff[fd][bytes_read] = '\0';
		tmp = ft_strjoin(tmp, buff[fd]);
		if (ft_strchr(buff[fd], '\n'))
			break ;
		if ((tmp[0] == '\0') && bytes_read <= 0)
		{
			free(tmp);
			return (NULL);
		}
	}
	ft_str_save(buff[fd]);
	return (tmp);
}
