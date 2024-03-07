/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:39:23 by wneel             #+#    #+#             */
/*   Updated: 2023/10/30 16:48:17 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (c > 122)
		return (0);
	if (c < 97 && c > 90)
		return (0);
	if (c < 65)
		return (c >= 48 && c <= 57);
	return (1);
}