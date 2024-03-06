/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiyauch <rmiyauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:51:42 by rmiyauch          #+#    #+#             */
/*   Updated: 2024/03/05 16:56:09 by rmiyauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	minus_field_precision_p(t_printf_format *memo, int *return_result)
{
	char			*p_value;
	unsigned int	p_len;
	unsigned int	width_minus_p_len;
	unsigned int	prec_minus_p_len;
	int				space_len;

	p_value = itoa_hexa(memo->p, 3);
	p_len = ft_strlen(p_value);
	*return_result += p_len + 2;
	width_minus_p_len = a_minus_b(memo->field_width, p_len);
	prec_minus_p_len = a_minus_b(memo->precsion_width, p_len);
	write(1, "0x", 2);
	while (memo->precsion_width-- > (int)(p_len))
	{
		write(1, "0", 1);
		*return_result += 1;
	}
	write(1, p_value, p_len);
	space_len = a_minus_b(width_minus_p_len, prec_minus_p_len);
	while (space_len-- > 2)
	{
		write(1, " ", 1);
		*return_result += 1;
	}
	free(p_value);
}

void	zero_field_precision_p(t_printf_format *memo, int *return_result)
{
	char			*p_value;
	unsigned int	p_len;

	p_value = itoa_hexa(memo->p, 3);
	p_len = ft_strlen(p_value);
	*return_result += p_len + 2;
	write(1, "0x", 2);
	while (memo->field_width-- > (int)(p_len + 2))
	{
		write(1, "0", 1);
		*return_result += 1;
	}
	write(1, p_value, p_len);
	free(p_value);
}

void	field_precision_p(t_printf_format *memo, int *return_result)
{
	char			*p_value;
	unsigned int	p_len;
	unsigned int	width_minus_p_len;
	unsigned int	prec_minus_p_len;
	int				space_len;

	p_value = itoa_hexa(memo->p, 3);
	p_len = ft_strlen(p_value);
	*return_result += p_len + 2;
	width_minus_p_len = a_minus_b(memo->field_width, p_len);
	prec_minus_p_len = a_minus_b(memo->precsion_width, p_len);
	space_len = a_minus_b(width_minus_p_len, prec_minus_p_len);
	while (space_len-- > 2)
	{
		write(1, " ", 1);
		*return_result += 1;
	}
	write(1, "0x", 2);
	while (memo->precsion_width-- > (int)(p_len))
	{
		write(1, "0", 1);
		*return_result += 1;
	}
	write(1, p_value, p_len);
	free(p_value);
}

void	printf_p(t_printf_format *memo, int *return_result)
{
	if (memo->minus_flag == true)
	{
		minus_field_precision_p(memo, return_result);
	}
	else if (memo->zero_flag == true)
	{
		zero_field_precision_p(memo, return_result);
	}
	else
	{
		field_precision_p(memo, return_result);
	}
}
