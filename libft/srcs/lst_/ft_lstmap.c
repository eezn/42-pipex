/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42Seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 23:12:41 by jin-lee           #+#    #+#             */
/*   Updated: 2021/07/05 11:49:37 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*head_node;
	t_list		*curr_node;
	t_list		*new_node;

	if (!lst || !f)
		return (NULL);
	head_node = ft_lstnew(f(lst->content));
	if (!head_node)
		return (NULL);
	curr_node = head_node;
	lst = lst->next;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&head_node, del);
			return (NULL);
		}
		curr_node->next = new_node;
		curr_node = new_node;
		lst = lst->next;
	}
	return (head_node);
}
