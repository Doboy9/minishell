/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wawa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:50:27 by wneel             #+#    #+#             */
/*   Updated: 2024/03/05 15:53:41 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wawa.h"
#include <stdio.h>

int	reverse_bool(int bool)
{
	if (bool == 0)
		return (1);
	return (0);
}

void	update_quote_status(char c, t_quote_status *quote_status)
{
	if (c == '\'' && !quote_status->in_dquotes)
		quote_status->in_squotes = reverse_bool(quote_status->in_squotes);
	if (c == '"' && !quote_status->in_squotes)
		quote_status->in_dquotes = reverse_bool(quote_status->in_dquotes);
}

void ft_init_quote_status(t_quote_status	*quote_status)
{
	quote_status->in_dquotes = 0;
	quote_status->in_squotes = 0;
}
	return (0);
}
