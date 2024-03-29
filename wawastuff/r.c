/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wawa_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:53:51 by wneel             #+#    #+#             */
/*   Updated: 2024/03/20 09:33:07 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wawa.h"

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

int	parse_word(char *bash_word)
{
	int	word_len;

	word_len = ft_strlen(bash_word);
	if (word_len == 1)
	{
		if (bash_word[0] == '|')
			return (PIPE);
		if (bash_word[0] == '<')
			return (ANGLE_BRACE_LEFT);
		if (bash_word[0] == '>')
			return (ANGLE_BRACE_RIGHT);
	}
	if (word_len == 2)
	{
		if (bash_word[0] == '<' && bash_word[1] == '<')
			return (DOUBLE_ANGLE_BRACE_LEFT);
		if (bash_word[0] == '>' && bash_word[1] == '>')
			return (DOUBLE_ANGLE_BRACE_RIGHT);
	}
	return (TEXT);
}
