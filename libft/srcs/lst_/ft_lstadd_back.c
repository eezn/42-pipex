/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42Seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 21:37:28 by jin-lee           #+#    #+#             */
/*   Updated: 2021/07/05 11:47:58 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list		*curr_node;
	t_list		*next_node;

	if (!(*lst))
		*lst = new;
	else
	{
		next_node = *lst;
		curr_node = next_node;
		while (next_node != NULL)
		{
			curr_node = next_node;
			next_node = next_node->next;
		}
		curr_node->next = new;
	}
}
