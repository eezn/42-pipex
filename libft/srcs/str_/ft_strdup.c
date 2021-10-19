/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42Seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 20:00:02 by jin-lee           #+#    #+#             */
/*   Updated: 2021/01/15 23:47:43 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dup;
	int		len;

	len = ft_strlen(src);
	dup = (char *)ft_calloc((len + 1), sizeof(char));
	if (!dup)
		return (NULL);
	ft_strcpy(dup, src);
	return (dup);
}
