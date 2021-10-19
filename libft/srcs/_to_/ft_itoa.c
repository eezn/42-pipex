/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42Seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 01:21:36 by jin-lee           #+#    #+#             */
/*   Updated: 2021/07/05 20:07:51 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_negative(int n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

static unsigned int	get_abs(int n)
{
	if (n < 0)
		return ((unsigned int)(n * (-1)));
	else
		return ((unsigned int)(n));
}

static size_t	get_len(unsigned int n)
{
	size_t	len;

	len = 1;
	n /= 10;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*ret;
	unsigned int	un;
	int				sign;
	int				len;

	sign = is_negative(n);
	un = get_abs(n);
	len = sign + get_len(un);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	if (un == 0)
		ret[0] = '0';
	if (sign == 1)
		ret[0] = '-';
	ret[len--] = '\0';
	while (un != 0)
	{
		ret[len--] = un % 10 + '0';
		un /= 10;
	}
	return (ret);
}
