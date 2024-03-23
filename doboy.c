/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doboy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:18:54 by dboire            #+#    #+#             */
/*   Updated: 2024/03/23 13:46:10 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doboy.h"
#include "wawa.h"

int	ft_doboy(int ac, char *av[], char *ev[])
{
	const char	*prompt;
	char		*lineread;
	t_command	**command_tab;
	t_envexp	*envexp;

	(void)ac;
	(void)av;
	(void)ev;
	envexp = ft_calloc(1, sizeof(t_envexp));
	prompt = "minishell >";
	lineread = readline(prompt);
	while (lineread)
	{
		command_tab = parse_line(lineread);
		printf("\n");
		add_history(lineread);
		envexp = ft_envexp(ev, envexp);
		ft_pipex(ac, command_tab, envexp);
		{
			int	i = 0;
			while (command_tab[i])
			{
				ft_print_cmd_el(command_tab[i]);
				i++;
			}
		}
		free(lineread);
		lineread = readline(prompt);
	}
	return (0);
}