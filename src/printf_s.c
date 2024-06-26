/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiyauch <rmiyauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 21:39:15 by rmiyauch          #+#    #+#             */
/*   Updated: 2024/04/07 16:42:29 by rmiyauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	minus_field_s(t_printf_format *memo, int *return_result)
{
	int	str_len;

	if (memo->s == NULL)
		memo->s = "(null)";
	str_len = ft_strlen(memo->s);
	*return_result += str_len;
	write(1, memo->s, str_len);
	while (memo->field_width-- > str_len)
	{
		write(1, " ", 1);
		*return_result += 1;
	}
}

void	non_minus_field_s(t_printf_format *memo, int *return_result)
{
	int	str_len;

	if (memo->s == NULL)
		memo->s = "(null)";
	str_len = ft_strlen(memo->s);
	*return_result += str_len;
	while (memo->field_width-- > str_len)
	{
		if (memo->zero_flag == true)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		*return_result += 1;
	}
	write(1, memo->s, str_len);
}

void	field_precision_s(t_printf_format *memo, int *return_result)
{
	int		str_len;
	char	*ptr;
	int		len;

	ptr = memo->s;
	if (memo->s == NULL)
		memo->s = "(null)";
	str_len = ft_strlen(memo->s);
	if (memo->precsion_width < str_len)
	{
		len = memo->precsion_width;
	}
	else
	{
		len = str_len;
	}
	while (len-- > 0)
	{
		ft_putchar_fd(*ptr, 1);
		*return_result += 1;
		ptr++;
	}
}

void	printf_s(t_printf_format *memo, int *return_result)
{
	if (memo->minus_flag == true)
		minus_field_s(memo, return_result);
	else
	{
		if (memo->precsion_width != -1)
		{
			field_precision_s(memo, return_result);
		}
		else
		{
			non_minus_field_s(memo, return_result);
		}
	}
}
