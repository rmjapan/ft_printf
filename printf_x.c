/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiyauch <rmiyauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:46:10 by rmiyauch          #+#    #+#             */
/*   Updated: 2024/02/10 12:49:35 by rmiyauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/miyauchiryuuichi/Downloads/42tokyo/ft_printf/include/ft_printf.h"
#include "/Users/miyauchiryuuichi/Downloads/42tokyo/ft_printf/include/libft.h"

void	minus_field_precision_x(t_printf_format *memo)
{
	char			*x_value;
	unsigned int	x_len;
	unsigned int	width_minus_x_len;
	unsigned int	prec_minus_x_len;

	x_value = itoa_hexa(memo->x, 7);
	x_len = ft_strlen(x_value);
	width_minus_x_len = a_minus_b(memo->field_width, x_len);
	prec_minus_x_len = a_minus_b(memo->precsion_width, x_len);
	while (memo->precsion_width-- > (int)(x_len))
		write(1, "0", 1);
	write(1, x_value, sizeof(x_value));
	while (width_minus_x_len-- > prec_minus_x_len)
		write(1, " ", 1);
}

void	zero_field_x(t_printf_format *memo)
{
	char			*x_value;
	unsigned int	x_len;

	x_value = itoa_hexa(memo->x, 7);
	x_len = ft_strlen(x_value);
	while (memo->field_width-- > (int)(x_len))
		write(1, "0", 1);
	write(1, x_value, sizeof(x_value));
}

void	field_precision_x(t_printf_format *memo)
{
	char			*x_value;
	unsigned int	x_len;
	unsigned int	width_minus_x_len;
	unsigned int	prec_minus_x_len;

	x_value = itoa_hexa(memo->x, 7);
	x_len = ft_strlen(x_value);
	width_minus_x_len = a_minus_b(memo->field_width, x_len);
	prec_minus_x_len = a_minus_b(memo->precsion_width, x_len);
	while (width_minus_x_len-- > prec_minus_x_len)
		write(1, " ", 1);
	while (memo->precsion_width-- > (int)(x_len))
		write(1, "0", 1);
	write(1, x_value, sizeof(x_value));
}

void	print_x(t_printf_format *memo)
{
	if (memo->minus_flag == true)
	{
		minus_field_precision_x(memo);
	}
	else if (memo->zero_flag == true)
	{
		zero_field_x(memo);
	}
	else
	{
		field_precision_x(memo);
	}
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>

// Dedicated test function for %x scenarios
// void	test_printf_x(t_printf_format *memo)
// {
// 	printf("マイナスフラグ: %d /", memo->minus_flag);
// 	printf("ゼロフラグ: %d /", memo->zero_flag);
// 	printf("精度フラグ: %d /", memo->precsion_width);
// 	printf("フィールド幅フラグ: %d /", memo->field_width);
// 	printf("出力値: %d\n", memo->x);
// 	char format[50]; // To hold the format string for dynamic configuration
// 	// Building the format string based on specified flags and precision
// 	if (memo->minus_flag)
// 	{
// 		printf("マイナスフラグが存在する場合\n");
// 		snprintf(format, sizeof(format), "Std:  [%%-%d.%dx]\n",
// 			memo->field_width, memo->precsion_width);
// 	}
// 	else if (memo->zero_flag && memo->precsion_width < 0)
// 	{
// 		printf("ゼロフラグが存在する場合\n");
// 		snprintf(format, sizeof(format), "Std:  [%%0%d.%dx]\n",
// 			memo->field_width,
// 					memo->precsion_width); // Width duplicated for zero padding
// 	}
// 	else
// 	{
// 		memo->zero_flag = false;
// 		printf("フラグが存在しない場合\n");
// 		snprintf(format, sizeof(format), "Std:  [%%%d.%dx]\n", memo->field_width,
// 			memo->precsion_width);
// 	}
// 	// Benchmark output with standard printf function
// 	printf(format, memo->x);
// 	// Prefix for custom printf function output
// 	write(1, "Cust: [", 7);
// 	print_x(memo);
// 	// Invoke custom function to simulate `%x` output via `ft_printf`
// 	write(1, "]\n", 2);
// 	printf("\n");
// }

// int	main(void)
// {
// 	t_printf_format	*memo;

// 	memo = (t_printf_format *)malloc(sizeof(t_printf_format));
// 	// Test configuration for %x conversion specifier tests
// 	unsigned int test_values[] = {0, 1, 3, 255, 0xFFFF, 0xFFFFFFFF};
// 	// Including edge cases
// 	int field_widths[] = {1, 4, 8};
// 	// Example field widths
// 	int precisions[] = {1, 2, 4};
// 	// Precision settings, -1 for no precision
// 	bool flags[][2] = {{false, false}, {true, false}, {false, true}};
// 	// Flag configurations: no flags, minus, zero
// 	for (int i = 0; i < sizeof(test_values) / sizeof(test_values[0]); i++)
// 	{
// 		for (int w = 0; w < sizeof(field_widths) / sizeof(field_widths[0]); w++)
// 		{
// 			for (int p = 0; p < sizeof(precisions) / sizeof(precisions[0]); p++)
// 			{
// 				for (int f = 0; f < sizeof(flags) / sizeof(flags[0]); f++)
// 				{
// 					memo->x = test_values[i];
// 					memo->field_width = field_widths[w];
// 					memo->precsion_width = precisions[p];
// 					memo->minus_flag = flags[f][0];
// 					memo->zero_flag = flags[f][1];
// 					// Execute custom test function
// 					test_printf_x(memo);
// 				}
// 			}
// 		}
// 	}
// 	// Deallocate memory
// 	free(memo);
// 	return (0);
// }
