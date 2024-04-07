/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiyauch <rmiyauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 15:39:00 by rmiyauch          #+#    #+#             */
/*   Updated: 2024/04/07 21:14:29 by rmiyauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_chars(char c, int count, int *return_result, int compared_number)
{
	while (count-- > compared_number)
	{
		write(1, &c, 1);
		*return_result += 1;
	}
}
