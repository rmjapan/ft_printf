/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_xx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiyauch <rmiyauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:49:51 by rmiyauch          #+#    #+#             */
/*   Updated: 2024/03/06 12:35:59 by rmiyauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	minus_field_precision_xx(t_printf_format *memo, int *return_result)
{
	char			*xx_value;
	unsigned int	xx_len;
	unsigned int	width_minus_xx_len;
	unsigned int	prec_minus_xx_len;

	xx_value = itoa_hexa(memo->xx, 8);
	xx_len = ft_strlen(xx_value);
	*return_result += xx_len;
	width_minus_xx_len = a_minus_b(memo->field_width, xx_len);
	prec_minus_xx_len = a_minus_b(memo->precsion_width, xx_len);
	while (memo->precsion_width-- > (int)xx_len)
	{
		write(1, "0", 1);
		*return_result += 1;
	}
	write(1, xx_value, xx_len);
	while (width_minus_xx_len-- > prec_minus_xx_len)
	{
		write(1, " ", 1);
		*return_result += 1;
	}
	free(xx_value);
}

void	zero_field_precision_xx(t_printf_format *memo, int *return_result)
{
	char			*xx_value;
	unsigned int	xx_len;

	xx_value = itoa_hexa(memo->xx, 8);
	xx_len = ft_strlen(xx_value);
	*return_result += xx_len;
	while (memo->field_width-- > (int)(xx_len))
	{
		write(1, "0", 1);
		*return_result += 1;
	}
	write(1, xx_value, xx_len);
	free(xx_value);
}

void	field_precision_xx(t_printf_format *memo, int *return_result)
{
	char			*xx_value;
	unsigned int	xx_len;
	unsigned int	width_minus_xx_len;
	unsigned int	prec_minus_xx_len;

	xx_value = itoa_hexa(memo->xx, 8);
	xx_len = ft_strlen(xx_value);
	*return_result += xx_len;
	width_minus_xx_len = a_minus_b(memo->field_width, xx_len);
	prec_minus_xx_len = a_minus_b(memo->precsion_width, xx_len);
	while (width_minus_xx_len-- > prec_minus_xx_len)
	{
		write(1, " ", 1);
		*return_result += 1;
	}
	while (memo->precsion_width-- > (int)xx_len)
	{
		write(1, "0", 1);
		*return_result += 1;
	}
	write(1, xx_value, xx_len);
	free(xx_value);
}

void	printf_xx(t_printf_format *memo, int *return_result)
{
	if (memo->minus_flag == true)
	{
		minus_field_precision_xx(memo, return_result);
	}
	else if (memo->zero_flag == true)
	{
		zero_field_precision_xx(memo, return_result);
	}
	else
	{
		field_precision_xx(memo, return_result);
	}
}

// void	test_ft_printf_x(void)
// {
// 	t_printf_format	*memo;

// 	memo = (t_printf_format *)malloc(sizeof(t_printf_format));
// 	memo->xx = 10;
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