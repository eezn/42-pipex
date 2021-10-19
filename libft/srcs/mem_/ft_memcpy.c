/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42Seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 21:08:34 by jin-lee           #+#    #+#             */
/*   Updated: 2021/07/05 11:50:42 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char	*udst;
	unsigned char	*usrc;

	if (!dst && !src)
		return (NULL);
	udst = (unsigned char *)dst;
	usrc = (unsigned char *)src;
	while (len--)
	{
		*udst = *usrc;
		udst++;
		usrc++;
	}
	return (dst);
}
