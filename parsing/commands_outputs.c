/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_outputs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 09:18:15 by wneel             #+#    #+#             */
/*   Updated: 2024/03/20 11:51:35 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wawa.h"

void	alloc_cmd_outputs(t_text_read	**text_read, t_cmd_cursor *cursors, t_command *command)
{
	int	outputs;
	int	i;

	i = cursors->start;
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

	i = cursors->start;
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

void	set_files_outputs(t_text_read	**text_read, t_cmd_cursor *cursors, t_command *command, int	*outputs)
{
	int	i;

	i = cursors->start;
	while (i < cursors->end)
	{
		if (text_read[i]->is_metachar == ANGLE_BRACE_RIGHT)
		{
			command->outputs[*outputs]->output_type = FILE_OUTPUT;
			command->outputs[*outputs]->file_path = text_read[i + 1]->exp_text;
			command->outputs[*outputs]->append = 0;
			*outputs += 1;
		}
		if (text_read[i]->is_metachar == DOUBLE_ANGLE_BRACE_RIGHT)
		{
			command->outputs[*outputs]->output_type = FILE_OUTPUT;
			command->outputs[*outputs]->file_path = text_read[i + 1]->exp_text;
			command->outputs[*outputs]->append = 1;
			*outputs += 1;
		}
		i++;
	}
}

void	set_cmd_outputs(t_text_read	**text_read, t_cmd_cursor *cursors, t_command *command)
{
	int	outputs;
	int	i;

	i = cursors->start;
	outputs = 0;
	alloc_cmd_outputs(text_read, cursors, command);
	alloc_each_cmd_output(text_read, cursors, command);
	set_files_outputs(text_read, cursors, command, &outputs);
	if (outputs > 0)
		return ;
	command->outputs[outputs] = malloc(sizeof(t_output));
	if (text_read[cursors->end] == NULL)
		command->outputs[outputs]->output_type = STANDARD_OUTPUT;
	if (text_read[cursors->end] != NULL)
		command->outputs[outputs]->output_type = PIPE;
}
