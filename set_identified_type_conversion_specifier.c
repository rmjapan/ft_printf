/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_identified_type_conversion_specifier.c         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiyauch <rmiyauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:50:08 by rmiyauch          #+#    #+#             */
/*   Updated: 2024/02/10 12:50:18 by rmiyauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/miyauchiryuuichi/Downloads/42tokyo/ft_printf/include/ft_printf.h"

unsigned int	identify_conversion_specifier_type(char c) //変換指定子の型を識別する
{
	if (c == 'c')
		return (1);
	else if (c == 's')
		return (2);
	else if (c == 'p')
		return (3);
	else if (c == 'd')
		return (4);
	else if (c == 'i')
		return (5);
	else if (c == 'u')
		return (6);
	else if (c == 'x')
		return (7);
	else if (c == 'X')
		return (8);
	else
		return (0);
}

void	set_conversion_specifier_type(t_printf_format *t_printf_format,
		unsigned int conversion_specifier_type, va_list target)
{
	t_printf_format->type = conversion_specifier_type;
}

void	set_conversion_specifier_value(t_printf_format *t_printf_format,
		va_list target)
{
	if (t_printf_format->type == 1)
		t_printf_format->c = va_arg(target, char);
	else if (t_printf_format->type == 2)
		t_printf_format->s = va_arg(target, char *);
	else if (t_printf_format->type == 3)
		t_printf_format->p = va_arg(target, unsigned int);
	else if (t_printf_format->type == 4)
		t_printf_format->d = va_arg(target, int);
	else if (t_printf_format->type == 5)
		t_printf_format->i = va_arg(target, int);
	else if (t_printf_format->type == 6)
		t_printf_format->u = va_arg(target, unsigned int);
	else if (t_printf_format->type == 7)
		t_printf_format->x = va_arg(target, unsigned int);
	else if (t_printf_format->type == 8)
		t_printf_format->X = va_arg(target, unsigned int);
}

t_printf_format	*set_identified_type_conversion_specifier(t_printf_format *t_printf_format,
		char format, va_list target)
{
	unsigned int conversion_specifier_type = 0;
	conversion_specifier_type = identify_conversion_specifier_type(format);
	set_conversion_specifier_type(t_printf_format,
		conversion_specifier_type, target);
	set_conversion_specifier_value(t_printf_format, target);
	return (t_printf_format);
}