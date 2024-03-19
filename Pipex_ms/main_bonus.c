/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:28:07 by dboire            #+#    #+#             */
/*   Updated: 2024/03/19 17:50:00 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_pipex(int ac, char **av, char **env)
{
	t_pipex	*pipex;
	int		i;

	i = 2;
	pipex = ft_calloc(sizeof(t_pipex), 1);
	//if(command->input == 3)
		//pipex = ft_init_pipex_here_doc(pipex, ac, av, env);
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		pipex = ft_init_pipex_here_doc(pipex, ac, av, env);
		i = 3;
	}
	else
		pipex = ft_init_pipex(pipex, ac, av, env);
	loop(pipex, ac, av, i);
	ft_free_pipex(pipex);
	return (0);
}

void	child_process(t_pipex *pipex, int *pipefd, int i, int tmp)
{
	close(pipefd[0]);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
	dup2(tmp, STDIN_FILENO);
	close(tmp);
	if (pipex->real_path[i] != NULL)
		if (execve(pipex->real_path[i], pipex->arg_final[i], NULL) == -1)
			ft_free_pipex(pipex);
}

int	ft_child_loop(t_pipex *pipex, int pipefd[2], int i, int tmp)
{
	int	pid1;

	if (pipe(pipefd) < 0)
		return (0);
	pid1 = fork();
	if (pid1 == 0)
		child_process(pipex, pipefd, i, tmp);
	close(pipefd[1]);
	close(tmp);
	tmp = pipefd[0];
	return (tmp);
}

void	loop(t_pipex *pipex, int ac, char **av, int y)
{
	int	tmp;
	int	i;
	int	fd;
	int	pipefd[2];

	i = 0;
	fd = 0;
	tmp = dup(STDIN_FILENO);
	while (y < ac - 2)
	{
		tmp = ft_child_loop(pipex, pipefd, i, tmp);
		i++;
		y++;
	}
	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
	close(tmp);
	fd = ft_doc(pipex, ac, av, fd);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	waitpid(-1, NULL, 0);
	if (pipex->real_path[i] != NULL)
		execve(pipex->real_path[i], pipex->arg_final[i], NULL);
}

int	ft_doc(t_pipex *pipex, int ac, char **av, int fd)
{
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fd <= 0)
			ft_free_pipex(pipex);
	}
	else
	{
		fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd <= 0)
			ft_free_pipex(pipex);
	}
	return (fd);
}

void	ft_here_doc_loop(char **av, int pipefd[2])
{
	char	*end;
	char	*here_doc;

	here_doc = NULL;
	end = ft_strdup(av[2]);
	//end = ft_strdup(command->output->file_path);
	here_doc = get_next_line(1);
	while (ft_strnstr(here_doc, end, ft_strlen(here_doc)) == 0)
		here_doc = ft_strjoin(here_doc, get_next_line(1));
	ft_putstr_fd(here_doc, pipefd[1]);
	free(here_doc);
}

void	ft_here_doc(char **av)
{
	int	pid1;
	int	pipefd[2];
	int	i;

	i = 0;
	if (pipe(pipefd) < 0)
		return ;
	pid1 = fork();
	if (pid1 == 0)
		ft_here_doc_loop(av, pipefd);
	i++;
	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
	return ;
}
