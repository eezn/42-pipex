/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42Seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 00:05:17 by jin-lee           #+#    #+#             */
/*   Updated: 2021/07/05 11:51:16 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print(unsigned int un, int fd)
{
	if (un == 0)
		return ;
	ft_print(un / 10, fd);
	ft_putchar_fd(un % 10 + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	un;

	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n < 0)
	{
		un = n * (-1);
		write(fd, "-", 1);
	}
	else
		un = n;
	ft_print(un, fd);
}
