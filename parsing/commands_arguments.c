/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:03:27 by wneel             #+#    #+#             */
/*   Updated: 2024/03/22 15:07:02 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wawa.h"

void	set_argc(
	t_text_read	**text_read,
	t_cmd_cursor *cursors,
	t_command *command
)
{
	int	argc;
	int	i;

	i = cursors->start;
	argc = 0;
	while (i < cursors->end)
	{
		if (is_redirection(text_read[i]))
			i ++;
		else
			argc++;
		i++;
	}
	command->argc = argc;
}

void	set_cmd_args(
	t_text_read	**text_read,
	t_cmd_cursor *cursors,
	t_command *command
)
{
	int	ac;
	int	i;

	i = cursors->start;
	ac = 0;
	set_argc(text_read, cursors, command);
	command->argv = NULL;
	command->argv = ft_calloc(command->argc + 1, sizeof(char *));
	command->command = NULL;
	while (i < cursors->end)
	{
		if (is_redirection(text_read[i]))
			i++;
		else
		{
			if (ac == 0)
				command->command = ft_strdup(text_read[i]->exp_text);
			command->argv[ac] = ft_strdup(text_read[i]->exp_text);
			ac++;
		}
		i++;
	}
}

t_command	*make_command(t_cmd_cursor	*cmd_cursors, t_text_read	**text_read)
{
	t_command	*command;

	command = NULL;
	command = malloc(sizeof(t_command));
	cmd_cursors->end = get_last_token_idx(text_read, cmd_cursors);
	set_cmd_inputs(text_read, cmd_cursors, command);
	set_cmd_outputs(text_read, cmd_cursors, command);
	set_cmd_args(text_read, cmd_cursors, command);
	return (command);
}
