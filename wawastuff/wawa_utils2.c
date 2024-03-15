/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wawa_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:53:51 by wneel             #+#    #+#             */
/*   Updated: 2024/03/15 15:54:17 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wawa.h"

int	char_tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	reverse_bool(int bool)
{
	if (bool == 0)
		return (1);
	return (0);
}

char	**make_chartab(int n, ...)
{
	int		i;
	char	*arg;
	char	**output;
	va_list	params;

	i = 0;
	output = ft_calloc(n + 1, sizeof(char *));
	va_start(params, n);
	while (i < n)
	{
		arg = va_arg(params, char *);
		output[i] = ft_calloc(ft_strlen(arg) + 1, sizeof(char));
		ft_memcpy(output[i], arg, ft_strlen(arg));
		i++;
	}
	va_end(params);
	return (output);
}
