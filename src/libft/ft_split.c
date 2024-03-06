/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiyauch <rmiyauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:24:11 by rmiyauch          #+#    #+#             */
/*   Updated: 2023/11/14 11:21:17 by rmiyauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*check(char *t, char const *a, char const *b)
{
	char	*p;
	size_t	len;

	len = 0;
	p = t;
	while (a != b)
	{
		p[len++] = *a;
		a++;
	}
	p[len] = '\0';
	return (p);
}

static long long	ft_split_len(const char *s, char c)
{
	long long	count;

	if (s == NULL)
		return (-1);
	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static size_t	ft_split_strlen(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		if (*s == c)
			break ;
		s++;
		len++;
	}
	return (len);
}

char	**size_free(char **result, size_t size)
{
	size_t	i;

	i = 0;
	while (i <= size)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	long long	result_len;
	char		**result;
	size_t		i;
	size_t		len;

	result_len = ft_split_len(s, c);
	result = (char **)malloc(sizeof(char *) * result_len + 1);
	if (result == NULL || result_len == -1)
		return (NULL);
	i = 0;
	while (*s != '\0' && i < (size_t)result_len)
	{
		while (*s == c)
			s++;
		len = ft_split_strlen(s, c);
		result[i] = (char *)malloc(sizeof(char) * len + 1);
		if (result[i] == NULL)
			return (size_free(result, i));
		result[i] = check(result[i], s, s + len);
		s = s + len;
		i++;
	}
	result[i] = NULL;
	return (result);
}
