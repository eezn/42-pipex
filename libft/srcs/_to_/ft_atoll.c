/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42Seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 10:37:28 by jin-lee           #+#    #+#             */
/*   Updated: 2021/07/05 16:01:41 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_int64_max_overflow(const char *str)
{
	char	*int64_max;
	size_t	i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	int64_max = "9223372036854775807";
	if (i < ft_strlen(int64_max))
		return (0);
	while (ft_isdigit(*str))
		if (*str++ > *int64_max++)
			return (1);
	return (0);
}

static int	is_int64_min_underflow(const char *str)
{
	char	*int64_min;
	size_t	i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	int64_min = "9223372036854775808";
	if (i < ft_strlen(int64_min))
		return (0);
	while (ft_isdigit(*str))
		if (*str++ > *int64_min++)
			return (1);
	return (0);
}

long long	ft_atoll(const char *str)
{
	long long		ret;
	int				sign;

	ret = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= (-1);
		str++;
	}
	if (sign > 0)
	{
		if (is_int64_max_overflow(str))
			return (-1);
	}
	else if (sign < 0)
		if (is_int64_min_underflow(str))
			return (0);
	while (ft_isdigit(*str))
		ret = ret * 10 + (*str++ - '0');
	return (ret * sign);
}
