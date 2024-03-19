/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:28:17 by dboire            #+#    #+#             */
/*   Updated: 2024/03/19 15:48:39 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H


# include "FT_PRINTF/libftprintf.h"
# include "../libft/libft.h"
# include "GNL/get_next_line.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <errno.h>


typedef struct s_pipex
{
	char	***arg_final;
	char	**real_path;
	int		command;
}	t_pipex;

void	ft_access(t_pipex *pipex, char **env);
char	**ft_parse(int ac, char **av);
void	ft_free_pipex(t_pipex *pipex);
void	ft_free_pipex_arg(t_pipex *pipex);
void	ft_free_other_pipex(t_pipex *pipex);
void	ft_fork(t_pipex *pipex);
void	child_process(t_pipex *pipex, int *pipefd, int i, int tmp);
void	parent_process(t_pipex *pipex, int ac, char **av);
t_pipex	*ft_init_pipex(t_pipex *pipex, int ac, char **av, char **env);
t_pipex	*ft_init_pipex_here_doc(t_pipex *pipex, int ac, char **av, char **env);
int		ft_check_fd(int fd, t_pipex *pipex, char **av, int ac);
int		find_path(char **env);
char 	**ft_split_path(char **env);
void	ft_free_2char(char **str);
void 	ft_check_access(char **split_path, t_pipex *pipex, int y);
void	loop(t_pipex *pipex, int ac, char **av, int y);
void	ft_here_doc_loop(char **av, int pipefd[2]);
void	ft_here_doc(char **av);
int	ft_child_loop(t_pipex *pipex, int pipefd[2], int i, int tmp);
int	ft_doc(t_pipex *pipex, int ac, char **av, int fd);

int	ft_pipex(int ac, char **av, char **env);

#endif