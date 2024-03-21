/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wawa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:50:27 by wneel             #+#    #+#             */
/*   Updated: 2024/03/21 15:20:03 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wawa.h"

void	set_argc(t_text_read	**text_read, t_cmd_cursor *cursors, t_command *command)
{
	int	argc;
	int	i;

	i = cursors->start;
	argc = 0;
	while (i < cursors->end)
	{
		if (is_redirection(text_read[i]))
			i	++;
		else
			argc++;
		i++;
	}
	command->argc = argc;
}

void	set_cmd_args(t_text_read	**text_read, t_cmd_cursor *cursors, t_command *command)
{
	int	ac;
	int	i;

	i = cursors->start;
	ac = 0;
	set_argc(text_read, cursors, command);
	command->argv = NULL;
	command->argv = ft_calloc(command->argc + 1, sizeof(char *));
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
	//ft_print_cmd_el(command);
	return (command);
}

t_command	**make_command_tab(t_text_read	**text_read)
{
	t_cmd_cursor	cmd_cursors;
	t_command	**command_tab;
	int			command_count;
	int			i;

	i = 0;
	command_count = get_command_count(text_read);
	command_tab = ft_calloc(command_count + 1, sizeof(t_command *));
	cmd_cursors.start = 0;
	cmd_cursors.end = 0;
	while (command_count > 0)
	{
		command_tab[i] = make_command(&cmd_cursors, text_read);
		command_count--;
		cmd_cursors.start = cmd_cursors.end + 1;
		i++;
	}
	return (command_tab);
}

t_command	**parse_line(char *lineread)
{
	t_text_read	**text_read;
	t_command	**command_tab = NULL;
	int				error_status;

	error_status = 0;
	text_read = NULL;
	text_read = parse_read_input(lineread);
	text_read = parse_variables(text_read, &error_status);
	text_read = parse_extra_quotes(text_read);

	command_tab = make_command_tab(text_read);

	{
		int	i = 0;
		while (command_tab[i])
		{
			ft_print_cmd_el(command_tab[i]);
			i++;
		}
	}

	// if (!error_status)
	free_text_read(text_read);
	return (command_tab);
}

void	test_dash_n(void)
{
	char	**testargs;
	int		x;

	x = 0;
	testargs = NULL;
	testargs = make_chartab(5, "echo", "-n", "'salut'$XDD",
			"\"les $NOOB XD", "\"XPTDRRRRRRRRRRRRRRRRRRRRRRRRR haha jss plie \
			de rire XD $NOOB is nnob\"");
	while (testargs[x])
	{
		printf("%s\n", expand_vars(testargs[x]));
		x++;
	}
}

void	free_output_tab(t_output **output)
{
	int	i;

	i = 0;
	while (output[i])
	{
		if (output[i]->file_path != NULL)
			free(output[i]->file_path);
		free(output[i]);
		i++;
	}
	free(output);
}

void	free_input_tab(t_input **input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i]->file_path != NULL)
			free(input[i]->file_path);
		free(input[i]);
		i++;
	}
	free(input);
}

void	free_cmd_el(t_command	*command)
{
	free_tab(command->argv);
	free(command->command);
	free_input_tab(command->inputs);
	free_output_tab(command->outputs);
	free(command);
}

void	free_command_tab(t_command	**command_tab)
{
	int	i;

	i = 0;
	while (command_tab[i])
	{
		free_cmd_el(command_tab[i]);
		i++;
	}
	free(command_tab);
}

int	ft_wawa(int ac, char *av[], char *ev[])
{
	const char	*prompt;
	char		*lineread;
	t_command	**command_tab;

	(void)ac;
	(void)av;
	(void)ev;
	prompt = "easyshell XD >";
	lineread = readline(prompt);
	command_tab = NULL;
	while (lineread)
	{
		if (lineread[0] == 49)
			command_tab = parse_line("< infile | echo xd | cat");
		else if (lineread[0] == 50)
			command_tab = parse_line("< xdfile | echo sltcv2 > mdrfile \
				| echo \"fail2 > failfile | echo ouicv2 > mdrfile2 | cat");
		else if (lineread[0] == 51)
			command_tab = parse_line("echo \"\"xdxd\"$VARW\"");
		else
			command_tab = parse_line(lineread);
		printf("\n");
		add_history(lineread);
		free(lineread);
		free_command_tab(command_tab);
		lineread = readline(prompt);
	}
	return (0);
}

int	only_n(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	parse_flags(char **flags)
{
	static int	xd = 0;
	int			i;
	int			j;

	i = 0;
	while (flags[i])
	{
		if (flags[i][0] != '-')
			break ;
		j = 1;
		if (!only_n(&flags[i][1]))
			break ;
		printf("xd: %d _%s_\n", xd, flags[i]);
		i++;
	}
	printf("\n");
	xd++;
	return (0);
}
