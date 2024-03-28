/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doboy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:18:54 by dboire            #+#    #+#             */
/*   Updated: 2024/03/28 16:14:54 by dboire           ###   ########.fr       */
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
	envexp = ft_envexp(ev, envexp);
	prompt = "minishell >";
	lineread = readline(prompt);
	command_tab = NULL;
	while (lineread)
	{
		command_tab = parse_line(lineread);
		ft_pipex(ac, command_tab, envexp);
		{
			int	i = 0;
			while (command_tab[i])
			{
				printf("Commande : %d\n", i);
				// if (command_tab[i]->inputs[i]->file_path)
				// 	printf("Commande : %s\n", command_tab[i]->inputs[i]->file_path);
				ft_print_cmd_el(command_tab[i]);
				// if (command_tab[i]->outputs[i]->file_path)
				// 	printf("Commande : %s\n", command_tab[i]->outputs[i]->file_path);
				i++;
			}
		}
		printf("\n"); // Ne pas mettre le printf quand il y a un here_doc et erreur
		add_history(lineread);
		free(lineread);
		free_command_tab(command_tab);
		lineread = readline(prompt);
	}
	return (0);
}
