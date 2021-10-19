/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42Seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 21:15:30 by jin-lee           #+#    #+#             */
/*   Updated: 2021/07/05 11:50:29 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*udst;
	unsigned char	*usrc;

	udst = (unsigned char *)dst;
	usrc = (unsigned char *)src;
	while (n--)
	{
		*udst = *usrc;
		if (*usrc == (unsigned char)c)
			return (++udst);
		udst++;
		usrc++;
	}
	return (NULL);
}
