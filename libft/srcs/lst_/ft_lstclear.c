/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42Seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 23:02:46 by jin-lee           #+#    #+#             */
/*   Updated: 2021/01/20 00:18:36 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr_node;

	curr_node = *lst;
	if (*lst)
	{
		while (*lst)
		{
			*lst = curr_node->next;
			ft_lstdelone(curr_node, del);
			curr_node = *lst;
		}
	}
}
