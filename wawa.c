/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wawa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:50:27 by wneel             #+#    #+#             */
/*   Updated: 2024/03/16 11:24:39 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wawa.h"

t_text_read	**parse_read_input(char *lineread)
{
	t_quote_status	quote_status;
	t_text_read		**text_read;
	t_text_read		*splitted;
	char			**bash_splitted;
	int				i;

	i = 0;
	text_read = NULL;
	ft_init_quote_status(&quote_status);
	bash_splitted = ft_split_bash_words(lineread);
	text_read = ft_calloc(char_tab_len(bash_splitted) + 1,
			sizeof(t_text_read *));
	while (bash_splitted[i])
	{
		splitted = malloc(sizeof(t_text_read));
		splitted->raw_text = bash_splitted[i];
		splitted->is_metachar = parse_word(bash_splitted[i]);
		splitted->is_attribution = 0x667;
		text_read[i] = splitted;
		i++;
	}
	free(bash_splitted);
	return (text_read);
}

t_text_read	**parse_variables(t_text_read	**text_read, int *error_status)
{
	int	i;

	i = 0;
	while (text_read[i])
	{
		if (!is_well_quoted(text_read[i]->raw_text))
		{
			*error_status = 1;
			return (text_read);
		}
		text_read[i]->raw_text = expand_vars(text_read[i]->raw_text);
		i++;
	}
	return (text_read);
}

void	free_text_read(t_text_read	**text_read)
{
	int	i;

	i = 0;
	while (text_read[i])
	{
		free(text_read[i]->raw_text);
		free(text_read[i]);
		i++;
	}
	free(text_read);
}

int	len_without_extra_quotes(char *str)
{
	t_quote_status	qstatus;
	int		last_qstatus;
	int		i;
	int		j;

	i = 0;
	j = 0;
	last_qstatus = 0;
	ft_init_quote_status(&qstatus);
	while (str[i] != '\0')
	{
		update_quote_status(str[i], &qstatus);
		if ((qstatus.in_dquotes || qstatus.in_squotes) == last_qstatus)
			j++;
		i++;
		last_qstatus = (qstatus.in_dquotes || qstatus.in_squotes);
	}
	return (j);
}

char	*remove_extra_quotes(char *str)
{
	t_quote_status	qstatus;
	char	*without_quotes;
	int		last_qstatus;
	int		i;
	int		j;

	i = 0;
	j = 0;
	last_qstatus = 0;
	without_quotes = ft_calloc(len_without_extra_quotes(str) \
		+ 1, sizeof(char));
	ft_init_quote_status(&qstatus);
	while (str[i] != '\0')
	{
		update_quote_status(str[i], &qstatus);
		if ((qstatus.in_dquotes || qstatus.in_squotes) == last_qstatus)
		{
			without_quotes[j] = str[i];
			j++;
		}
		i++;
		last_qstatus = (qstatus.in_dquotes || qstatus.in_squotes);
	}
	free(str);
	return (without_quotes);
}

t_text_read	**parse_extra_quotes(t_text_read	**text_read)
{
	int		i;

	i = 0;
	while (text_read[i])
	{
		text_read[i]->raw_text = remove_extra_quotes(text_read[i]->raw_text);
		i++;
	}
	return (text_read);
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
	if (!error_status)
		ft_print_text_read(text_read);
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
