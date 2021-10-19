/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42Seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 10:40:36 by jin-lee           #+#    #+#             */
/*   Updated: 2021/07/05 10:43:12 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_vecjoin(char **v1, char **v2)
{
	char	**ret;
	char	**tmp;
	char	**free_v1;
	char	**free_v2;
	size_t	total_len;

	if (!v1 || !v2)
		return (NULL);
	total_len = ft_veclen(v1) + ft_veclen(v2);
	ret = (char **)malloc(sizeof(char *) * (total_len + 1));
	if (!ret)
		return (NULL);
	tmp = ret;
	free_v1 = v1;
	free_v2 = v2;
	while (*v1)
		*tmp++ = *v1++;
	while (*v2)
		*tmp++ = *v2++;
	*tmp = 0;
	free(free_v1);
	free(free_v2);
	return (ret);
}
