/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:47:33 by wneel             #+#    #+#             */
/*   Updated: 2023/11/26 12:27:31 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstadd_back_gnl(t_char_list **lst, t_char_list *new)
{
	t_char_list	*curr;

	if (!*lst || !lst)
	{
		*lst = new;
		return ;
	}
	curr = *lst;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = new;
}

char	*ft_lstiter_gnl(t_char_list *lst, char const *s1)
{
	t_char_list	*curr;
	char	*concat;

	if (!lst || !s1)
		return (0);
	curr = lst;
	concat = (char *) s1;
	while (curr != NULL)
	{
		concat = ft_strjoin_char(concat, curr->c);
		if (!concat)
			return (0);
		if (curr->c == '\n')
			break ;
		curr = curr->next;
	}
	return (concat);
}

char	*ft_strjoin_char(char *s1, char const c)
{
	unsigned int	s1_len;
	unsigned int	i;
	char			*concat;

	if (!s1 || !c)
		return (0);
	i = 0;
	s1_len = -1;
	while (s1[++s1_len] != '\0')
		;
	concat = malloc(sizeof(char) * (s1_len + 1 + 1));
	if (!concat)
		return (0);
	while (s1[i] != '\0')
	{
		concat[i] = s1[i];
		i++;
	}
	if (s1_len)
		free(s1);
	concat[i++] = c;
	concat[i] = '\0';
	return (concat);
}

void	ft_lstclear_line(t_char_list **lst, void (*del)(void*))
{
	t_char_list	*curr;
	t_char_list	*next;

	if (!*lst || !lst || !del)
		return ;
	curr = *lst;
	while (curr != NULL)
	{
		next = curr->next;
		if (curr->c == '\n')
		{
			del(curr);
			curr = next;
			break ;
		}
		if (curr->c != '\n')
			del(curr);
		curr = next;
	}
	*lst = curr;
}
