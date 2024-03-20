/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:12:55 by wneel             #+#    #+#             */
/*   Updated: 2023/11/26 12:27:03 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# define OPEN_MAX 1024
# include <unistd.h>
# include <stdlib.h>

typedef struct s_char_list
{
	char			c;
	struct s_char_list	*next;
}						t_char_list;

char		*get_next_line(int fd);
void		ft_lstadd_back_gnl(t_char_list **lst, t_char_list *new);
char		*ft_lstiter_gnl(t_char_list *lst, char const *s1);
char		*ft_strjoin_char(char *s1, char const c);
void		ft_lstclear_line(t_char_list **lst, void (*del)(void*));

#endif
