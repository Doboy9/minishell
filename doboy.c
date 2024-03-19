/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doboy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:18:54 by dboire            #+#    #+#             */
/*   Updated: 2024/03/19 16:20:25 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doboy.h"

int	ft_doboy(int ac, char *av[], char *ev[])
{
	(void)ac;
	(void)av;
	(void)ev;
	int i = 0;
	const char	*prompt;
	char		*lineread;
	char		**lineread_split;
	
	prompt = "easyshell -_- >";
	lineread = readline(prompt);
	lineread_split = ft_split(lineread, ' ');
	while(lineread_split[i])
		i++;
	while (lineread)
	{
		ft_pipex(i, lineread_split, ev);
		add_history(lineread);
		free(lineread);
		lineread = readline(prompt);
	}
	return (0);
}