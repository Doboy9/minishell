/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:28:40 by wneel             #+#    #+#             */
/*   Updated: 2023/11/05 16:19:54 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		src_len;
	char	*new_src;
	int		i;

	src_len = ft_strlen(s);
	new_src = malloc((src_len + 1) * sizeof(char));
	if (!new_src)
		return (0);
	i = 0;
	while (i < src_len)
	{
		new_src[i] = s[i];
		i++;
	}
	new_src[i] = '\0';
	return (new_src);
}
