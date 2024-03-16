/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doboy_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:12:08 by dboire            #+#    #+#             */
/*   Updated: 2024/03/16 16:14:58 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doboy.h"

void	ft_copyenv(char *ev[], t_envexp *envexp)
{
	int	i;
	
	i = 0;
	while (ev[i])
		i++;
	envexp->envcopy = ft_calloc(sizeof(char *), i + 1);
	i = 0;
	while(ev[i])
	{
		envexp->envcopy[i] = ft_strdup(ev[i]);
		i++;
	}
	i = 0;
	while (envexp->envcopy[i])
	{
		printf("%s\n", envexp->envcopy[i]);
		i++;
	}
}

void	ft_copyexp(char *ev[], t_envexp *envexp) //Reste a trier par ascii
{
	int	i;
	
	i = 0;
	while (ev[i])
		i++;
	envexp->expcopy = ft_calloc(sizeof(char *), i + 1);
	i = 0;
	while(ev[i])
	{
		envexp->expcopy[i] = ft_strdup2(ev[i]);
		i++;
	}
	i = 0;
	while (envexp->expcopy[i])
	{
		printf("%s", "declare -x ");
		printf("%s\n", envexp->expcopy[i]);
		i++;
	}
}

char	*ft_strdup2(const char *s)
{
	int		src_len;
	char	*new_src;
	int		i;
	int		y;

	y = 0;
	src_len = ft_strlen(s);
	new_src = calloc((src_len + 3), sizeof(char));
	if (!new_src)
		return (0);
	i = 0;
	while (i < src_len)
	{
		if (s[i] == '=' && y == 0)
		{
			new_src[i] = s[i];
			i++;
			new_src[i] = '"';
			i++;
			y++;
		}
		new_src[i] = s[i-y];
		i++;
	}
	if(y == 1)
	{
		new_src[i] = '"';
		i++;
	}
	new_src[i] = '\0';
	return (new_src);
}
