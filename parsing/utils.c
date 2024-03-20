/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 09:21:02 by wneel             #+#    #+#             */
/*   Updated: 2024/03/20 09:29:43 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	reverse_bool(int bool)
{
	if (bool == 0)
		return (1);
	return (0);
}

int	char_tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	get_command_count(t_text_read	**text_read)
{
	int	command_count;
	int	i;

	i = 0;
	command_count = 1;
	while (text_read[i])
	{
		if (text_read[i]->is_metachar == PIPE)
			command_count += 1;
		i++;
	}
	return (command_count);
}

int	get_last_token_idx(t_text_read	**text_read, t_cmd_cursor *cursors)
{
	int	i;

	i = cursors->start;
	while (text_read[i])
	{
		if (text_read[i]->is_metachar == PIPE)
			return (i);
		i++;
	}
	return (i);
}

int	is_redirection(t_text_read *el)
{
	if (el->is_metachar == ANGLE_BRACE_LEFT)
		return (1);
	if (el->is_metachar == ANGLE_BRACE_RIGHT)
		return (1);
	if (el->is_metachar == DOUBLE_ANGLE_BRACE_LEFT)
		return (1);
	if (el->is_metachar == DOUBLE_ANGLE_BRACE_RIGHT)
		return (1);
	return (0);
}
