/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiyauch <rmiyauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:52:03 by rmiyauch          #+#    #+#             */
/*   Updated: 2024/05/03 15:50:13 by rmiyauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	from_percent_to_conversion_specifier_len(const char *format)
{
	size_t	len;

	len = 0;
	while (!is_conversion_specifier(format[len++]))
		;
	return (len);
}

t_printf_format	*set_minus_precision_value(const char *format, va_list *target)
{
	t_printf_format	*memo;

	if (is_conversion_specifier(*format))
	{
		memo = (t_printf_format *)malloc(sizeof(t_printf_format) * 1);
		if (!memo)
			return (NULL);
		init_t_printf_format(memo);
		memo = set_id_type_conv_spec(memo, *format, target);
		return (memo);
	}
	else
	{
		memo = set_minus_precision_value(format + 1, target);
		if (*format == '.')
		{
			memo->precsion_width = ft_atoi(format + 1);
		}
		if (*format == '-')
		{
			memo->minus_flag = true;
		}
		return (memo);
	}
}

const char	*output_format(const char *p, va_list *target,
		t_printf_format *memo, int *return_result)
{
	if (*p == '%')
	{
		if (*(p + 1) == '\0')
			return (p);
		p++;
		if (*p == '%')
			write_char('%', return_result);
		else
		{
			memo = set_minus_precision_value(p, target);
			memo = set_zero_flag(memo, p);
			memo = set_field_width_flag(memo, p);
			printf_target(memo, return_result);
			p = p + from_percent_to_conversion_specifier_len(p) - 1;
			free(memo);
		}
	}
	else
		write_char(*p, return_result);
	return (p);
}

int	ft_printf(const char *format, ...)
{
	va_list			target;
	const char		*p;
	t_printf_format	*memo;
	int				return_result;

	return_result = 0;
	memo = NULL;
	va_start(target, format);
	p = format;
	while (*p != '\0')
	{
		p = output_format(p, &target, memo, &return_result);
		p++;
	}
	va_end(target);
	return (return_result);
}
