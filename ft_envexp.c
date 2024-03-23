/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envexp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:44:46 by dboire            #+#    #+#             */
/*   Updated: 2024/03/21 18:37:05 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doboy.h"
#include "wawa.h"

t_envexp *ft_envexp(char *ev[], t_envexp *envexp)
{
	int	i;

	i = 0;
	while(ev[i])
		i++;
	envexp->env_total = i;
	envexp->envcopy = ft_calloc(envexp->env_total, sizeof(char **));
	i = 0;
	while(ev[i])
	{
		envexp->envcopy[i] = ft_strdup(ev[i]);
		i++;
	}
	ft_expcopy(envexp);
	return (envexp);
}

void	ft_expcopy(t_envexp *envexp)
{
	int		i;
	int		y;
	int		ascii;
	char	*tmp;
	
	i = 0;
	y = 0;
	ascii = 0;
	envexp->expcopy = ft_calloc(envexp->env_total, sizeof(char **));
	while (i < envexp->env_total)
	{
		ft_sort_double_tab(envexp, ascii, i);
		i++;
	}
	i = 0;
	while (i < envexp->env_total)
	{
		tmp = ft_strdup(envexp->expcopy[i]);
		free(envexp->expcopy[i]);
		envexp->expcopy[i] = ft_strjoin("declare -x ", tmp);
		free(tmp);
		// printf("%s\n", envexp->expcopy[i]);
		i++;
	}
}

void	ft_sort_double_tab(t_envexp *envexp, int ascii, int tab)
{
	int i;

	i = 0;
	while (ascii != 127)
	{
		while(envexp->envcopy[i])
		{
			if(envexp->envcopy[i][0] == ascii)
			{
				if (ft_check_if_already_there(envexp, i) == 0)
				{
					envexp->expcopy[tab] = ft_strdup(envexp->envcopy[i]);
					return ;
				}
				else
					i++;
			}
			else
				i++;
		}
		ascii++;
		i = 0;
	}
	return ;
}

int	ft_check_if_already_there(t_envexp *envexp, int i)
{
	int	y;
	int	z;

	y = 0;
	z = 0;
	while (envexp->expcopy[z])
	{
		while ((envexp->expcopy[z][y] == envexp->envcopy[i][y]) && envexp->envcopy[i][y] != '\0')
			y++;
		if (envexp->expcopy[z][y] == '\0' && envexp->envcopy[i][y] == '\0')
			return (1);
		else
		{
			y = 0;
			z++;
		}
	}
	return (0);
}