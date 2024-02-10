/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiyauch <rmiyauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:52:03 by rmiyauch          #+#    #+#             */
/*   Updated: 2024/02/10 15:26:25 by rmiyauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/miyauchiryuuichi/Downloads/42tokyo/ft_printf/include/ft_printf.h"
#include "/Users/miyauchiryuuichi/Downloads/42tokyo/ft_printf/include/libft.h"

size_t	from_percent_to_conversion_specifier_len(char *format)
{
	size_t	len;

	len = 0;
	while (!is_conversion_specifier(format[len++]))
		return (len);
}

t_printf_format	*set_minus_precision_value(char *format, va_list target)
{
	t_printf_format	*memo;

	if (is_conversion_specifier(format))
	{
		memo = init_t_printf_format(memo);
		memo = set_identified_type_conversion_specifier(memo, *format, target);
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

int	ft_printf(const char *format, ...)
{
	va_list			target;
	t_printf_format	*memo;

	va_start(target, format);
	for (const char *p = format; *p != '\0'; p++)
	{
		if (*p == "%")
		{
			p++;
			if (p == "%")
			{
				write(1, "%", 1);
			}
			else
			{
				memo = set_minus_precision_value(p, target);
				memo = set_zero_flag(memo, p);
				memo = set_field_width(memo, p);
				print_target(memo);
				p = p + from_percent_to_conversion_specifier_len(p);
			}
		}
		else
		{
			write(1, p, 1);
		}
	}
	va_end(target);
	return (0);
}
