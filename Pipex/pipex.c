/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:28:02 by dboire            #+#    #+#             */
/*   Updated: 2024/03/21 19:21:40 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../doboy.h"
#include "../wawa.h"

void	ft_pipex(int ac, t_command **command_tab, t_envexp *envexp)
{
	(void)ac;

	ft_is_here_doc(command_tab);
	ft_access(command_tab, envexp);

}

void	ft_is_here_doc(t_command **command_tab)
{
	int	i;
	
	i = 0;
	while(command_tab[i])
	{
		if (command_tab[i]->inputs[0] != NULL)
		{
			if(command_tab[i]->inputs[0]->input_type == 3)
				printf("here_doc\n");
		}
	i++;
	}
}

void	ft_access(t_command **command_tab, t_envexp *envexp)
{
	int		i;
	char	**split_path;
	(void)command_tab;

	i = 0;
	split_path = ft_split_path(envexp);
	while (command_tab[i])
	{
		if (!command_tab[i]->command)
			printf("no command ??");
		ft_check_access(split_path, command_tab, i);
	// 	// if ((!pipex->real_path[y]) && (!pipex->arg_final[y][0]))
	// 	// 	ft_printf(": command not found\n");
	// 	// if ((!pipex->real_path[y]) && (pipex->arg_final[y][0]))
	// 	// 	ft_printf("%s: command not found\n", pipex->arg_final[y][0]);
		i++;
	}
	return ;
}

void	ft_check_access(char **split_path, t_command **command_tab, int y)
{
	int	i;

	i = 0;
	while (split_path[i])
	{
		if (!command_tab[y]->command)
			return ;
		command_tab[y]->command_path = ft_strjoin(split_path[i], command_tab[y]->command);
		if (access(command_tab[y]->command_path, R_OK) == -1)
		{
			printf("non :");
			printf("%s\n", command_tab[y]->command_path);
			free(command_tab[y]->command_path);
			command_tab[y]->command_path = NULL;
		}
		else
		{
			printf("OUI :%s\n", command_tab[y]->command_path);
			return ;
		}
		i++;
	}
}

char	**ft_split_path(t_envexp *envexp)
{
	char	**split_path;
	char	*real_path;
	char	*first_path;
	int		i;
	
	i = find_path(envexp->envcopy);
	split_path = ft_split(envexp->envcopy[i], ':');
	i = 0;
	while (split_path[i])
	{
		real_path = ft_strjoin(split_path[i], "/");
		free(split_path[i]);
		split_path[i] = ft_strdup(real_path);
		free(real_path);
		i++;
	}
	first_path = ft_strtrim(split_path[0], "PATH=");
	free(split_path[0]);
	split_path[0] = ft_strdup(first_path);
	free(first_path);
	return (split_path);
}

int	find_path(char **env)
{
	int		i;
	int		y;
	char	*path;

	path = ft_strdup("PATH");
	i = 0;
	y = 0;
	while (env[i])
	{
		while (env[i][y] == path[y])
			y++;
		if (path[y] == '\0')
		{
			free(path);
			return (i);
		}
		else
			y = 0;
		i++;
	}
	free(path);
	return (-1);
}