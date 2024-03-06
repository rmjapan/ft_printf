/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiyauch <rmiyauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:50:59 by rmiyauch          #+#    #+#             */
/*   Updated: 2023/10/31 13:36:25 by rmiyauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*p;

	if (n && size && n > (4294967295 / size))
		return (NULL);
	p = (void *)malloc(n * size);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, n * size);
	return (p);
}
