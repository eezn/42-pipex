/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42Seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 01:04:36 by jin-lee           #+#    #+#             */
/*   Updated: 2021/07/05 17:48:40 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char		*check_point;
	char		*s1;
	char		*s2;
	size_t		count;
	size_t		little_len;

	little_len = ft_strlen(little);
	if (!little_len)
		return ((char *)big);
	count = 0;
	check_point = (char *)big;
	while (*check_point && (count++ + little_len - 1 < len))
	{
		s1 = check_point;
		s2 = (char *)little;
		while (*s1 && *s2 && (*s1 == *s2))
		{
			s1++;
			s2++;
		}
		if (!(*s2))
			return (check_point);
		check_point++;
	}
	return (NULL);
}
