/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:22:09 by wneel             #+#    #+#             */
/*   Updated: 2023/11/05 11:46:26 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*tab;
	long int		allocated_size;

	allocated_size = size * nmemb;
	if (allocated_size < 0 || ((int) size < 0 && (int) nmemb < 0))
		return (0);
	tab = malloc(allocated_size);
	if (!tab)
		return (0);
	ft_bzero(tab, allocated_size);
	return ((void *)tab);
}
