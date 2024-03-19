/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:40:30 by dboire            #+#    #+#             */
/*   Updated: 2023/11/17 14:46:47 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

int	ft_puthexa_nbr_lower(unsigned int nb, int len)
{
	unsigned int	cp;

	cp = nb;
	if (cp < 16)
		len = ft_putchar_base_lower(cp, len);
	else
	{
		len = ft_puthexa_nbr_lower(cp / 16, len);
		len = ft_putchar_base_lower(cp % 16, len);
	}
	return (len);
}

int	ft_puthexa_nbr_upper(unsigned int nb, int len)
{
	unsigned int	cp;

	cp = nb;
	if (cp < 16)
		len = ft_putchar_base_upper(cp, len);
	else
	{
		len = ft_puthexa_nbr_upper(cp / 16, len);
		len = ft_putchar_base_upper(cp % 16, len);
	}
	return (len);
}

int	ft_puthexa_pointer(unsigned long long int nb, int len)
{
	unsigned long long int	cp;

	cp = nb;
	if (cp < 16)
		len = ft_putchar_base_lower(cp, len);
	else
	{
		len = ft_puthexa_pointer(cp / 16, len);
		len = ft_putchar_base_lower(cp % 16, len);
	}
	return (len);
}

int	ft_pointer(unsigned long long int nb, int len)
{
	if (nb == 0)
		len = ft_putstr("(nil)", len);
	else if (nb != 0)
	{
		len = ft_putstr("0x", len);
		len = ft_puthexa_pointer(nb, len);
	}
	return (len);
}
