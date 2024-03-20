/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wawa.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:50:31 by wneel             #+#    #+#             */
/*   Updated: 2024/03/20 09:47:46 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WAWA_H
#define WAWA_H
# include "libft/libft.h"
# include "parsing/parsing.h"
# include "parsing/parsing_structs.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

int		ft_is_word_cutter(const char *str, int index);
char	**ft_split_bash_words(char const *s);
int		ft_wawa(int ac, char *av[], char *ev[]);
int		parse_flags(char **flags);
int		parse_word(char *bash_word);

void	ft_print_split(char **splitted);
void	ft_print_cmd_el(t_command *command);
void	ft_print_text_read_el(t_text_read *text_read);
void	ft_print_text_read_tab(t_text_read **text_read);

char	**make_chartab(int n, ...);

t_command	**parse_line(char *lineread);
#endif
