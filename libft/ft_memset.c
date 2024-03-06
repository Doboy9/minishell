/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:33:27 by wneel             #+#    #+#             */
/*   Updated: 2023/10/30 19:24:15 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		t;
	unsigned char		*us;

	i = 0;
	t = c;
	us = s;
	while (i < n)
	{
		us[i] = t;
		i++;
	}
	return (s);
}
