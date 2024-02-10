/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiyauch <rmiyauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:41:10 by rmiyauch          #+#    #+#             */
/*   Updated: 2024/02/10 12:44:32 by rmiyauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/miyauchiryuuichi/Downloads/42tokyo/ft_printf/include/ft_printf.h"
#include "/Users/miyauchiryuuichi/Downloads/42tokyo/ft_printf/include/libft.h"
#include <stdio.h>

void	minus_field_c(t_printf_format *memo)
{
	write(1, &memo->c, 1);
	while (memo->field_width-- > 1)
		write(1, " ", 1);
}

void	non_minus_field_c(t_printf_format *memo)
{
	while (memo->field_width-- > 1)
	{
		if (memo->zero_flag == true)
			write(1, "0", 1);
		else
			write(1, " ", 1);
	}
	write(1, &memo->c, 1);
}

void	print_c(t_printf_format *memo)
{
	if (memo->minus_flag == true)
		minus_field_c(memo);
	else
	{
		non_minus_field_c(memo);
	}
}
