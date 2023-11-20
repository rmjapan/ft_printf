/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiyauch <rmiyauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:01:53 by rmiyauch          #+#    #+#             */
/*   Updated: 2023/11/01 13:06:02 by rmiyauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_fd2(long long n, int fd)
{
	int	k;

	k = 0;
	if (n < 10)
	{
		ft_putchar_fd(n + '0', fd);
		return ;
	}
	else
	{
		ft_putnbr_fd2(n / 10, fd);
		k = n % 10;
		ft_putchar_fd(k + '0', fd);
		return ;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long long int	p;

	p = (long long int)n;
	if (p < 0)
	{
		write(fd, "-", 1);
		p = -p;
	}
	ft_putnbr_fd2(p, fd);
}
