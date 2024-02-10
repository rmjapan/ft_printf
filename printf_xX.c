/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_xX.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiyauch <rmiyauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:49:51 by rmiyauch          #+#    #+#             */
/*   Updated: 2024/02/10 15:11:51 by rmiyauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/miyauchiryuuichi/Downloads/42tokyo/ft_printf/include/ft_printf.h"
#include "/Users/miyauchiryuuichi/Downloads/42tokyo/ft_printf/include/libft.h"
#include <stdio.h>

unsigned int	a_minus_b(int a, int b)
{
	if (a > b)
		return (a - b);
	else
		return (0);
}

void	minus_field_precision_X(t_printf_format *memo)
{
	char			*X_value;
	unsigned int	X_len;
	unsigned int	width_minus_X_len;
	unsigned int	prec_minus_X_len;

	X_value = itoa_hexa(memo->X, 8);
	X_len = ft_strlen(X_value);
	width_minus_X_len = a_minus_b(memo->field_width, X_len);
	prec_minus_X_len = a_minus_b(memo->precsion_width, X_len);
	while (memo->precsion_width-- > (int)X_len)
		write(1, "0", 1);
	write(1, X_value, sizeof(X_value));
	while (width_minus_X_len-- > prec_minus_X_len)
		write(1, " ", 1);
}

void	zero_field_precision_X(t_printf_format *memo)
{
	char			*X_value;
	unsigned int	X_len;

	X_value = itoa_hexa(memo->X, 8);
	X_len = ft_strlen(X_value);
	while (memo->field_width-- > (int)(X_len))
		write(1, "0", 1);
	write(1, X_value, sizeof(X_value));
}

void	field_precision_X(t_printf_format *memo)
{
	char			*X_value;
	unsigned int	X_len;
	unsigned int	width_minus_X_len;
	unsigned int	prec_minus_X_len;

	X_value = itoa_hexa(memo->X, 8);
	X_len = ft_strlen(X_value);
	width_minus_X_len = a_minus_b(memo->field_width, X_len);
	prec_minus_X_len = a_minus_b(memo->precsion_width, X_len);
	while (width_minus_X_len-- > prec_minus_X_len)
		write(1, " ", 1);
	while (memo->precsion_width-- > (int)X_len)
		write(1, "0", 1);
	write(1, X_value, sizeof(X_value));
}

void	print_X(t_printf_format *memo)
{
	if (memo->minus_flag == true)
	{
		minus_field_precision_X(memo);
	}
	else if (memo->zero_flag == true)
	{
		zero_field_precision_X(memo);
	}
	else
	{
		field_precision_X(memo);
	}
}

// void	test_ft_printf_x(void)
// {
// 	t_printf_format	*memo;

// 	memo = (t_printf_format *)malloc(sizeof(t_printf_format));
// 	memo->X = 10;
// 	memo->precsion_width = 300;
// 	memo->field_width = 10;
// 	memo->minus_flag = true;
// 	memo->zero_flag = false;
// 	print_X(memo);
// 	printf("\n");
// 	printf("%-10.300X]", 10);
// }
// int	main(void)
// {
// 	test_ft_printf_x();

// 	return (0);
// }