/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wawa.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:50:31 by wneel             #+#    #+#             */
/*   Updated: 2024/03/13 14:54:19 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WAWA_H
#define WAWA_H
# include "libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct	s_quote_status
{
	int in_squotes;
	int in_dquotes;
}				t_quote_status;

typedef struct s_text_read
{
	char	*raw_text;
	int		is_metachar;
	int		is_attribution;
}				t_text_read;

int		ft_is_word_cutter(const char *str, int index);
char	**ft_split_bash_words(char const *s);
int		ft_wawa(int ac, char *av[], char *ev[]);
void	ft_print_text_read(t_text_read **text_read);
void	ft_print_split(char **splitted);
#endif
