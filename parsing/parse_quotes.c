/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 09:25:52 by wneel             #+#    #+#             */
/*   Updated: 2024/03/20 09:26:24 by wneel            ###   ########.fr       */
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
