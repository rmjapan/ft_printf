/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_hexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiyauch <rmiyauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:30:41 by rmiyauch          #+#    #+#             */
/*   Updated: 2024/03/05 17:12:48 by rmiyauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	convert_hexa(unsigned long long n, char *p, char a_or_aa)
{
	size_t	k;

	if (n < 16)
	{
		k = 0;
		if (n < 10)
			p[k++] = n + '0';
		else
			p[k++] = n + a_or_aa - 10;
		return (k);
	}
	else
	{
		k = 0;
		k = convert_hexa(n / 16, p, a_or_aa);
		if (n % 16 < 10)
			p[k++] = n % 16 + '0';
		else
			p[k++] = n % 16 + a_or_aa - 10;
		return (k);
	}
}

static size_t	hexa_keta_size(unsigned long long n)
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

char	*itoa_hexa(unsigned long long n, int type)
{
	size_t	keta_size;
	char	*p;
	size_t	i;
	char	a_or_aa;

	a_or_aa = 'a';
	if (type == 8)
		a_or_aa = 'A';
	keta_size = hexa_keta_size(n);
	p = (char *)malloc(sizeof(char) * (keta_size + 1));
	if (p == NULL)
		return (NULL);
	i = convert_hexa(n, p, a_or_aa);
	p[i] = '\0';
	return (p);
}
