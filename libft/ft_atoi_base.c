/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:20:33 by wneel             #+#    #+#             */
/*   Updated: 2023/11/28 14:07:55 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_base_valid(char *base)
{
	unsigned int		i;
	unsigned int		j;
	unsigned int		counter;

	i = 0;
	j = 0;
	counter = 0;
	while (i < ft_strlen(base))
	{
		while (j < ft_strlen(base))
		{
			if (base[i] == base[j])
				counter++;
			if ((base[i] > 7 && base[i] < 14) || (base[i] == 32))
				return (1);
			if ((base[i] == 43) || (base[i] == 45))
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	if (counter != ft_strlen(base) || ft_strlen(base) <= 1)
		return (1);
	return (0);
}

static int	ft_read_base_c(char c, char *base)
{
	unsigned int		i;

	i = 0;
	while (i < ft_strlen(base))
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int		sign;
	int		number;
	int		i;

	i = 0;
	number = 0;
	sign = 1;
	if (ft_is_base_valid(base) != 0)
		return (0);
	while (str[i] != '\0')
	{
		while ((str[i] > 7 && str[i] < 14) || (str[i] == 32))
			i++;
		while ((str[i] == 43) || (str[i] == 45))
		{
			if (str[i] == 45)
				sign *= -1;
			i++;
		}
		while (ft_read_base_c(str[i], base) != -1)
			number = number * ft_strlen(base) + ft_read_base_c(str[i++], base);
		return (number * sign);
	}
	return (0);
}
