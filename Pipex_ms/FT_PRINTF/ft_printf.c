/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:25:35 by dboire            #+#    #+#             */
/*   Updated: 2023/11/17 16:15:44 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *s, ...)
{
	size_t	i;
	int		len;
	va_list	args;

	va_start (args, s);
	i = 0;
	len = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			len = ft_switch(s, i, args, len);
			i++;
		}
		else
			len = ft_putchar(s[i], len);
		i++;
	}
	va_end(args);
	return (len);
}
