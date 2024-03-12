/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wawa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:50:27 by wneel             #+#    #+#             */
/*   Updated: 2024/03/12 19:50:27 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wawa.h"

const	char *word_cutters = " \t\n|&()<>"; // blank => https://www.gnu.org/software/bash/manual/bash.html#Definitions

int	reverse_bool(int bool)
{
	if (bool == 0)
		return (1);
	return (0);
}

void	update_quote_status(char c, t_quote_status *quote_status)
{
	if (c == '\'' && !quote_status->in_dquotes)
		quote_status->in_squotes = reverse_bool(quote_status->in_squotes);
	if (c == '"' && !quote_status->in_squotes)
		quote_status->in_dquotes = reverse_bool(quote_status->in_dquotes);
}

void ft_init_quote_status(t_quote_status	*quote_status)
{
	quote_status->in_dquotes = 0;
	quote_status->in_squotes = 0;
}

int	ft_is_word_cutter(const char *str, int index)
{
	int	i;
	int	j;
	int	is_word_cutter;
	t_quote_status	quote_status;

	i = 0;
	j = 0;
	is_word_cutter = 0;
	ft_init_quote_status(&quote_status);
	while (i < index)
	{
		update_quote_status(str[i], &quote_status);
		i++;
	}
	while (word_cutters[j] != '\0')
	{
		if (word_cutters[j] == str[i])
			is_word_cutter = 1;
		j++;
	}
	if (quote_status.in_dquotes || quote_status.in_squotes)
		is_word_cutter = 0;
	return (is_word_cutter);
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

enum SPECIAL_CHARACTERS {
	TEXT = 0,
	PIPE = 1,
	ANGLE_BRACE_LEFT = 2,
	ANGLE_BRACE_RIGHT = 3,
	DOUBLE_ANGLE_BRACE_LEFT = 4,
	DOUBLE_ANGLE_BRACE_RIGHT = 5
};

int	parse_word(char *bash_word)
{
	int	word_len;

	word_len = ft_strlen(bash_word);
	if (word_len == 1)
	{
		if (bash_word[0] == '|')
			return (PIPE);
		if (bash_word[0] == '<')
			return (ANGLE_BRACE_LEFT);
		if (bash_word[0] == '>')
			return (ANGLE_BRACE_RIGHT);
	}
	if (word_len == 2)
	{
		if (bash_word[0] == '<' && bash_word[1] == '<')
			return (DOUBLE_ANGLE_BRACE_LEFT);
		if (bash_word[0] == '>' && bash_word[1] == '>')
			return (DOUBLE_ANGLE_BRACE_RIGHT);
	}
	return (TEXT);
}

int	char_tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_print_text_read(t_text_read **text_read)
{
	int	i;

	i = 0;
	while (text_read[i])
	{
		printf("\n{\n	text : %s;\n	mchar: %d;\n	attr : %d;\n}\n", text_read[i]->raw_text, text_read[i]->is_metachar, text_read[i]->is_attribution);
		i++;
	}
}

int	ft_main(int ac, char *av[], char *ev[], char *lineread)
{
	(void)ac;
	(void)av;
	(void)ev;
	t_quote_status	quote_status;
	ft_init_quote_status(&quote_status);

	int i = 0;
	while (lineread[i] != '\0')
	{
		update_quote_status(lineread[i], &quote_status);
		if ((quote_status.in_dquotes && lineread[i] != '"') || (quote_status.in_squotes && lineread[i] != '\''))
		{
			printf("%c", lineread[i]);
		}
		i++;
	}

	// i = 0;
	// ft_init_quote_status(&quote_status);
	// while (cmd[i] != '\0')
	// {
	// 	update_quote_status(cmd[i], &quote_status);
	// 	int is_word_cutter = ft_is_word_cutter(cmd, i);
	// 	if (quote_status.in_dquotes || quote_status.in_squotes)
	// 		is_word_cutter = 0;
	// 	i++;
	// }
	char **bash_splitted = ft_split_bash_words(lineread);
	ft_print_split(bash_splitted);
	i = 0;
	t_text_read		**text_read = NULL;
	text_read = ft_calloc(char_tab_len(bash_splitted) + 1, sizeof(t_text_read *));
	while (bash_splitted[i])
	{
		t_text_read *splitted = malloc(sizeof(t_text_read));
		splitted->raw_text = bash_splitted[i];
		splitted->is_metachar = parse_word(bash_splitted[i]);
		splitted->is_attribution = 0x667;
		text_read[i] = splitted;
		i++;
	}

	ft_print_text_read(text_read);

	return (0);
}

int parse_flags(char **flags);
char	**make_chartab(int n, ...);

int	is_well_quoted(char *str)
{
	int	strlen;

	strlen = ft_strlen(str);
	if (str[0] == '\"' && str[strlen - 1] != '\"')
		return (0);
	if (str[0] == '\'' && str[strlen - 1] != '\'')
		return (0);
	return (1);
}

int	is_d_quoted(char *str)
{
	int	strlen;

	strlen = ft_strlen(str);
	if (str[0] == '\"' && str[strlen - 1] == '\"')
		return (1);
	return (0);
}

int	ft_char_next_index(char *str, char to_find)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == to_find)
			return (i);
		if (str[i] != to_find)
			i++;
	}
	return (-1);
}

void expand_vars()
{
	char **testargs = make_chartab(5, "echo", "-n", "'salut'", "\"les $NOOB XD", "\"XPTDRRRRRRRRRRRRRRRRRRRRRRRRR haha jss plie de rire XD $NOOB is nnob\"");

	int	i;
	i = 0;
	while (testargs[i])
	{
		if (!is_d_quoted(testargs[i]))
		{
			i++;
			continue ;
		}
		int	j;

		j = 0;
		while (testargs[i][j])
		{
			if (testargs[i][j] == '$')
			{
				int chr = ft_char_next_index(&testargs[i][j], ' ');
				//int	k = 0;


				// printf("\n_%s_\n", ft_substr(testargs[i], j + 1, chr - 1));
				ft_putstr_fd(getenv(ft_substr(testargs[i], j + 1, chr - 1)), 1);


				// printf("\nj: %d chr: %d\n", j, chr);
			}
			else
				ft_putchar_fd(testargs[i][j], 1);
			j++;
		}

		i++;
	}

	// printf("\n%s\n", getenv("NOOB"));
}

int	ft_wawa(int ac, char *av[], char *ev[])
{
	(void)ac;
	(void)av;
	(void)ev;
	t_quote_status	quote_status;
	ft_init_quote_status(&quote_status);
	const char *prompt = "easyshell XD >";
	char *lineread = readline(prompt);
	while (lineread)
	{
		//printf("%s", lineread);
		if (lineread[0] == 49)
			ft_main(ac, av, ev, "< test | $echo xd | cat");
		else
			ft_main(ac, av, ev, lineread);
		printf("\n");
		//rl_on_new_line();
		add_history(lineread);
		if (lineread[0] != 49)
			free(lineread);
		lineread = readline(prompt);
	}


	return (0);
}
char	**make_chartab(int n, ...)
{
	int		i;
	char	**output;
	va_list	params;

	i = 0;
	output = ft_calloc(n + 1, sizeof(char *));
	va_start(params, n);
	while (i < n)
	{
		char *arg = va_arg(params, char *);
		output[i] = ft_calloc(ft_strlen(arg) + 1, sizeof(char));
		ft_memcpy(output[i], arg, ft_strlen(arg));
		i++;
	}
	va_end(params);
	return (output);
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

int parse_flags(char **flags)
{
	static int xd = 0;
	int	i;
	int	j;

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
	return 0;
}
