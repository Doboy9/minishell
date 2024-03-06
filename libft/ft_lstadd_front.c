/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:08:00 by wneel             #+#    #+#             */
/*   Updated: 2023/11/06 16:41:45 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*current;

	if (!new)
		return ;
	if (!lst || !*lst)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	new->next = current;
	*lst = new;
}
