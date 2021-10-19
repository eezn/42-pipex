/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42Seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 22:46:41 by jin-lee           #+#    #+#             */
/*   Updated: 2021/01/15 23:10:58 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*udst;
	unsigned char	*usrc;

	if (!dst && !src)
		return (NULL);
	udst = (unsigned char *)dst;
	usrc = (unsigned char *)src;
	if (udst <= usrc)
		while (n--)
			*udst++ = *usrc++;
	else
	{
		udst += n - 1;
		usrc += n - 1;
		while (n--)
			*udst-- = *usrc--;
	}
	return (dst);
}
