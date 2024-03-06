/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiyauch <rmiyauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:30:41 by rmiyauch          #+#    #+#             */
/*   Updated: 2024/02/25 13:52:57 by rmiyauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_itoa1(long long n, char *p, int flag)
{
	size_t	k;

	if (n < 10)
	{
		k = 0;
		if (flag == 1)
		{
			p[k++] = '-';
		}
		p[k++] = n + '0';
		return (k);
	}
	else
	{
		k = 0;
		k = ft_itoa1(n / 10, p, flag);
		p[k++] = n % 10 + '0';
		return (k);
	}
}

static size_t	ketasize(long long n)
{
	int	keta_size;

	keta_size = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		keta_size++;
	}
	return (keta_size);
}

char	*ft_itoa_u(size_t n)
{
	size_t		keta_size;
	long long	n1;
	char		*p;
	size_t		i;
	size_t		flag;

	flag = 0;
	n1 = (long long)n;
	if (n1 < 0)
	{
		n1 = -n1;
		flag = 1;
	}
	keta_size = ketasize(n1);
	p = (char *)malloc(sizeof(char) * (keta_size + flag + 1));
	if (p == NULL)
		return (NULL);
	i = ft_itoa1(n1, p, flag);
	p[i] = '\0';
	return (p);
}
