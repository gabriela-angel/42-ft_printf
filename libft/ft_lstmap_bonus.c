/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:38:46 by gangel-a          #+#    #+#             */
/*   Updated: 2024/10/20 12:57:11 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*lst_iter;
	t_list	*current_node;

	lst_iter = lst;
	if (!lst_iter || !f)
		return (NULL);
	head = NULL;
	while (lst_iter)
	{
		current_node = ft_lstnew(f(lst_iter->content));
		if (!current_node)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, current_node);
		lst_iter = lst_iter->next;
	}
	return (head);
}
