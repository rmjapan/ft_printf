/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiyauch <rmiyauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:16:13 by rmiyauch          #+#    #+#             */
/*   Updated: 2023/11/01 12:13:13 by rmiyauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*result;
	size_t			result_len;
	long long int	i;
	long long int	j;

	i = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (ft_strchr(set, s1[i]) != NULL && s1[i] != '\0')
		i++;
	j = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[j]) != NULL && j >= 0)
		j--;
	if (i <= j)
	{
		result_len = j - i + 1;
		result = (char *)malloc(sizeof(char) * result_len + 1);
		if (result == NULL)
			return (NULL);
		ft_strlcpy(result, s1 + i, result_len + 1);
		return (result);
	}
	result = ft_strdup("");
	return (result);
}
