/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:41:40 by wneel             #+#    #+#             */
/*   Updated: 2023/11/03 14:52:47 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		c_mod;
	char	*string;

	i = 0;
	c_mod = c % 128;
	string = (char *) s;
	while (s[i] != '\0' && s[i] != c_mod)
		i++;
	if (s[i] == c_mod)
	{
		string += i;
		return (string);
	}
	return (0);
}
