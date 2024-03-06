/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:10:13 by wneel             #+#    #+#             */
/*   Updated: 2023/11/07 15:02:21 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list			*new_list;
	t_list			*next;

	if (!lst || !f || !del)
		return (0);
	new_list = NULL;
	while (lst != NULL)
	{
		next = ft_lstnew(f(lst->content));
		if (!next)
		{
			ft_lstclear(&new_list, del);
			return (0);
		}
		ft_lstadd_back(&new_list, next);
		lst = lst->next;
	}
	return (new_list);
}
