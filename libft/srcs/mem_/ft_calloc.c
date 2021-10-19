/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42Seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 19:33:04 by jin-lee           #+#    #+#             */
/*   Updated: 2021/01/15 23:34:02 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	size_t		size;
	void		*ret;

	size = nelem * elsize;
	ret = malloc(size);
	if (!ret)
		return (NULL);
	ft_memset(ret, 0, size);
	return (ret);
}
