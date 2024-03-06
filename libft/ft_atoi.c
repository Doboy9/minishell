/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:09:24 by wneel             #+#    #+#             */
/*   Updated: 2023/10/31 16:33:23 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_static_is_char_whitespace(char c)
{
	return ((c > 7 && c < 14) || (c == 32));
}

int	ft_atoi(const char *nptr)
{
	int		sign;
	int		number;
	int		i;

	i = 0;
	number = 0;
	sign = 1;
	while (nptr[i] != '\0')
	{
		while (ft_static_is_char_whitespace(nptr[i]))
			i++;
		if ((nptr[i] == 43) || (nptr[i] == 45))
		{
			if (nptr[i] == 45)
				sign *= -1;
			i++;
		}
		while (nptr[i] > 47 && nptr[i] < 58)
		{
			number = number * 10 + (nptr[i] - '0');
			i++;
		}
		return (number * sign);
	}
	return (0);
}
