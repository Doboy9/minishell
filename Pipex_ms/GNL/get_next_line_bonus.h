/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:01:51 by dboire            #+#    #+#             */
/*   Updated: 2023/12/12 11:17:27 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define OPEN_MAX 1024

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_strdup(char *src);
char	*ft_strchr(char *s, int c);
void	ft_str_save(char *src);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
int		ft_strligne(char *str);

#endif