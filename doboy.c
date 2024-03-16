/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doboy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:13:22 by dboire            #+#    #+#             */
/*   Updated: 2024/03/16 16:49:44 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doboy.h"

int	ft_doboy(int ac, char *av[], char *ev[])
{
	(void)ac;
	(void)av;
	(void)ev;
	const char	*prompt;
	char		*lineread;
	t_envexp *envexp;
	
	envexp = ft_calloc(sizeof(t_envexp), 1);
	prompt = "easyshell -_- >";
	lineread = readline(prompt);
	while (lineread)
	{
		if (ft_strncmp(lineread, "env", 3) == 0)
			ft_copyenv(ev, envexp);
		else if (ft_strncmp(lineread, "export", 6) == 0)
			ft_copyexp(ev, envexp);
		else if (ft_strncmp(lineread, "pwd", 3) == 0)
			printf("%s\n", getcwd(NULL, 0)); //ok, works
		else if (ft_strncmp(lineread, "cd", 2) == 0) // Besoin de split le line read pour avoir le path
			chdir("/nfs/homes"); //ok, working but need modif
		else if (ft_strncmp(lineread, "echo", 4) == 0) // Besoin de split le lineread pour avoir ce qu il faut ecrire
			printf("%s\n", lineread); // ok, working but need modif
		else if (ft_strncmp(lineread, "exit", 4) == 0) // Function to free everything needed
			exit(0); //ok, working but need modif
		else
			printf("%s: command not found\n", lineread); //ok, works
		add_history(lineread);
		free(lineread);
		lineread = readline(prompt);
	}
	return (0);
}