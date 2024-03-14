/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wawa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:50:27 by wneel             #+#    #+#             */
/*   Updated: 2024/03/14 17:31:49 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wawa.h"

int parse_flags(char **flags);
char	**make_chartab(int n, ...);

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

int	is_well_quoted(char *str)
{
	int	i;
	t_quote_status	quote_status;

	ft_init_quote_status(&quote_status);
	i = 0;
	while (str[i] != '\0')
	{
		update_quote_status(str[i], &quote_status);
		i++;
	}
	if (quote_status.in_dquotes)
		printf("dquote issue here => %s", str);
	if (quote_status.in_squotes)
		printf("squote issue here =>  %s", str);
	if (quote_status.in_dquotes || quote_status.in_squotes)
		return (0);
	return (1);
}

int	exec_line(int ac, char *av[], char *ev[], char *lineread)
{
	(void)ac;
	(void)av;
	(void)ev;
	int		i;
	t_quote_status	quote_status;
	ft_init_quote_status(&quote_status);
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
	t_quote_status quote_status;
	int	i;
	int j;

	ft_init_quote_status(&quote_status);
	i = 0;
	j = 0;
	while (str[i])
	{
		update_quote_status(str[i], &quote_status);
		if (str[i] == '$' && !quote_status.in_squotes)
		{
			int chr = var_name_end(&str[j + 1]);

			char *evar = ft_substr(str, i + 1, chr);
			char *evar_value = getenv(evar);
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
	printf("\nchr: %d, evar: _%s_ value: %s sreach from : '%s', j: %d\n", chr, evar, evar_value, &str[*j], *j);
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
	t_quote_status quote_status;
	int	j;
	int k;
	char *expanded_char;

	ft_init_quote_status(&quote_status);
	int exp_size = calc_expanded_size(str);
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

		{
			int x = 0;
			char **testargs = make_chartab(5, "echo", "-n", "'salut'$XDD", "\"les $NOOB XD", "\"XPTDRRRRRRRRRRRRRRRRRRRRRRRRR haha jss plie de rire XD $NOOB is nnob\"");
			while (testargs[x])
			{
				printf("%s\n", expand_vars(testargs[x]));
				x++;
			}

		}

		//printf("%s", lineread);
		if (lineread[0] == 49)
			exec_line(ac, av, ev, "< $XDD | $echo xd | cat");
		else if (lineread[0] == 50)
			exec_line(ac, av, ev, "< xdfile | echo sltcv2 > mdrfile | echo \"fail2 > failfile | echo ouicv2 > mdrfile2 | cat");
		else if (lineread[0] == 51)
			exec_line(ac, av, ev, "echo \"\"xdxd\"$VARW\"");
		else
			exec_line(ac, av, ev, lineread);
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
