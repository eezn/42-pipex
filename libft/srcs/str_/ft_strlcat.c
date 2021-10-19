/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42Seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 00:39:48 by jin-lee           #+#    #+#             */
/*   Updated: 2021/07/05 21:12:42 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		dstlen;
	size_t		srclen;
	size_t		idx;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	idx = 0;
	if (dstlen > dstsize || dstsize == 0)
		return (dstsize + srclen);
	while (src[idx] && dstlen + idx < dstsize - 1)
	{
		dst[dstlen + idx] = src[idx];
		idx++;
	}
	dst[dstlen + idx] = 0;
	return (dstlen + srclen);
}
