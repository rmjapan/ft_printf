/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiyauch <rmiyauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:41:10 by rmiyauch          #+#    #+#             */
/*   Updated: 2024/03/05 12:49:57 by rmiyauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	minus_field_c(t_printf_format *memo, int *return_result)
{
	char	c;

	c = (char)memo->c;
	ft_putchar_fd(c, 1);
	*return_result += 1;
	while (memo->field_width-- > 1)
	{
		write(1, " ", 1);
		*return_result += 1;
	}
}

void	non_minus_field_c(t_printf_format *memo, int *return_result)
{
	char	c;

	c = (char)memo->c;
	while (memo->field_width-- > 1)
	{
		if (memo->zero_flag == true)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		*return_result += 1;
	}
	ft_putchar_fd(c, 1);
	*return_result += 1;
}

void	printf_c(t_printf_format *memo, int *return_result)
{
	if (memo->minus_flag == true)
		minus_field_c(memo, return_result);
	else
	{
		non_minus_field_c(memo, return_result);
	}
}
