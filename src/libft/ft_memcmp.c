/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiyauch <rmiyauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:44:06 by rmiyauch          #+#    #+#             */
/*   Updated: 2023/11/01 10:50:57 by rmiyauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	*s;
	int				result;

	if (buf1 == NULL && buf2 == NULL)
		return (0);
	i = 0;
	result = 0;
	p = (unsigned char *)buf1;
	s = (unsigned char *)buf2;
	while (i < n)
	{
		if (s[i] != p[i])
		{
			result = (int)(*(p + i) - *(s + i));
			break ;
		}
		i++;
	}
	return (result);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {

// 	char* buf4 = NULL;
// 	char* buf5 = NULL;

// 	//printf("ft_memcmp: %d\n", ft_memcmp(buf4, buf5, 1));
// 	printf("memcmp: %d\n", memcmp(buf4, buf5, 1));
// 	return (0);
// }