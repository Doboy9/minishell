/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_switch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:54:35 by dboire            #+#    #+#             */
/*   Updated: 2023/11/17 16:15:42 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_switch(const char *s, size_t i, va_list args, int len)
{
	if (s[i + 1] == 'c')
		len = ft_putchar(va_arg(args, int), len);
	else if (s[i + 1] == 's')
		len = ft_putstr(va_arg(args, const char *), len);
	else if (s[i + 1] == 'p')
		len = ft_pointer(va_arg(args, unsigned long long int), len);
	else if (s[i + 1] == 'd' || s[i + 1] == 'i')
		len = ft_putnbr(va_arg(args, int), len);
	else if (s[i + 1] == 'u')
		len = ft_put_unsigned_nbr(va_arg(args, unsigned int), len);
	else if (s[i + 1] == 'x')
		len = ft_puthexa_nbr_lower(va_arg(args, unsigned int), len);
	else if (s[i + 1] == 'X')
		len = ft_puthexa_nbr_upper(va_arg(args, unsigned int), len);
	else if (s[i + 1] == '%')
		len = ft_putchar('%', len);
	else
	{
		len = ft_putchar(s[i], len);
		len = ft_putchar(s[i + 1], len);
	}
	i = i + 2;
	return (len);
}
