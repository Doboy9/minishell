/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:22:09 by dboire            #+#    #+#             */
/*   Updated: 2023/11/17 16:22:13 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr(int nb, int len)
{
	long int	cp;

	cp = nb;
	if (cp < 0)
	{
		len = ft_putchar('-', len);
		cp = (-1) * cp;
	}
	if (cp <= 9)
	{
		len = ft_putchar(cp + '0', len);
	}
	else
	{
		len = ft_putnbr(cp / 10, len);
		len = ft_putchar(cp % 10 + '0', len);
	}
	return (len);
}

int	ft_put_unsigned_nbr(unsigned int nb, int len)
{
	long int	cp;

	cp = nb;
	if (cp <= 9)
	{
		len = ft_putchar(cp + '0', len);
	}
	else
	{
		len = ft_putnbr(cp / 10, len);
		len = ft_putchar(cp % 10 + '0', len);
	}
	return (len);
}

int	ft_putchar_base_lower(int c, size_t len)
{
	char	*s;

	s = "0123456789abcdef";
	write (1, &s[c], 1);
	len++;
	return (len);
}

int	ft_putchar_base_upper(int c, size_t len)
{
	char	*s;

	s = "0123456789ABCDEF";
	write (1, &s[c], 1);
	len++;
	return (len);
}
