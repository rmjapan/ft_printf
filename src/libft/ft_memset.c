/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiyauch <rmiyauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:26:57 by rmiyauch          #+#    #+#             */
/*   Updated: 2023/10/30 14:55:56 by rmiyauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			count;
	unsigned char	*p;

	p = (unsigned char *)str;
	count = 0;
	while (count < n)
	{
		*p++ = c;
		count++;
	}
	return (str);
}
