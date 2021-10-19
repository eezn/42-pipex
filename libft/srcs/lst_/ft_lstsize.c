/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42Seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 21:25:34 by jin-lee           #+#    #+#             */
/*   Updated: 2021/07/05 11:48:29 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int			lstlen;
	t_list		*next_node;

	lstlen = 0;
	next_node = lst;
	while (next_node != NULL)
	{
		next_node = next_node->next;
		lstlen += 1;
	}
	return (lstlen);
}
