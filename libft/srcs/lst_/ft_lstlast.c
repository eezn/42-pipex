/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42Seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 21:30:15 by jin-lee           #+#    #+#             */
/*   Updated: 2021/07/05 11:48:20 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list		*curr_node;
	t_list		*next_node;

	next_node = lst;
	curr_node = lst;
	while (next_node != NULL)
	{
		curr_node = next_node;
		next_node = next_node->next;
	}
	return (curr_node);
}
