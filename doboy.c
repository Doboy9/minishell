/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doboy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:13:22 by dboire            #+#    #+#             */
/*   Updated: 2024/03/14 17:08:01 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doboy.h"

int	ft_doboy(int ac, char *av[], char *ev[])
{
	// (void)ac;
	// (void)av;
	// (void)ev;
	// const char *prompt = "easyshell XD >";
	// char *lineread = readline(prompt);
	// while (lineread)
	// {
		// if (lineread[0] == 49)
		// 	exec_line(ac, av, ev, "< $XDD | $echo xd | cat");
		// else if (lineread[0] == 50)
		// 	exec_line(ac, av, ev, "< xdfile | echo sltcv2 > mdrfile | echo \"fail2 > failfile | echo ouicv2 > mdrfile2 | cat");
		// else
		// 	exec_line(ac, av, ev, lineread);
		
		
		
		ft_builtins(ac, av, ev);
		printf("\n");
	// 	add_history(lineread);
	// 	if (lineread[0] != 49)
	// 		free(lineread);
	// 	lineread = readline(prompt);
	// }
	return (0);
}