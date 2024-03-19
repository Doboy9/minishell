/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:14:17 by dboire            #+#    #+#             */
/*   Updated: 2024/03/19 15:52:31 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_pipex_arg(t_pipex *pipex)
{
	int	j;
	int	i;

	j = 0;
	if (pipex->arg_final)
	{
		if (pipex->arg_final[j])
		{
			while (pipex->arg_final[j])
			{
				i = 0;
				if (pipex->arg_final[j][i])
				{
					while (pipex->arg_final[j][i])
					{
						free(pipex->arg_final[j][i]);
						i++;
					}
				}
				free(pipex->arg_final[j]);
				j++;
			}
			free (pipex->arg_final);
		}
	}
}

void	ft_free_pipex(t_pipex *pipex)
{
	ft_free_pipex_arg(pipex);
	ft_free_other_pipex(pipex);
	free(pipex);
	exit(0);
}

void	ft_free_other_pipex(t_pipex *pipex)
{
	int	i;

	i = 0;
	if (pipex->real_path)
	{
		while (i != pipex->command)
		{
			if (pipex->real_path[i])
				free(pipex->real_path[i]);
			i++;
		}
		free(pipex->real_path);
	}
}

void	ft_free_2char(char **str)
{
	int	i;

	i = 0;
	if (str[i])
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
}
