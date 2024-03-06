/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiyauch <rmiyauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:29:42 by rmiyauch          #+#    #+#             */
/*   Updated: 2023/10/30 16:28:31 by rmiyauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*p1;
	const unsigned char	*p2;

	p1 = (unsigned char *)dest;
	p2 = (const unsigned char *)src;
	if (p1 == NULL && p2 == NULL)
		return (NULL);
	while (n > 0)
	{
		*p1++ = *p2++;
		n--;
	}
	return (dest);
}
