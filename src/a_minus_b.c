/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_minus_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiyauch <rmiyauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:05:10 by rmiyauch          #+#    #+#             */
/*   Updated: 2024/02/25 14:38:01 by rmiyauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	a_minus_b(int a, int b)
{
	if (a > b)
		return (a - b);
	else
		return (0);
}
