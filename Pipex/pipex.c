/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:28:02 by dboire            #+#    #+#             */
/*   Updated: 2024/03/24 17:05:46 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../doboy.h"
#include "../wawa.h"

void	ft_pipex(int ac, t_command **command_tab, t_envexp *envexp)
{
	(void)ac;

	ft_is_here_doc(command_tab);
	// ft_access(command_tab, envexp);
	ft_pipe(command_tab, envexp);
}
//ft_pipe

int	ft_pipe(t_command **command_tab, t_envexp *envexp)
{
	int		pipex_fds[2];
	int		exit_code;
	int		i;
	int		y;
	int save_stdin;
	int save_stdout;
	(void)envexp;

	i = 0;
	y = 0;
	save_stdin = dup(1);
	save_stdout = dup(0);
	exit_code = 0;
	ft_set_infile_fds(pipex_fds, command_tab);
	// if (pipex_fds[0] != -1)
	// 	dup2(pipex_fds[0], 0);
	while (command_tab[i])
		i++;
	if (i > 0)
		ft_pipe_loop(command_tab, envexp);
	exit_code = ft_handle_outfile(save_stdout, command_tab[i - 1], envexp);
	return (exit_code);
}
int	ft_handle_outfile(int outfile_fd, t_command *command_tab, t_envexp *envexp)
{
	int		exit_code;
	pid_t	process;
	int		status;

	status = 0;
	exit_code = 0;
	process = fork();
	if (process == 0)
	{
		if (outfile_fd == -1)
			exit (1);
		if (outfile_fd == 0)
			dup2(outfile_fd, STDIN_FILENO);
		dup2(outfile_fd, STDOUT_FILENO);
		exit_code = ft_exec_cmd(command_tab, envexp);
		exit(exit_code);
	}
	waitpid(process, &status, 0);
	if (status != -1 && WIFEXITED(status))
		exit_code = WEXITSTATUS(status);
	return (exit_code);
}

void	ft_pipe_loop(t_command **command_tab, t_envexp *envexp)
{
	int	i;

	i = 0;
	while (command_tab[i])
	{
		ft_pipe_it(command_tab[i], envexp);
		i++;
	}
}

void	ft_pipe_it(t_command *command_tab, t_envexp *envexp)
{
	int		pipe_fds[2];
	pid_t	process;
	int		exit_code;

	exit_code = 0;
	pipe(pipe_fds);
	process = fork();
	if (process == -1)
		exit(1);
	if (process == 0)
	{
		dup2(pipe_fds[1], STDOUT_FILENO);
		exit_code = ft_exec_cmd(command_tab, envexp);
		exit(exit_code);
	}
	else
	{
		close(pipe_fds[1]);
		dup2(pipe_fds[0], STDIN_FILENO);
	}
}

int	ft_exec_cmd(t_command *command_tab, t_envexp *envexp)
{
	int		execve_status;
	char	*cmd_path;

	cmd_path = NULL;
	cmd_path = ft_get_cmd_path(command_tab->argv[0], envexp);
	if (!cmd_path)
	{
		ft_send_error("command not found: ", command_tab->argv[0]);
		free(cmd_path);
		return (127);
	}
	// ft_putstr_fd(command_tab->argv[0], 0);
	execve_status = execve(cmd_path, command_tab->argv, envexp->envcopy);
	free(cmd_path);
	if (execve_status == -1)
		return (1);
	return (0);
}

char	*ft_get_cmd_path(char *cmd, t_envexp *envexp)
{
	char	*test_pathname;
	char	**path;
	int		i;

	i = 0;
	if (!cmd)
		return (0);
	if (access(cmd, X_OK) == 0)
		return (cmd);
	path = NULL;
	path = ft_get_paths(envexp->envcopy);
	if (!path)
		return (0);
	test_pathname = NULL;
	while (path[i])
	{
		test_pathname = ft_parse_pathname(path[i++], cmd);
		if (access(test_pathname, X_OK) == 0)
			free_tab(path);
		if (access(test_pathname, X_OK) == 0)
			return (test_pathname);
		free(test_pathname);
	}
	free_tab(path);
	return (0);
}
char	**ft_get_paths(char *ev[])
{
	char	*paths;
	char	**path;

	paths = NULL;
	path = NULL;
	while (*ev)
	{
		if (ft_strnstr(*ev, "PATH=", 5))
		{
			paths = ft_substr(*ev, 5, ft_strlen(*ev));
			break ;
		}
		ev++;
	}
	path = ft_split(paths, ':');
	free(paths);
	return (path);
}
char	*ft_parse_pathname(char *path, char *cmd)
{
	char	*pathname_slash;
	char	*test_pathname;

	test_pathname = NULL;
	pathname_slash = NULL;
	pathname_slash = ft_strjoin(path, "/");
	test_pathname = ft_strjoin(pathname_slash, cmd);
	free(pathname_slash);
	return (test_pathname);
}

void	ft_set_infile_fds(int fds[2], t_command **command_tab)
{
	if (!command_tab[0]->inputs[0])
		return ;
	else if (command_tab[0]->inputs[0]->input_type == 1)
		fds[0] = ft_open(command_tab[0]->inputs[0]->file_path, O_RDONLY, 0, 0);
	// Va etre a gerer avec la struct de here_doc
	// else if (command_tab[0]->inputs[0]->input_type == 3)
	// 	ft_handle_here_doc(command_tab[0]->inputs[0]->file_path);
}

// void	ft_handle_here_doc(char *limiter)
// {
// 	int		doc_fd[2];
// 	pid_t	process;
// 	char	*doc_line;

// 	pipe(doc_fd);
// 	process = fork();
// 	if (process == -1)
// 		exit(1);
// 	if (process == 0)
// 	{
// 		doc_line = NULL;
// 		doc_line = get_next_line(0);
// 		while (doc_line)
// 		{
// 			if (ft_strncmp(doc_line, limiter, ft_strlen(limiter)) == 0)
// 				break ;
// 			ft_putstr_fd(doc_line, doc_fd[1]);
// 			free(doc_line);
// 			doc_line = get_next_line(0);
// 		}
// 		free(doc_line);
// 		exit(0);
// 	}
// 	close(doc_fd[1]);
// 	dup2(doc_fd[0], 0);
// }

int	ft_open(char *file_name, int flags, mode_t mode, int silent)
{
	int		fd;

	if (mode)
		fd = open(file_name, flags, mode);
	else
		fd = open(file_name, flags, 0);
	if (fd == -1 && !silent)
		ft_send_error("no such file or directory: ", file_name);
	return (fd);
}

void	ft_send_error(char *message_part1, char *message_part2)
{
	ft_putstr_fd("\e[1;31mpipex: \e[0m", 2);
	if (message_part2)
	{
		ft_putstr_fd(message_part1, 2);
		ft_putendl_fd(message_part2, 2);
	}
	else
		ft_putendl_fd(message_part1, 2);
}




// ft _here_doc a suprimer
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
