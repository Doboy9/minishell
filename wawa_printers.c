/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wawa_printers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:53:18 by wneel             #+#    #+#             */
/*   Updated: 2024/03/13 14:55:20 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wawa.h"

void	ft_print_text_read(t_text_read **text_read)
{
	int	i;

	i = 0;
	while (text_read[i])
	{
		printf("\n{\n	text : %s;\n	mchar: %d;\n	attr : %d;\n}\n",
			text_read[i]->raw_text, text_read[i]->is_metachar,
			text_read[i]->is_attribution);
		i++;
	}
}

void	ft_print_split(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
	{
		printf("_%s_\n", splitted[i]);
		i++;
	}
}
