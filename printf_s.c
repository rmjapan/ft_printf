/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiyauch <rmiyauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 21:39:15 by rmiyauch          #+#    #+#             */
/*   Updated: 2024/01/31 22:01:35 by rmiyauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/miyauchiryuuichi/Downloads/42tokyo/ft_printf/include/ft_printf.h"
#include "/Users/miyauchiryuuichi/Downloads/42tokyo/ft_printf/include/libft.h"
#include <stdio.h>

char	*str = "12345";

void	minus_field_s(all_type_conversion_specifier *memo)
{
	unsigned int	str_len;

	str_len = ft_strlen(str);
	write(1, str, str_len);
	while (memo->width_flag-- > str_len)
		write(1, " ", 1);
}

void	non_minus_field_s(all_type_conversion_specifier *memo)
{
	unsigned int	str_len;

	str_len = ft_strlen(str);
	while (memo->width_flag-- > str_len)
	{
		if (memo->zero_flag == true)
			write(1, "0", 1);
		else
			write(1, " ", 1);
	}
	write(1, str, str_len);
}
void	print_s(all_type_conversion_specifier *memo)
{
	if (memo->minus_flag == true)
		minus_field_s(memo);
	else
	{
		non_minus_field_s(memo);
	}
}
