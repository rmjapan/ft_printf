/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiyauch <rmiyauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:35:42 by rmiyauch          #+#    #+#             */
/*   Updated: 2023/11/14 13:28:12 by rmiyauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_size;
	size_t	max;
	size_t	j;

	if (dst == NULL && dstsize == 0)
		return (ft_strlen(src));
	dst_size = ft_strlen(dst);
	if (dstsize == 0)
	{
		return (ft_strlen(src));
	}
	if (dstsize <= dst_size)
	{
		return (ft_strlen(src) + dstsize);
	}
	max = dstsize - dst_size - 1;
	j = 0;
	while (src[j] != '\0' && j < max)
	{
		dst[dst_size + j] = src[j];
		j++;
	}
	dst[dst_size + j] = '\0';
	return (dst_size + ft_strlen(src));
}
