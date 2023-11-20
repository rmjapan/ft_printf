/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiyauch <rmiyauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:56:18 by rmiyauch          #+#    #+#             */
/*   Updated: 2023/11/01 13:08:21 by rmiyauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*t;
	size_t	size;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	t = (char *)malloc(sizeof(char) * (size + 1));
	if (t == NULL)
		return (NULL);
	i = 0;
	while (*s1 != '\0')
	{
		t[i] = *s1++;
		i++;
	}
	while (*s2 != '\0')
	{
		t[i] = *s2++;
		i++;
	}
	t[i] = '\0';
	return (t);
}
