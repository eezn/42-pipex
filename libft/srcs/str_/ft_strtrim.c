/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42Seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 14:46:43 by jin-lee           #+#    #+#             */
/*   Updated: 2021/07/05 21:13:50 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checkset(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*ret;
	size_t		idx;
	size_t		head;
	size_t		tail;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	head = 0;
	tail = ft_strlen(s1);
	while (s1[head] && ft_checkset(s1[head], set))
		head++;
	while ((head < tail) && ft_checkset(s1[tail - 1], set))
		tail--;
	ret = (char *)malloc(sizeof(char) * (tail - head + 1));
	if (!ret)
		return (NULL);
	idx = 0;
	while (head < tail)
		ret[idx++] = s1[head++];
	ret[idx] = 0;
	return (ret);
}
