/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_outputs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 09:18:15 by wneel             #+#    #+#             */
/*   Updated: 2024/03/20 09:18:27 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wawa.h"

void	alloc_cmd_outputs(t_text_read	**text_read, t_cmd_cursor *cursors, t_command *command)
{
	int	outputs;
	int	i;

	i = 0;
	outputs = 0;
	while (i < cursors->end)
	{
		if (text_read[i]->is_metachar == ANGLE_BRACE_RIGHT)
			outputs++;
		if (text_read[i]->is_metachar == DOUBLE_ANGLE_BRACE_RIGHT)
			outputs++;
		i++;
	}
	command->outputs = NULL;
	command->outputs = ft_calloc(outputs + 1, sizeof(t_output *));
}

void	alloc_each_cmd_output(t_text_read	**text_read, t_cmd_cursor *cursors, t_command *command)
{
	int	outputs;
	int	i;

	i = 0;
	outputs = 0;
	while (i < cursors->end)
	{
		if (text_read[i]->is_metachar == ANGLE_BRACE_RIGHT)
		{
			command->outputs[outputs] = malloc(sizeof(t_output));
			outputs++;
		}
		if (text_read[i]->is_metachar == DOUBLE_ANGLE_BRACE_RIGHT)
		{
			command->outputs[outputs] = malloc(sizeof(t_output));
			outputs++;
		}
		i++;
	}
}

void	set_cmd_outputs(t_text_read	**text_read, t_cmd_cursor *cursors, t_command *command)
{
	int	cmd;
	int	i;

	i = 0;
	cmd = 0;
	alloc_cmd_outputs(text_read, cursors, command);
	alloc_each_cmd_output(text_read, cursors, command);
	while (i < cursors->end)
	{
		if (text_read[i]->is_metachar == ANGLE_BRACE_RIGHT)
		{
			command->outputs[cmd]->output_type = FILE_OUTPUT;
			command->outputs[cmd]->file_path = text_read[i + 1]->exp_text;
			command->outputs[cmd]->append = 0;
			cmd++;
		}
		if (text_read[i]->is_metachar == DOUBLE_ANGLE_BRACE_RIGHT)
		{
			command->outputs[cmd]->output_type = FILE_OUTPUT;
			command->outputs[cmd]->file_path = text_read[i + 1]->exp_text;
			command->outputs[cmd]->append = 1;
			cmd++;
		}
		i++;
	}
}
