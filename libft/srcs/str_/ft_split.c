/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42Seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 01:02:56 by jin-lee           #+#    #+#             */
/*   Updated: 2021/07/05 17:34:21 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_chunk(const char *s, char c)
{
	size_t		count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && (*s != c))
				s++;
		}
		else
			s++;
	}
	return (count);
}

static void	copy_to_cntnr(char *cntnr, const char *start, const char *end)
{
	while (start < end)
		*cntnr++ = *start++;
	*cntnr = 0;
}

static void	free_cntnr(char **cntnr, size_t cdx)
{
	size_t		idx;

	idx = 0;
	while (idx < cdx)
		free(cntnr[idx++]);
	free(cntnr);
}

char	**ft_split(char const *s, char c)
{
	char		**cntnr;
	char		*start;
	size_t		idx;

	cntnr = (char **)malloc(sizeof(char *) * (get_chunk(s, c) + 1));
	if (!cntnr)
		return (0);
	idx = 0;
	while (*s)
	{
		if (*s != c)
		{
			start = (char *)s;
			while (*s && (*s != c))
				s++;
			cntnr[idx] = (char *)malloc(s - start + 1);
			if (!cntnr[idx])
				free_cntnr(cntnr, idx);
			copy_to_cntnr(cntnr[idx++], start, s);
		}
		else
			s++;
	}
	cntnr[idx] = 0;
	return (cntnr);
}
