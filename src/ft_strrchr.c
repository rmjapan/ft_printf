/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiyauch <rmiyauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:40:40 by rmiyauch          #+#    #+#             */
/*   Updated: 2023/10/30 17:39:17 by rmiyauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	size_t	size;
	size_t	i;

	size = ft_strlen(s);
	i = 0;
	p = NULL;
	while (i <= size)
	{
		if (s[i] == (char)c)
		{
			p = (char *)s + i;
		}
		i++;
	}
	return (p);
}
