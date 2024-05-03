/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiyauch <rmiyauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 15:39:00 by rmiyauch          #+#    #+#             */
/*   Updated: 2024/05/03 15:15:01 by rmiyauch         ###   ########.fr       */
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

void	write_char(char c, int *return_result)
{
	write(1, &c, 1);
	*return_result += 1;
}
