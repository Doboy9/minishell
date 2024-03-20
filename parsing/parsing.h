/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 09:18:57 by wneel             #+#    #+#             */
/*   Updated: 2024/03/20 10:17:11 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
#define PARSING_H
# include "../wawa.h"
# include "parsing_structs.h"

int		is_well_quoted(char *str);
char	*remove_extra_quotes(char *str);
void	ft_init_quote_status(t_quote_status *quote_status);
void	update_quote_status(char c, t_quote_status *quote_status);

int		var_name_end(char *str);
char	*expand_vars(char *str);
int		calc_expanded_size(char *str, int i);
void	assign_evar(char *str, char *expanded_char, int *j, int *k);

int		reverse_bool(int bool);
int		char_tab_len(char **tab);
int		is_redirection(t_text_read *el);
int		get_command_count(t_text_read	**text_read);
int		get_last_token_idx(t_text_read	**text_read, t_cmd_cursor *cursors);

void	free_text_read(t_text_read	**text_read);
t_text_read	**parse_read_input(char *lineread);
t_text_read	**parse_extra_quotes(t_text_read	**text_read);
t_text_read	**parse_variables(t_text_read	**text_read, int *error_status);

void	set_cmd_inputs(t_text_read	**text_read, t_cmd_cursor *cursors, t_command *command);
void	set_cmd_outputs(t_text_read	**text_read, t_cmd_cursor *cursors, t_command *command);
#endif
