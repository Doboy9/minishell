/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_access_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:01:47 by dboire            #+#    #+#             */
/*   Updated: 2024/03/19 15:52:38 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_access(t_pipex *pipex, char **env)
{
	int		y;
	char	**split_path;

	split_path = ft_split_path(env);
	y = 0;
	while (pipex->arg_final[y])
	{
		ft_check_access(split_path, pipex, y);
		if ((!pipex->real_path[y]) && (!pipex->arg_final[y][0]))
			ft_printf(": command not found\n");
		if ((!pipex->real_path[y]) && (pipex->arg_final[y][0]))
			ft_printf("%s: command not found\n", pipex->arg_final[y][0]);
		y++;
	}
	ft_free_2char(split_path);
	return ;
}

char	**ft_split_path(char **env)
{
	char	**split_path;
	char	*real_path;
	char	*first_path;
	int		i;

	i = find_path(env);
	split_path = ft_split(env[i], ':');
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

void	ft_check_access(char **split_path, t_pipex *pipex, int y)
{
	int	i;

	i = 0;
	while (split_path[i] != NULL)
	{
		if (!pipex->arg_final[y][0])
			return ;
		pipex->real_path[y] = ft_strjoin(split_path[i], pipex->arg_final[y][0]);
		if (access(pipex->real_path[y], R_OK) == -1)
		{
			free(pipex->real_path[y]);
			pipex->real_path[y] = NULL;
		}
		else
			return ;
		i++;
	}
}
