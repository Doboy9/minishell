/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_text_read.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:12:59 by wneel             #+#    #+#             */
/*   Updated: 2024/03/21 15:29:44 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_text_read	**parse_read_input(char *lineread)
{
	t_quote_status	quote_status;
	t_text_read		**text_read;
	t_text_read		*splitted;
	char			**bash_splitted;
	int				i;

	i = 0;
	text_read = NULL;
	ft_init_quote_status(&quote_status);
	bash_splitted = ft_split_bash_words(lineread);
	text_read = ft_calloc(char_tab_len(bash_splitted) + 1,
			sizeof(t_text_read *));
	while (bash_splitted[i])
	{
		splitted = malloc(sizeof(t_text_read));
		splitted->raw_text = ft_strdup(bash_splitted[i]);
		splitted->exp_text = ft_strdup(bash_splitted[i]);
		splitted->is_metachar = parse_word(bash_splitted[i]);
		splitted->is_attribution = 0x667;
		text_read[i] = splitted;
		i++;
	}
	free_tab(bash_splitted);
	return (text_read);
}

t_text_read	**parse_variables(t_text_read	**text_read, int *error_status)
{
	int	i;

	i = 0;
	while (text_read[i])
	{
		if (!is_well_quoted(text_read[i]->exp_text))
		{
			*error_status = 1;
			return (text_read);
		}
		text_read[i]->exp_text = expand_vars(text_read[i]->exp_text);
		i++;
	}
	return (text_read);
}

t_text_read	**parse_extra_quotes(t_text_read	**text_read)
{
	int		i;

	i = 0;
	while (text_read[i])
	{
		text_read[i]->exp_text = remove_extra_quotes(text_read[i]->exp_text);
		i++;
	}
	return (text_read);
}

void	free_text_read(t_text_read	**text_read)
{
	int	i;

	i = 0;
	while (text_read[i])
	{
		free(text_read[i]->raw_text);
		free(text_read[i]->exp_text);
		free(text_read[i]);
		i++;
	}
	free(text_read);
}
