/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiyauch <rmiyauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:36:56 by rmiyauch          #+#    #+#             */
/*   Updated: 2023/11/13 21:37:32 by rmiyauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*t;
	size_t	count;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (len == 0 || start >= s_len || s == NULL)
	{
		len = 0;
	}
	if (len > s_len - start)
		len = s_len - start;
	t = (char *)malloc(sizeof(char) * len + 1);
	if (t == NULL)
		return (NULL);
	count = 0;
	while (count < len && s[start + count] != '\0')
	{
		t[count] = s[start + count];
		count++;
	}
	t[count] = '\0';
	return (t);
}
