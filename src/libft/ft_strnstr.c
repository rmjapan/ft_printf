/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiyauch <rmiyauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:45:01 by rmiyauch          #+#    #+#             */
/*   Updated: 2023/11/13 21:33:44 by rmiyauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	len;
	size_t	i;

	if (s1 == NULL && n == 0)
		return (NULL);
	if (*s2 == '\0')
		return ((char *)s1);
	len = ft_strlen(s2);
	i = 0;
	while (s1[i] != '\0' && i + len <= n)
	{
		if (s1[i] == *s2 && ft_strncmp(s1 + i, s2, len) == 0)
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
