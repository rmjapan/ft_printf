/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_hexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiyauch <rmiyauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:30:41 by rmiyauch          #+#    #+#             */
/*   Updated: 2024/02/10 14:18:48 by rmiyauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/miyauchiryuuichi/Downloads/42tokyo/ft_printf/include/ft_printf.h"
#include "/Users/miyauchiryuuichi/Downloads/42tokyo/ft_printf/include/libft.h"
#include <stdio.h>

static size_t	convert_hexa(long long n, char *p, char a_OR_A)
{
	size_t	k;

	if (n < 16)
	{
		k = 0;
		if (n < 10)
			p[k++] = n + '0';
		else
			p[k++] = n + a_OR_A - 10;
		return (k);
	}
	else
	{
		k = 0;
		k = convert_hexa(n / 16, p, a_OR_A);
		if (n % 16 < 10)
			p[k++] = n % 16 + '0';
		else
			p[k++] = n % 16 + a_OR_A - 10;
		return (k);
	}
}

static size_t	hexa_keta_size(long long n)
{
	int	hexa_keta_size;

	hexa_keta_size = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 16;
		hexa_keta_size++;
	}
	return (hexa_keta_size);
}

char	*itoa_hexa(unsigned int n, int type)
{
	size_t	keta_size;
	char	*p;
	size_t	i;
	char	a_OR_A;

	a_OR_A = 'a';
	if (type == 8)
		a_OR_A = 'A';
	keta_size = hexa_keta_size(n);
	p = (char *)malloc(sizeof(char) * (keta_size + 1));
	if (p == NULL)
		return (NULL);
	i = convert_hexa(n, p, a_OR_A);
	p[i] = '\0';
	return (p);
}
