/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 09:25:52 by wneel             #+#    #+#             */
/*   Updated: 2024/03/21 15:29:26 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	update_quote_status(char c, t_quote_status *quote_status)
{
	if (c == '\'' && !quote_status->in_dquotes)
		quote_status->in_squotes = reverse_bool(quote_status->in_squotes);
	if (c == '"' && !quote_status->in_squotes)
		quote_status->in_dquotes = reverse_bool(quote_status->in_dquotes);
}

void	ft_init_quote_status(t_quote_status	*quote_status)
{
	quote_status->in_dquotes = 0;
	quote_status->in_squotes = 0;
}

int	is_well_quoted(char *str)
{
	int				i;
	t_quote_status	quote_status;

	ft_init_quote_status(&quote_status);
	i = 0;
	while (str[i] != '\0')
	{
		update_quote_status(str[i], &quote_status);
		i++;
	}
	if (quote_status.in_dquotes)
		printf("dquote issue here => %s", str);
	if (quote_status.in_squotes)
		printf("squote issue here =>  %s", str);
	if (quote_status.in_dquotes || quote_status.in_squotes)
		return (0);
	return (1);
}

int	len_without_extra_quotes(char *str)
{
	t_quote_status	qstatus;
	int				last_qstatus;
	int				i;
	int				j;

	i = 0;
	j = 0;
	last_qstatus = 0;
	ft_init_quote_status(&qstatus);
	while (str[i] != '\0')
	{
		update_quote_status(str[i], &qstatus);
		if ((qstatus.in_dquotes || qstatus.in_squotes) == last_qstatus)
			j++;
		i++;
		last_qstatus = (qstatus.in_dquotes || qstatus.in_squotes);
	}
	return (j);
}

char	*remove_extra_quotes(char *str)
{
	t_quote_status	qstatus;
	char			*without_quotes;
	int				last_qstatus;
	int				i;
	int				j;

	i = 0;
	j = 0;
	last_qstatus = 0;
	without_quotes = ft_calloc(len_without_extra_quotes(str) \
		+ 1, sizeof(char));
	ft_init_quote_status(&qstatus);
	while (str[i] != '\0')
	{
		update_quote_status(str[i], &qstatus);
		if ((qstatus.in_dquotes || qstatus.in_squotes) == last_qstatus)
		{
			without_quotes[j] = str[i];
			j++;
		}
		i++;
		last_qstatus = (qstatus.in_dquotes || qstatus.in_squotes);
	}
	free(str);
	return (without_quotes);
}
