/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wawa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:50:27 by wneel             #+#    #+#             */
/*   Updated: 2024/03/15 16:10:03 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wawa.h"

const char	*word_cutters = " \t\n|&()<>";

int	ft_is_word_cutter(const char *str, int index)
{
	int				i;
	int				j;
	int				is_word_cutter;
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
	return (text_read);
}

int	exec_line(int ac, char *av[], char *ev[], char *lineread)
{
	t_text_read	**text_read;
	int			i;

	(void)ac;
	(void)av;
	(void)ev;
	text_read = NULL;
	text_read = parse_read_input(lineread);
	ft_print_text_read(text_read);
	i = 0;
	while (text_read[i])
	{
		if (!is_well_quoted(text_read[i]->raw_text))
			return (0);
		text_read[i]->raw_text = expand_vars(text_read[i]->raw_text);
		i++;
	}
	ft_print_text_read(text_read);
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

int	var_name_end(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isalnum(str[i]) || str[i] == '_')
		{
			i++;
			continue ;
		}
		return (i);
	}
	return (i);
}

int	calc_expanded_size(char *str)
{
	t_quote_status	quote_status;
	char			*evar_value;
	char			*evar;
	int				chr;
	int				j;
	int				i;

	ft_init_quote_status(&quote_status);
	i = 0;
	j = 0;
	while (str[i])
	{
		update_quote_status(str[i], &quote_status);
		if (str[i] == '$' && !quote_status.in_squotes)
		{
			chr = var_name_end(&str[j + 1]);
			evar = ft_substr(str, i + 1, chr);
			evar_value = getenv(evar);
			j += ft_strlen(evar_value) - 1;
			i += ft_strlen(evar);
		}
		i++;
		j++;
	}
	return (j);
}

void	assign_evar(char *str, char *expanded_char, int *j, int *k)
{
	char	*evar_value;
	char	*evar;
	int		chr;
	int		l;

	l = 0;
	chr = var_name_end(&str[*j + 1]);
	evar = ft_substr(str, *j + 1, chr);
	evar_value = getenv(evar);
	printf("\nchr: %d, evar: _%s_ value: %s sreach from : '%s', j: \
			%d\n", chr, evar, evar_value, &str[*j], *j);
	while (evar_value && evar_value[l])
	{
		expanded_char[*k] = evar_value[l];
		*k += 1;
		l++;
	}
	*k -= 1;
	*j += ft_strlen(evar);
}

char	*expand_vars(char *str)
{
	t_quote_status	quote_status;
	char			*expanded_char;
	int				exp_size;
	int				k;
	int				j;

	ft_init_quote_status(&quote_status);
	exp_size = calc_expanded_size(str);
	expanded_char = ft_calloc(exp_size + 1, sizeof(char));
	j = 0;
	k = 0;
	while (str[j])
	{
		update_quote_status(str[j], &quote_status);
		if (str[j] == '$' && !quote_status.in_squotes)
			assign_evar(str, expanded_char, &j, &k);
		else
			expanded_char[k] = str[j];
		j++;
		k++;
	}
	free(str);
	return (expanded_char);
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
			exec_line(ac, av, ev, "< $XDD | $echo xd | cat");
		else if (lineread[0] == 50)
			exec_line(ac, av, ev, "< xdfile | echo sltcv2 > mdrfile \
				| echo \"fail2 > failfile | echo ouicv2 > mdrfile2 | cat");
		else if (lineread[0] == 51)
			exec_line(ac, av, ev, "echo \"\"xdxd\"$VARW\"");
		else
			exec_line(ac, av, ev, lineread);
		printf("\n");
		add_history(lineread);
		if (lineread[0] != 49)
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
