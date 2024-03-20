/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:12:50 by wneel             #+#    #+#             */
/*   Updated: 2023/11/26 12:27:16 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_push_char(t_char_list **lst, int *read_idx, char c, int *r)
{
	t_char_list	*curr;

	curr = NULL;
	curr = malloc(sizeof(t_char_list));
	if (!curr)
	{
		*r = -1;
		return ;
	}
	curr->c = c;
	curr->next = NULL;
	ft_lstadd_back_gnl(lst, curr);
	*read_idx += 1;
}

void	ft_read_buf(int fd, char *text_read, int *read_idx, int *r)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		text_read[i] = '\0';
		i++;
	}
	*r = read(fd, text_read, BUFFER_SIZE);
	*read_idx = 0;
}

char	*ft_read_line(int fd, t_char_list **lst)
{
	char	text_read[BUFFER_SIZE];
	int		read_idx;
	char	*line;
	int		r;

	line = "";
	read_idx = 0;
	ft_read_buf(fd, text_read, &read_idx, &r);
	while (text_read[read_idx] != '\0' && text_read[read_idx] != '\n'
		&& r > 0)
	{
		ft_push_char(lst, &read_idx, text_read[read_idx], &r);
		if (read_idx >= BUFFER_SIZE && r > 0)
			ft_read_buf(fd, text_read, &read_idx, &r);
	}
	while (read_idx < r)
		ft_push_char(lst, &read_idx, text_read[read_idx], &r);
	if (r != 0 && r == -1)
		return (0);
	line = ft_lstiter_gnl(*lst, line);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_char_list		*heads[OPEN_MAX];
	char				*line_content;

	line_content = ft_read_line(fd, &heads[fd]);
	if (line_content)
		ft_lstclear_line(&heads[fd], &free);
	return (line_content);
}
