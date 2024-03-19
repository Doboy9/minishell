/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wawa_printers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:53:18 by wneel             #+#    #+#             */
/*   Updated: 2024/03/19 16:01:21 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wawa.h"


void	ft_print_input_el(t_input *input)
{
	printf("\n{\n	file_fd: %d;\n	path   : %s;\n	input  : %d;\n}\n",
			input->file_fd, input->file_path, input->input_type);
}

void	ft_print_input_tab(t_input **input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		ft_print_input_el(input[i]);
		i++;
	}
}

void	ft_print_output_el(t_output *output)
{
	printf("\n{\n	file_fd: %d;\n	path   : %s;\n	output  : %d;\n	append  : %d;\n}\n",
			output->file_fd, output->file_path, output->output_type, output->append);
}

void	ft_print_output_tab(t_output **output)
{
	int	i;

	i = 0;
	while (output[i])
	{
		ft_print_output_el(output[i]);
		i++;
	}
}

void	ft_print_cmd_el(t_command *command)
{
	printf("\n{\n	argc : %d;\n	argv:\n", command->argc);
	ft_print_split(command->argv);
	printf("\n	command : %s;\n}\n", command->command);
	ft_print_input_tab(command->inputs);
	ft_print_output_tab(command->outputs);
}

void	ft_print_text_read_el(t_text_read *text_read)
{
	printf("\n{\n	text : %s;\n	mchar: %d;\n	attr : %d;\n}\n",
		text_read->exp_text, text_read->is_metachar,
		text_read->is_attribution);
}

void	ft_print_text_read_tab(t_text_read **text_read)
{
	int	i;

	i = 0;
	while (text_read[i])
	{
		printf("\n{\n	text : %s;\n	mchar: %d;\n	attr : %d;\n}\n",
			text_read[i]->exp_text, text_read[i]->is_metachar,
			text_read[i]->is_attribution);
		i++;
	}
}

void	ft_print_split(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
	{
		printf("_%s_\n", splitted[i]);
		i++;
	}
}
