/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:52:47 by wneel             #+#    #+#             */
/*   Updated: 2023/11/05 16:21:48 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_string;
	unsigned int	s_len;
	unsigned int	i;

	if (!s || !f)
		return (0);
	i = 0;
	s_len = ft_strlen(s);
	new_string = malloc(sizeof(char) * (s_len + 1));
	if (!new_string)
		return (0);
	while (i < s_len)
	{
		new_string[i] = f(i, s[i]);
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
