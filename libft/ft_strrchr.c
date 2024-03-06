/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:45:29 by wneel             #+#    #+#             */
/*   Updated: 2023/11/05 11:21:27 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		c_mod;
	int		last_occur;
	char	*string;

	i = 0;
	c_mod = c % 128;
	last_occur = 0;
	string = (char *) s;
	while (s[i] != '\0')
	{
		if (s[i] == c_mod)
			last_occur = i;
		i++;
	}
	if (s[last_occur] == c_mod)
	{
		string += last_occur;
		return (string);
	}
	if (s[last_occur] != c_mod && c_mod == '\0')
		string += i;
	if (s[last_occur] != c_mod && c_mod == '\0')
		return (string);
	return (0);
}
