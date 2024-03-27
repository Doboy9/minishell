/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doboy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:12:03 by dboire            #+#    #+#             */
/*   Updated: 2024/03/27 15:07:58 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOBOY_H
# define DOBOY_H
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "sys/types.h"
# include <fcntl.h>
# include "wawa.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct s_commandecho
{
	// int		command_argc; 
	char	**command_argv; // the text that will be echoed (w/o echo)
	char	*command;	//the echo char*
	int		flag_n;
}			t_commandecho;

typedef struct s_commandcd
{
	// int		command_argc;
	char	**command_argv; // The path cd needs to go to
	char	*command; // The cd char*
	int		abs_or_rel; // 0 or 1 to see if the path is absolute or relative. If absolute, **command_argv take the string, if not, take the pwd in env ?
}			t_commandcd;

typedef struct s_commandpwd // GET CWD
{
	// int		command_argc;
	char	*command; // The pwd char*
	int		find_pwd; // int to see were is PWD in the env (env[i])
}			t_commandpwd;

typedef struct s_commandexport
{
	char	***export; //Keeping all the variables with have done with the export until now
	int		export_count; // Knowing how many variables we have in export
}	t_commandexport;

// typedef struct s_pipex
// {
// 	char	***arg_final; // If ls -l | grep m | cat Makefile -> arg_final[0][0] = ls [0][1] = -l [1][0]= grep [1][1] = m etc...
// 	char	**real_path; //Will access in all the paths available in $PATH to know if a path is correct, and keep it here for executing
// 	int		command; // How many commands do we have to process / execute
// }	t_pipex;

typedef struct s_envexp
{
	char	**envcopy; // Copy the env of the pc
	int		env_total;
	char	**expcopy; // Copy the export of the pc
}	t_envexp;

int		ft_doboy(int ac, char *av[], char *ev[]);
void	ft_builtins(int ac, char *av[], char *ev[]);
void	ft_changedir(int ac, char *av[]);
int		find_pwd(char **env);
void	ft_copyenv(char *ev[], t_envexp *envexp);
void	ft_write_exp(t_envexp *envexp);
void	ft_copyexp(char *ev[], t_envexp *envexp);
char	*ft_strdup2(const char *s);


//envexp
t_envexp	*ft_envexp(char *ev[], t_envexp *envexp);
void	ft_expcopy(t_envexp *envexp);
void	ft_sort_double_tab(t_envexp *envexp, int ascii, int tab);
int		ft_check_if_already_there(t_envexp *envexp, int i);

//main prompt
void	free_command_tab(t_command	**command_tab);
void	free_cmd_el(t_command	*command);
void	free_input_tab(t_input **input);
void	free_output_tab(t_output **output);

// pipex
void	ft_pipex(int ac, t_command **command_tab, t_envexp *envexp);
void	ft_is_here_doc(t_command **command_tab);
void	ft_access(t_command **command_tab, t_envexp *envexp);
char	**ft_split_path(t_envexp *envexp);
int	find_path(char **env);
void	ft_check_access(char **split_path, t_command **command_tab, int y);

int		ft_pipe(t_command **command_tab, t_envexp *envexp);
int	ft_set_infile_fds(int fds[2], t_command **command_tab);
void	ft_handle_here_doc(char *limiter);
int		ft_open(char *file_name, int flags, mode_t mode, int silent);
void	ft_send_error(char *message_part1, char *message_part2);
void	ft_pipe_loop(t_command **command_tab, t_envexp *envexp);
void		ft_pipe_it(t_command *command_tab, t_envexp *envexp);
int		ft_exec_cmd(t_command *command_tab, t_envexp *envexp);
char	*ft_get_cmd_path(char *cmd, t_envexp *envexp);
char	**ft_get_paths(char *ev[]);
char	*ft_parse_pathname(char *path, char *cmd);
int		ft_handle_outfile(int outfile_fd, t_command *command_tab, t_envexp *envexp);

#endif
