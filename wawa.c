/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wawa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:50:27 by wneel             #+#    #+#             */
/*   Updated: 2024/03/20 10:45:21 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wawa.h"

void	set_argc(t_text_read	**text_read, t_cmd_cursor *cursors, t_command *command)
{
	int	argc;
	int	i;

	i = 0;
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

	i = 0;
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

int	exec_line(char *ev[], char *lineread)
{
	t_text_read	**text_read;
	int				error_status;

	(void)ev;
	error_status = 0;
	text_read = NULL;
	text_read = parse_read_input(lineread);
	text_read = parse_variables(text_read, &error_status);
	text_read = parse_extra_quotes(text_read);

	{
		t_cmd_cursor	cmd_cursors;
		t_command	**command_tab;
		int			command_count;

		command_count = get_command_count(text_read);
		command_tab = ft_calloc(command_count + 1, sizeof(t_command *));
		cmd_cursors.start = 0;
		cmd_cursors.end = 0;
		{
			t_command	*command;

			command = NULL;
			command = malloc(sizeof(t_command));
			cmd_cursors.end = get_last_token_idx(text_read, &cmd_cursors);
			set_cmd_inputs(text_read, &cmd_cursors, command);
			set_cmd_outputs(text_read, &cmd_cursors, command);
			set_cmd_args(text_read, &cmd_cursors, command);
			ft_print_cmd_el(command);
		}
	}

	// if (!error_status)
	// 	ft_print_text_read_tab(text_read);
	free_text_read(text_read);
	return (0);
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

int	ft_wawa(int ac, char *av[], char *ev[])
{
	const char	*prompt;
	char		*lineread;

	(void)ac;
	(void)av;
	(void)ev;
	prompt = "easyshell XD >";
	lineread = readline(prompt);
	while (lineread)
	{
		if (lineread[0] == 49)
			exec_line(ev, "< infile | echo xd | cat");
		else if (lineread[0] == 50)
			exec_line(ev, "< xdfile | echo sltcv2 > mdrfile \
				| echo \"fail2 > failfile | echo ouicv2 > mdrfile2 | cat");
		else if (lineread[0] == 51)
			exec_line(ev, "echo \"\"xdxd\"$VARW\"");
		else
			exec_line(ev, lineread);
		printf("\n");
		add_history(lineread);
		free(lineread);
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
