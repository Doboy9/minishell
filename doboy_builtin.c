/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doboy_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:45:12 by dboire            #+#    #+#             */
/*   Updated: 2024/03/16 16:25:28 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doboy.h"

void	ft_builtins(int ac, char *av[], char *ev[])
{
	(void)ac;
	(void)av;
	(void)ev;

	if (ft_strncmp(av[1], "echo", 4) == 0)
	{
		printf("%s", av[2]);
		//if (-n == 0)
			//printf("\n");
	}
	if (ft_strncmp(av[1], "exit", 4) == 0)
	{
		// free all;
		printf("Exiting..");
		exit(0);
	}
	if (ft_strncmp(av[1], "cd", 2) == 0)
	{
		ft_changedir(ac, av);
	}
	if (ft_strncmp(av[1], "pwd", 3) == 0)
	{
		getcwd(NULL, 0);
	}
	if (ft_strncmp(av[1], "env", 3) == 0)
	{
		//while(ev[i])
		//{
			//printf("%s", ev[i]);
		// 	i++;
		//}
	}
	if (ft_strncmp(av[1], "export", 6) == 0)
	{
		// ft_export(); //We need to check it constantly when $ is called
	}
}

void	ft_changedir(int ac, char *av[]) // See whether the chdir changes pwd in env, if it does, remove the function
{
	(void)ac;
	
	chdir(av[2]);
}

int	find_pwd(char **env)
{
	int		i;
	int		y;
	char	*pwd;

	pwd = ft_calloc(sizeof(char), 5);
	ft_strlcpy(pwd, "PWD", 3);
	i = 0;
	y = 0;
	while (env[i])
	{
		while (env[i][y] == pwd[y])
			y++;
		if (pwd[y] == '\0')
		{
			free(pwd);
			return (i);
		}
		else
			y = 0;
		i++;
	}
	free(pwd);
	return (-1);
}