/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_inputs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 09:17:26 by wneel             #+#    #+#             */
/*   Updated: 2024/03/20 09:17:41 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wawa.h"

void	alloc_cmd_inputs(t_text_read	**text_read, t_cmd_cursor *cursors, t_command *command)
{
	int	inputs;
	int	i;

	i = 0;
	inputs = 0;
	while (i < cursors->end)
	{
		if (text_read[i]->is_metachar == ANGLE_BRACE_LEFT)
			inputs++;
		if (text_read[i]->is_metachar == DOUBLE_ANGLE_BRACE_LEFT)
			inputs++;
		i++;
	}
	command->inputs = NULL;
	command->inputs = ft_calloc(inputs + 1, sizeof(t_output *));
}

void	alloc_each_cmd_input(t_text_read	**text_read, t_cmd_cursor *cursors, t_command *command)
{
	int	inputs;
	int	i;

	i = 0;
	inputs = 0;
	while (i < cursors->end)
	{
		if (text_read[i]->is_metachar == ANGLE_BRACE_LEFT)
		{
			command->inputs[inputs] = malloc(sizeof(t_input));
			inputs++;
		}
		if (text_read[i]->is_metachar == DOUBLE_ANGLE_BRACE_LEFT)
		{
			command->inputs[inputs] = malloc(sizeof(t_input));
			inputs++;
		}
		i++;
	}
}

void	set_cmd_inputs(t_text_read	**text_read, t_cmd_cursor *cursors, t_command *command)
{
	int	cmd;
	int	i;

	i = 0;
	cmd = 0;
	alloc_cmd_inputs(text_read, cursors, command);
	alloc_each_cmd_input(text_read, cursors, command);
	while (i < cursors->end)
	{
		if (text_read[i]->is_metachar == ANGLE_BRACE_LEFT)
		{
			command->inputs[cmd]->input_type = FILE_INPUT;
			command->inputs[cmd]->file_path = text_read[i + 1]->exp_text;
			cmd++;
		}
		if (text_read[i]->is_metachar == DOUBLE_ANGLE_BRACE_LEFT)
		{
			command->inputs[cmd]->input_type = HERE_DOC_INPUT;
			command->inputs[cmd]->file_path = text_read[i + 1]->exp_text;
			cmd++;
		}
		i++;
	}
}