/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wawa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:50:27 by wneel             #+#    #+#             */
/*   Updated: 2024/03/07 09:22:03 by wneel            ###   ########.fr       */
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

int	ft_main(int ac, char *av[], char *ev[], char *lineread)
{
	(void)ac;
	(void)av;
	(void)ev;
	//char *cmd = "echo '\"Salut les me&cs\"'\n";
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
	// ft_print_split(ft_split_bash_words(cmd));
	return (0);
}

int	ft_wawa(int ac, char *av[], char *ev[])
{
	(void)ac;
	(void)av;
	(void)ev;
	// char *cmd = "echo ()('\"Salut les me&cs\"')\n";
	// t_quote_status	quote_status;
	// ft_init_quote_status(&quote_status);
	// printf("%s", cmd);
	const char *prompt = "easyshell XD >";
	char *lineread = readline(prompt);
	while (lineread)
	{
		//printf("%s", lineread);
		ft_main(ac, av, ev, lineread);
		printf("\n");
		//rl_on_new_line();
		add_history(lineread);
		free(lineread);
		lineread = readline(prompt);
	}

	return (0);
}
