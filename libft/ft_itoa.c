/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:57:43 by wneel             #+#    #+#             */
/*   Updated: 2023/11/09 16:11:51 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_static_count_decimals(int i)
{
	unsigned int	decimals;

	decimals = 0;
	if (i < 0)
	{
		i *= -1;
		decimals++;
	}
	while (i / 10 != 0)
	{
		i /= 10;
		decimals++;
	}
	return (decimals);
}

static char	*ft_static_rev_str(char *tab, unsigned int size)
{
	unsigned int	i;
	unsigned int	temp;

	i = 0;
	while (i < size / 2)
	{
		temp = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i -1] = temp;
		i++;
	}
	return (tab);
}

char	*ft_itoa(int n)
{
	unsigned int	n_len;
	unsigned int	i;
	char			*text;
	long int		number;

	number = (long int) n;
	n_len = ft_static_count_decimals(n) + 1;
	text = malloc(sizeof(char) * (n_len + 1));
	if (!text)
		return (0);
	i = 0;
	if (n < 0)
		number *= -1;
	while (number / 10 != 0)
	{
		text[i++] = ((number % 10) + '0');
		number /= 10;
	}
	text[i++] = ((number % 10) + '0');
	if (n < 0)
		text[i++] = '-';
	text[i] = '\0';
	text = ft_static_rev_str(text, (n_len));
	return (text);
}
