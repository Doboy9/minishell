/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:42:04 by dboire            #+#    #+#             */
/*   Updated: 2024/03/19 16:18:03 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_parse(int ac, char **av)
{
	char	**dest;

	dest = ft_split(av[ac], ' ');
	return (dest);
}

t_pipex	*ft_init_pipex_here_doc(t_pipex *pipex, int ac, char **av, char **env)
{
	int	i;
	int	end;

	i = 0;
	end = ac - 1;
	pipex->arg_final = ft_calloc(sizeof(char ***), ac);
	pipex->real_path = ft_calloc(sizeof(char **), ac - 2);
	while (av[i + 4])
	{
		pipex->arg_final[i] = ft_split(av[i + 3], ' ');
		i++;
	}
	pipex->command = i;
	ft_access(pipex, env);
	ft_here_doc(av);
	return (pipex);
}

t_pipex	*ft_init_pipex(t_pipex *pipex, int ac, char **av, char **env)
{
	int	i;
	int	fd;

	i = 0;
	pipex->arg_final = ft_calloc(sizeof(char ***), ac);
	pipex->real_path = ft_calloc(sizeof(char **), ac - 2);
	while (av[i + 3])
	{
		pipex->arg_final[i] = ft_split(av[i + 2], ' ');
		i++;
	}
	pipex->command = i;
	ft_access(pipex, env);
	fd = open(av[1], O_RDONLY);
	fd = ft_check_fd(fd, pipex, av, ac);
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (pipex);
}

int	find_path(char **env)
{
	int		i;
	int		y;
	char	*path;

	path = ft_calloc(sizeof(char), 5);
	ft_strlcpy(path, "PATH", 5);
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

int	ft_check_fd(int fd, t_pipex *pipex, char **av, int ac)
{
	(void) pipex;
	if (fd == 0)
	{
		ft_printf("bash: %s: No such file or directory\n", av[1]);
		ft_doc(pipex, ac, av, fd);
		close(fd);
		ft_free_pipex(pipex);
	}
	else if (fd < 0)
	{
		ft_printf("bash: %s: Permission denied\n", av[1]);
		ft_doc(pipex, ac, av, fd);
		close(fd);
		ft_free_pipex(pipex);
	}
	ft_parse(ac, av);
	return (fd);
}
