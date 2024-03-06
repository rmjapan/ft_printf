/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiyauch <rmiyauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:42:57 by rmiyauch          #+#    #+#             */
/*   Updated: 2023/11/13 21:01:58 by rmiyauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int ch, size_t n)
{
	const char	*s;
	size_t		i;

	s = (const char *)buf;
	i = 0;
	while (i < n)
	{
		if (s[i] == (char)ch)
		{
			return ((void *)s + i);
		}
		i++;
	}
	return (NULL);
}
