/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42Seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 02:00:53 by jin-lee           #+#    #+#             */
/*   Updated: 2021/07/05 21:14:12 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*ret;
	size_t		idx;
	size_t		s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len - start < len)
		ret = (char *)malloc(sizeof(char) * (s_len - start + 1));
	else if (start > s_len - 1)
		ret = (char *)malloc(sizeof(char) * 1);
	else
		ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	idx = -1;
	if (start < s_len)
		while (++idx < len && idx < s_len)
			ret[idx] = s[start + idx];
	ret[idx] = 0;
	return (ret);
}
