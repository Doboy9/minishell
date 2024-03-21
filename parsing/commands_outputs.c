/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_outputs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 09:18:15 by wneel             #+#    #+#             */
/*   Updated: 2024/03/21 15:28:15 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wawa.h"

t_output	*init_output(t_command *command, int outputs)
{
	command->outputs[outputs] = malloc(sizeof(t_output));
	command->outputs[outputs]->append = 0;
	command->outputs[outputs]->file_fd = 0;
	command->outputs[outputs]->file_path = 0;
	command->outputs[outputs]->output_type = 0;
	return (command->outputs[outputs]);
}

void	alloc_cmd_outputs(
	t_text_read	**text_read,
	t_cmd_cursor *cursors,
	t_command *command
)
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
	if (outputs == 0)
		outputs++;
	command->outputs = NULL;
	command->outputs = ft_calloc(outputs + 1, sizeof(t_output *));
}

void	alloc_each_cmd_output(
	t_text_read	**text_read,
	t_cmd_cursor *cursors,
	t_command *command
)
{
	int	outputs;
	int	i;

	i = cursors->start;
	outputs = 0;
	while (i < cursors->end)
	{
		if (text_read[i]->is_metachar == ANGLE_BRACE_RIGHT)
		{
			command->outputs[outputs] = NULL;
			command->outputs[outputs] = init_output(command, outputs);
			outputs++;
		}
		if (text_read[i]->is_metachar == DOUBLE_ANGLE_BRACE_RIGHT)
		{
			command->outputs[outputs] = NULL;
			command->outputs[outputs] = init_output(command, outputs);
			outputs++;
		}
		i++;
	}
}

void	set_files_outputs(
	t_text_read	**text_read,
	t_cmd_cursor *cursors,
	t_command *command, int	*outputs)
{
	int	i;

	i = cursors->start;
	while (i < cursors->end)
	{
		if (text_read[i]->is_metachar == ANGLE_BRACE_RIGHT)
		{
			command->outputs[*outputs]->output_type = FILE_OUTPUT;
			command->outputs[*outputs]->file_path
				= ft_strdup(text_read[i + 1]->exp_text);
			command->outputs[*outputs]->append = 0;
			*outputs += 1;
		}
		if (text_read[i]->is_metachar == DOUBLE_ANGLE_BRACE_RIGHT)
		{
			command->outputs[*outputs]->output_type = FILE_OUTPUT;
			command->outputs[*outputs]->file_path
				= ft_strdup(text_read[i + 1]->exp_text);
			command->outputs[*outputs]->append = 1;
			*outputs += 1;
		}
		i++;
	}
}

void	set_cmd_outputs(
	t_text_read	**text_read,
	t_cmd_cursor *cursors,
	t_command *command
)
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
	command->outputs[outputs] = NULL;
	command->outputs[outputs] = init_output(command, outputs);
	if (text_read[cursors->end] == NULL)
		command->outputs[outputs]->output_type = STANDARD_OUTPUT;
	if (text_read[cursors->end] != NULL)
		command->outputs[outputs]->output_type = PIPE_OUTPUT;
}
